#!/usr/bin/env bash
# capture_prebuilt.sh — run ON the Comma 4 after a successful source install.
#
# Commits the compiled (aarch64) tree with a `prebuilt` marker and force-pushes to
# ap-dev-prebuilt on the SurferSD/AdventurePilot fork, producing a branch that skips
# the on-device compile on future installs (fast boot).
#
# Includes an idempotent post-push safety check: after pushing, it re-fetches the
# remote branch and verifies the `prebuilt` marker and the compiled artifacts are
# actually present server-side (not just in the local working tree) before declaring
# success. The check is read-only, so re-running the script is safe.
#
# Usage:
#   cd /data/openpilot
#   bash release/capture_prebuilt.sh
#
# Env overrides:
#   REMOTE_URL  push target  (default git@github.com:SurferSD/AdventurePilot.git)
#   BRANCH      push branch   (default ap-dev-prebuilt)
#   OPENPILOT_DIR working dir (default /data/openpilot)

set -euo pipefail

BRANCH="${BRANCH:-ap-dev-prebuilt}"
REMOTE_URL="${REMOTE_URL:-git@github.com:SurferSD/AdventurePilot.git}"
OPENPILOT_DIR="${OPENPILOT_DIR:-/data/openpilot}"

cd "$OPENPILOT_DIR"

echo "[*] arch check"
ARCH="$(uname -m)"
if [ "$ARCH" != "aarch64" ]; then
  echo "ERROR: not running on aarch64 (got $ARCH). Run this on the Comma device." >&2
  exit 1
fi

echo "[*] build-complete check"
if ! find selfdrive -name '*.so' 2>/dev/null | grep -q .; then
  echo "ERROR: no compiled .so found under selfdrive — openpilot has not been built." >&2
  echo "       Install the source branch (ap-dev) and let the first boot finish." >&2
  exit 1
fi

if ! pgrep -f "selfdrive/manager.py" >/dev/null; then
  echo "WARN: manager.py not currently running. Assuming a successful prior build."
fi

echo "[*] current branch: $(git rev-parse --abbrev-ref HEAD 2>/dev/null || echo unknown)"

# --- Flatten submodules so the pushed branch is self-contained -------------------
# The installed tree has nested submodule repos (panda, msgq, rednose, tinygrad,
# opendbc...). A fresh clone would otherwise try to re-init them. Strip their .git
# linkage and commit their files as normal content.
echo "[*] flattening submodules"
rm -f .gitmodules
for g in $(find . -name '.git' -maxdepth 3 2>/dev/null); do
  [ "$g" = "./.git" ] && continue
  rm -rf "$g"
done

# --- Drop intermediate build artifacts, keep what is needed to run ---------------
echo "[*] trimming intermediates"
find . -name '*.a' -delete 2>/dev/null || true
find . -name '*.o' -delete 2>/dev/null || true
find . -name '*.os' -delete 2>/dev/null || true
find . -name '*.pyc' -delete 2>/dev/null || true
find . -name 'moc_*' -delete 2>/dev/null || true
find . -name '__pycache__' -type d -exec rm -rf {} + 2>/dev/null || true
rm -rf .sconsign.dblite Jenkinsfile release/ 2>/dev/null || true
# Comma 4 is aarch64; drop x86/Darwin third_party dead weight
find third_party/ -name '*x86*' -exec rm -rf {} + 2>/dev/null || true
find third_party/ -name '*Darwin*' -exec rm -rf {} + 2>/dev/null || true
# Model weights are fetched by the installer at install time; don't bloat the branch.
rm -f selfdrive/modeld/models/*.onnx sunnypilot/modeld*/models/*.onnx 2>/dev/null || true

# --- Mark as prebuilt ------------------------------------------------------------
echo "[*] creating prebuilt marker"
touch prebuilt

# --- Configure remote + identity for push ----------------------------------------
echo "[*] configuring remote for push"
git remote remove origin 2>/dev/null || true
git remote add origin "$REMOTE_URL"
git config user.email "${GIT_EMAIL:-prebuilt@adventurepilot.local}" 2>/dev/null || true
git config user.name "${GIT_NAME:-AdventurePilot Prebuilt Bot}" 2>/dev/null || true

# --- Commit the compiled tree ----------------------------------------------------
echo "[*] staging compiled tree"
git add -f .

if git diff --cached --quiet; then
  echo "WARN: nothing staged — tree already captured? Still ensuring prebuilt marker."
fi

git commit -m "prebuilt: capture compiled Comma 4 tree for fast boot (ap-dev)" \
  || echo "WARN: commit had nothing new to add."

# --- Push ------------------------------------------------------------------------
echo "[*] pushing to $BRANCH"
git push -f origin "HEAD:$BRANCH"

# --- Idempotent safety check: verify the REMOTE branch actually holds the
#     compiled artifacts before declaring success. Read-only; safe to re-run. ------
echo "[*] safety check: verifying remote branch '$BRANCH' contents"

git fetch -q origin "$BRANCH" || {
  echo "ERROR: push reported success but cannot fetch '$BRANCH' to verify contents." >&2
  exit 1
}

REMOTE_TREE="origin/$BRANCH"

# 1) prebuilt marker must be present in the remote tree
if ! git ls-tree -r "$REMOTE_TREE" --name-only | grep -qx "prebuilt"; then
  echo "ERROR: 'prebuilt' marker missing from remote branch '$BRANCH'." >&2
  echo "       Do NOT install from this branch — it would compile on-device." >&2
  exit 1
fi

# 2) count compiled artifacts: shared objects (.so, mode 100644) plus scons-built
#    executables (mode 100755) under selfdrive/ and system/.
SO_COUNT=$(git ls-tree -r "$REMOTE_TREE" | awk '$1=="100644" && $4 ~ /\.so$/ {c++} END{print c+0}')
EXEC_COUNT=$(git ls-tree -r "$REMOTE_TREE" | awk '$1=="100755" && $4 ~ /^(selfdrive|system)\// {c++} END{print c+0}')
TOTAL_COMPILED=$((SO_COUNT + EXEC_COUNT))

if [ "$TOTAL_COMPILED" -lt 5 ]; then
  echo "ERROR: remote branch '$BRANCH' holds only $TOTAL_COMPILED compiled artifacts (expected >=5)." >&2
  echo "       The push looks incomplete; do NOT install from this branch yet." >&2
  exit 1
fi

# 3) manager entrypoint / core binary sanity: require the Python manager launcher
#    and/or a known core executable to be present.
MANAGER_OK=0
if git ls-tree -r "$REMOTE_TREE" --name-only | grep -qx "selfdrive/manager.py"; then
  MANAGER_OK=1
fi
for bin in selfdrive/modeld/modeld selfdrive/camerad/camerad selfdrive/pandad/pandad system/manager/manager; do
  if git ls-tree -r "$REMOTE_TREE" --name-only | grep -qx "$bin"; then
    MANAGER_OK=1
    break
  fi
done
if [ "$MANAGER_OK" -ne 1 ]; then
  echo "WARN: no manager entrypoint/core binary detected in remote tree; boot behavior unverified."
fi

echo "[+] safety check passed: '$BRANCH' has prebuilt marker + $TOTAL_COMPILED compiled artifacts (so=$SO_COUNT, exec=$EXEC_COUNT)."
echo "[+] done. Future installs from branch '$BRANCH' will skip the on-device compile."
