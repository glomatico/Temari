# Pinned-APK legacy profile (experimental)

This fork extends upstream Temari with a **version-specific backend** for
Apple Music 3.6.0-beta, build 1109, x86-64.

The implementation was developed and validated in the local research folder
`/mnt/sda1/wrapper-v2-investigation`. The repository does **not** require
that folder, an Apple APK, or Apple's libraries to compile.

## Profiles and wire contract

Upstream's untagged context JSON continues through the original Rust engine.
Legacy JSON must include exactly this profile identifier:

```json
{
  "profile": "apple-music-3.6.0.1109-x86_64-research-v1",
  "ctx": "<base64, decoded size 0x8000>",
  "state": "<base64, decoded size 0x800>",
  "bl": 0,
  "r9b": 0
}
```

The JSON above is **only a format illustration**, not a usable real template.
The client verifies the profile, buffer sizes and byte-valued registers.
Unsupported explicit profiles are rejected rather than silently falling back.

The original x86-64 CoreLSKD used for the pinned capture work has SHA-256
`bf813206d382bd8b27384bd546a5b9aa730df32c8543d709756b081b619a8b3a`.
The exporter must verify the exact library build, as its hook addresses are
version-dependent. The client-side Rust crate does not load CoreLSKD.

## Implementation

- `src/legacy/legacy_backend.c` is the exact generated C round body from
  Astra's tested pinned-ELF lift. SHA-256:
  `8843942763c784a2727890dfc52791b7e041e3aa38b6f308bb02e5d25360d792`.
- `build.rs` uses Cargo's `cc` build dependency to compile it for the
  **target** architecture and link it into the Rust crate.
- `src/legacy.rs` provides the version-specific context validation, memory
  mapping and sample-boundary state resets. Its C interface receives only
  checked region pointers; the C transform bounds-checks virtual reads/writes
  and forbids writes to ciphertext/context regions.
- `src/template.rs` dispatches tagged legacy JSON to the legacy constructor.
  An untagged upstream template retains the original construction path.
- `src/rounds.rs` selects the corresponding backend for serial, parallel
  and streaming decryption. Gamdl uses the **native Rust API**:
  `temari::{template_from_json, decrypt, decrypt_par}`.

Python and Go bindings remain present in upstream's source tree for
compatibility but are **not distributed** as part of this fork's releases.
No PyPI or crates.io workflows are enabled. The Cargo crate has
`publish = false`; consumers pin a Git commit.

## Verification

The independent research prototype reported byte-for-byte matches against
the full native reference for **40 real AAC/ALAC samples**, plus 32 synthetic
samples, spanning two content-key URIs. See the research folder's
`reports/live-legacy-comparison.json` for the original validation record.
That authenticated comparison is **not** part of public CI.

The fork includes `tests/legacy_profile.rs` and
`tests/fixtures/legacy-v1109-synthetic.json`, containing an entirely
**fabricated** deterministic context and 16/64-byte ciphertext vectors.
The expected plaintext was recorded from running the original pinned
instructions in an isolated Unicorn emulator, independently of the compiled
C backend. These tests run offline on GitHub Actions with `cargo test --locked`
and do not require secrets, an account, a Wrapper service or any Apple library.
They also verify parallel operation, preservation of non-block tails, rejection
of unknown profiles, and retention of upstream template dispatch.

## Remaining work

- **ARM64 native capture** from the pinned APK needs independent research.
  Cross-compiling the client-side C engine is not proof of ARM64 capture.
- Review C/Rust boundary failure handling and security before accepting
  untrusted templates from arbitrary sources. Some internal contract
  violations currently panic rather than returning structured Rust errors.
- Benchmark performance against the original Temari engine and a native
  sample decryptor on representative sample sizes.
- Integrate the version-pinned context exporter into a new Wrapper-v2, and
  implement an end-to-end native Rust Gamdl integration.
- Review provenance and distribution obligations for the generated C source.

No live account data, DRM material, Apple binary blobs or decrypted media
are included in this repository.
