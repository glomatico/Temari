## Temari
Apple Music FairPlay Streaming decryption library

The project name comes from [Tsukimura Temari (月村手毬)](https://bangumi.tv/character/153576)

> [中文版 README](./README.zh.md)

> **glomatico fork:** This repository preserves upstream history and adds an
> architecture-specific backends for Apple Music **3.6.0-beta, build 1109**. The fork is
> distributed via **GitHub only**, not crates.io or PyPI. Gamdl uses its
> native Rust API.

### Native Rust integration (Gamdl)

Pin a reviewed commit of the GitHub fork:

```toml
[dependencies]
temari = { git = "https://github.com/glomatico/Temari.git", rev = "<commit-sha>" }
```

```rust
use temari::{decrypt, decrypt_par, template_from_json};

let template = template_from_json(&context_json)?;
let plaintext = decrypt(&template, &encrypted_sample);
let batch = decrypt_par(&template, &[encrypted_sample.as_slice()]);
```

The context JSON selects a backend:

| Context | Engine |
|---|---|
| Untagged upstream 40020-style JSON | Original upstream Rust rounds |
| `profile: apple-music-1109-x86_64` | Legacy C rounds, linked into Rust |
| `profile: apple-music-1109-arm64-v8a` | Pure Rust ARM64 context backend; no Apple native libraries at runtime |
| Unknown explicit profile | Rejected |

Both build-1109 backends require a matching, version-pinned context exporter.
The ARM64 exporter is implemented in the `tamari` branch of
[glomatico/wrapper-v2](https://github.com/glomatico/wrapper-v2) (the new Wrapper-v2
codebase); it exports architecture-specific state for Temari to decrypt locally.
The ARM64 profile describes **the APK architecture**, not the computer's CPU:
the pure Rust backend works on x86_64 hosts as well. No Apple native libraries
or APK files are downloaded during compilation.

**ARM64 status:** Validated under ARM64 QEMU against the pinned Apple Music
build, including 120 comparisons covering real AAC/ALAC samples, synthetic
samples, non-block-aligned tails, repeated context acquisition, and the x86_64
reference backend. Sequential, parallel and streaming decryption are tested.
The integrated Wrapper-v2 ARM64 exporter was also tested under QEMU. **Physical
ARM64 hardware has not yet been tested**, and this does not imply compatibility
with newer Apple Music builds or arbitrary APKs.

See the [x86_64 backend](docs/legacy-profile.md) and
[ARM64 backend](docs/arm64-profile.md) documentation. Public Rust tests use
fabricated contexts and independently emulated reference output.

### What is this
This library decrypts content protected by Apple Music's FairPlay Streaming DRM. Technically, it supports decrypting content encrypted via the `NfcRKVnxuKZy04KWbdFu71Ou` method.

It depends on the decryption-context data provided by [WorldObservationLog/wrapper](https://github.com/WorldObservationLog/wrapper).

### How to use
If you are not a developer, you probably do not need this library. You should look at [zhaarey/apple-music-downloader](https://github.com/zhaarey/apple-music-downloader) and [WorldObservationLog/AppleMusicDecrypt](https://github.com/WorldObservationLog/AppleMusicDecrypt).

### Upstream package registries (not this fork)

The original upstream project publishes these packages. **They do not include
the build-1109 backends from this fork.** They are documented here for historical
upstream compatibility:

| Registry | Package | Install |
|---|---|---|
| crates.io | `temari` | `cargo add temari` |
| PyPI | `temari` | `pip install temari` |
| Go | `github.com/WorldObservationLog/Temari/bindings/go` | `go get github.com/WorldObservationLog/Temari/bindings/go@v0.5.1` |

The Python and Go packages automatically select the bundled cdylib for the
current platform (Linux x86_64 / arm64, Windows x86_64 / arm64, macOS
x86_64 / arm64 — the macOS x86_64 and Windows arm64 libs are cross-compiled,
no Intel-Mac runner is used) — **no Rust
toolchain is needed on the target machine**. For Rust, add the crate as a
normal dependency:

```toml
[dependencies]
temari = "0.1"
```

**Un-precompiled platforms** (e.g. riscv64, ppc64le, FreeBSD): both the Python
wheel and the Go module ship the Rust source, so they can self-compile — the
Python package at install time (`pip install temari --no-binary :all:`) or on
first use; the Go module on first `LoadDefault()`. This needs a `cargo`
toolchain; without it, build the cdylib yourself (`cargo build --release`) and
point `TEMARI_LIB` / `Load()` at it.

> Building the cdylib by hand (`cargo build --release`) is only needed for the
> FFI / manual-loading path.

#### Rust
```rust
use temari::rounds;
use temari::template::template_from_json;

let tmpl = template_from_json(&json)?;
let plain = rounds::decrypt(&tmpl, &ct);
let plains = rounds::decrypt_par(&tmpl, &samples);
```

#### FFI
See also [`FFI.md`](./FFI.md)

```c
void*  tmpl_from_json(const char* json, size_t len);
void   tmpl_destroy(void* tmpl);
size_t decrypt_sample_ffi(const void* tmpl, const uint8_t* sample, size_t sample_len, uint8_t* out);
size_t decrypt_samples_par(const void* tmpl,
                           const uint8_t* const* ptrs,
                           const size_t* lens, size_t n,
                           uint8_t* out);
```

#### Python Binding
See also [`bindings/python`](./bindings/python/README.md)

```python
from temari import Temari

body = fetch_decrypt_context_json()
t = Temari.from_json(body)
plain = t.decrypt(ct)
plains = t.decrypt_par(samples)
t.close()
```

#### Golang Binding
See also [`bindings/go`](./bindings/go/README.md)

```go
import "temari"

lib, _ := temari.LoadDefault()   // bundled cdylib for the current platform
t, _ := lib.FromJSON(body)
plain, _ := t.Decrypt(sample)
plains, _ := t.DecryptPar(samples)
t.Close()
```

#### WebAssembly (browser)
See also [`bindings/wasm`](./bindings/wasm/README.md)

```js
import { loadTemari } from "temari.js";

const temari = await loadTemari("/temari.wasm");
const t = temari.Temari.fromJson(jsonBytes);   // caller fetches the JSON
const plain = t.decrypt(ctBytes);              // single sample (no threads in wasm)
t.close();
```

### Special Thanks
- An anonymous person provided the original Frida decryption program and the wrapper decryption program
- chocomint provided arm64 architecture support for the wrapper
- Deepseek, Claude Code, and Deepseek Harness did most of the reverse engineering and programming work

### License
MIT, see [`LICENSE`](./LICENSE).
