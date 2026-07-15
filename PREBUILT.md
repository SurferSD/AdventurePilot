# Prebuilt branch: `ap-dev-prebuilt`

This branch is a **scaffold**. It does not yet contain compiled Comma 4 binaries.
A real prebuilt branch must be captured **on the device**, because the compiled
artifacts are aarch64 binaries built by the Comma 4's own SoC — they cannot be
produced correctly on an x86_64 build machine.

## How a prebuilt branch works

openpilot (and AdventurePilot/sunnypilot) skip the on-device `scons` compile when a
marker file named `prebuilt` exists at the repo root. The release pipeline
(`release/build_release.sh`) compiles everything, then `touch prebuilt`, then commits
the *compiled* tree. A device installing a branch with `prebuilt` present boots fast
(no multi-minute first-boot compile).

## Steps (run on the Comma 4)

1. Install the **source** branch first: on the Comma 4 setup screen, use custom
   software URL `https://github.com/SurferSD/AdventurePilot` and select branch
   `ap-dev`. Let the first boot finish — this compiles openpilot on-device.
2. SSH into the device (`ssh comma@<device-ip>`).
3. Make sure you can push to this fork:
   - The device has an SSH key at `/data/gitkey`. Get its public key:
     `ssh-keygen -y -P "" -f /data/gitkey`
   - Add that public key to your GitHub account (Settings → SSH and GPG keys), OR
     set `REMOTE_URL` to an `https://<token>@github.com/...` URL with a PAT.
4. Run the capture script:
   ```bash
   cd /data/openpilot
   bash release/capture_prebuilt.sh
   ```
   The script verifies it is on aarch64, that the build completed (compiled `.so`
   present), flattens submodules so the branch is self-contained, force-adds the
   compiled tree, adds the `prebuilt` marker, and force-pushes to `ap-dev-prebuilt`
   on this fork.

## Install from the prebuilt branch (future devices / reinstalls)

Custom software URL: `https://github.com/SurferSD/AdventurePilot`
Branch: `ap-dev-prebuilt`

The `prebuilt` marker makes the device skip compilation → fast boot. Model weights are
still fetched by the installer at install time (they are intentionally NOT committed to
this branch).

## Notes / caveats

- The first (source) install still compiles. The prebuilt branch only helps on
  *subsequent* installs/reflashes.
- `capture_prebuilt.sh` force-pushes to `ap-dev-prebuilt`, intentionally overwriting
  this scaffold.
- If the device clone is shallow, the pushed branch clones back shallow — that is fine
  for installation.
- This is alpha research software. You are responsible for safe use and compliance.
