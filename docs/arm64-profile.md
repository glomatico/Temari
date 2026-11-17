# Apple Music build 1109 ARM64 profile

This fork provides a separate, pure Rust backend for contexts captured from
Apple Music 3.6.0-beta build 1109, `arm64-v8a`. It does not load Apple libraries
or execute ARM machine code. The backend works on either supported Linux host
architecture; the profile describes the source APK, not the client CPU.

The flat JSON contract is:

```json
{"profile":"apple-music-3.6.0.1109-arm64-v8a-research-v1","ctx":"<base64>","state":"<base64>"}
```

`ctx` decodes to exactly 9,504 bytes; `state` decodes to exactly 2,304 bytes.
Native pointers are normalized to the checked virtual regions defined in
`src/arm64.rs`. Unknown profiles, wrong sizes, and invalid pointer/dispatch
fields are rejected. No register fields from the x86 profile are reused.
Each sample resets the state, preserves any trailing incomplete block, and
supports the existing sequential, parallel, and streaming APIs.

The native exporter must pin CoreLSKD SHA-256
`36e49510c1c3b0c133b263cfc6996f79cda112320b51d5f9dbaa1175cab6d8d9`
and verify its hook signature. The validated block spans ELF offsets
`0x105928..0x109d74`; only x21 and sparse stack state are live at entry.
The backend represents that block as Rust integer operations and checked
reads/writes. All shifts, truncations, extensions, and wrapping arithmetic
were checked against an independent Unicorn replay.

Validation on 2026-11-17 used isolated QEMU workers with copied sessions,
without modifying production. 120 comparisons included 40 real AAC/ALAC
samples across two tracks and repeated context acquisition, deterministic
inputs and non-aligned tails. Full ARM64 native decryption, Unicorn replay,
the Rust backend, and the existing x86 backend agreed. Integrated Temari
also passed sequential, parallel, reversed-order, and streaming comparisons.
No native ARM64 hardware was available. These authenticated tests and all
private inputs remain outside Git.

Public tests construct entirely fabricated tables and state. Their expected
results come from independent emulation; no account data, captured context,
native libraries, or decrypted media are included.

Like the existing legacy backend, malformed semantic state that passes the
initial format checks may panic during decryption; virtual memory remains
bounds checked and cannot access host addresses. The FFI catches panics.
