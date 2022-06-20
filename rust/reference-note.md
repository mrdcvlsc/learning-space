# Rust Programming Language

**Install** - Download or install rust from the official website

**Update** - update rust to the latest version
```
rustup update
```

**Documentation** - access the rust documentation
```
rustup docs
rustup docs --book
```

**Basic Rust Program Structure**
```rust
fn main() {
    println!("Hello, world!");
}
```

**Compiling** - compile rust sources with the rust compiler
```
rustc main.rs
```

**Cargo** - rust's package manager, use to handel packages (libraries)

**Initializing a project with Cargo**
```
cargo new project-name
```

**Cargo Build (debug)** Building/Compiling cargo projects (default no optimizations)
```
cargo build
```

**Cargo Build (release)** - compile sources with optimizations
```
cargo build --release
```

**Cargo's executable output**
```
./target/debug/hello-cargo
```

**Cargo Run** - Running cargo executable build using cargo itself
```
cargo run
```

**Cargo Check** - check if the rust source codes in the cargo project will compile properly
```
cargo check
```
