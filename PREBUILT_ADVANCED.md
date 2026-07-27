# Prebuilt branch: `ap-dev-advanced`

This branch is a **scaffold** for the advanced Rivian AdventurePilot build. It does not yet contain compiled Comma 4 binaries. A real prebuilt branch must be captured **on the device**, because the compiled artifacts are aarch64 binaries built by the Comma 4's own SoC — they cannot be produced correctly on an x86_64 build machine.

This branch combines:
- Latest sunnypilot/master nightly sync (70f2c3ac7, July 2026)
- Advanced Rivian angle steering from `do-not-use-a-src` branch
- All Rivian MADS lateral control improvements
- Angle/torque-primary steering toggle for comma 3/3X + comma 4
- Cooperative steering, torque envelope fixes, engage-revoke race fixes

## How a prebuilt branch works

openpilot (and AdventurePilot/sunnypilot) skip the on-device `scons` compile when a marker file named `prebuilt` exists at the repo root. The release pipeline (`release/build_release.sh`) compiles everything, then `touch prebuilt`, then commits the *compiled* tree. A device installing a branch with `prebuilt` present boots fast (no multi-minute first-boot compile).

## Steps (run on the Comma 4)

1. Install the **source** branch first: on the Comma 4 setup screen, use custom software URL `https://github.com/SurferSD/AdventurePilot` and select branch `ap-dev-advanced`. Let the first boot finish — this compiles openpilot on-device.
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
   The script verifies it is on aarch64, that the build completed (compiled `.so` present), flattens submodules so the branch is self-contained, force-adds the compiled tree, adds the `prebuilt` marker, and force-pushes to `ap-dev-advanced` on this fork.

## Install from the prebuilt branch (future devices / reinstalls)

Custom software URL: `https://github.com/SurferSD/AdventurePilot`
Branch: `ap-dev-advanced`

The `prebuilt` marker makes the device skip compilation → fast boot. Model weights are still fetched by the installer at install time (they are intentionally NOT committed to this branch).

## Key Rivian Features in This Branch

### Angle Steering (Hardware: Angle Harness Required)
- **Angle/torque-primary toggle**: Switch between angle-controlled and torque-controlled steering via UI or Sunnylink
- **On-screen wheel-tap toggle**: Hold wheel tap to cycle steering mode (comma 3/3X + comma 4)
- **Cooperative steering**: Always-on for angle mode, matches xnor behavior
- **Steering-limit warning**: Restored for angle mode

### MADS Lateral Control
- Fixed engage-revoke race that faulted Rivian EPAS
- Fixed Params type crash writing MadsMinEngageSpeed (str → int)
- Minimum MADS engage speed setting
- Full MADS disengage on reverse gear entry
- Torque envelope + blip handling matching dev/software tune

### Longitudinal Improvements
- `longitudinalActuatorDelay` 0.2 → 0.3 (matches measured plant lag)
- Feedforward accel offset to cancel VDM's decel drag
- Dropped longitudinal kp (eliminates low-speed stutter)

### UI/UX
- Lateral mode indicator (angle/torque) on screen
- Rivian-specific steering settings panel
- Angle harness detection (RivianFlags.ANGLE_HARNESS)
- Torque bar shows lateral accel for angle-capable hardware

## Notes / Caveats

- The first (source) install still compiles. The prebuilt branch only helps on *subsequent* installs/reflashes.
- `capture_prebuilt.sh` force-pushes to `ap-dev-advanced`, intentionally overwriting this scaffold.
- If the device clone is shallow, the pushed branch clones back shallow — that is fine for installation.
- **Angle steering requires the angle harness** (RivianFlags.ANGLE_HARNESS). Torque-primary mode works on stock harness.
- This is alpha research software. You are responsible for safe use and compliance.
