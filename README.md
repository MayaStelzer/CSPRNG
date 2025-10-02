# CSPRNGs for Python, Golang, C++, and Rust

Examples and documentation for CSPRNG libraries


## Python
To run: 
```bash
python3 example.py
```
Documentation: [here](https://docs.python.org/3/library/secrets.html)

Notes:

- built-in Python library
- generates cryptographically strong random numbers that can be used for passwords, account authentication, security tokens, and related secrets


## Golang
To run: 
```bash
go run example.go
```
Documentation: [here](https://pkg.go.dev/crypto/rand#section-documentation)

Notes:

- built-in Go library
- implements cryptographically secure random number generator

## C++
Dependencies: Make sure openSSL is installed

To run:
```bash
g++ example.cpp -o example
./example
```
Documentation: [here](https://docs.openssl.org/3.1/man3/RAND_bytes/)

Notes:

- OpenSSL is an open-source cryptography toolkit
- RAND_bytes() function in OpenSSL generates cryptographically secure pseudo-random bytes

## Rust
To run: 
```bash
cargo run  
```

Documentation: [RngCore](https://docs.rs/rand/latest/rand/trait.RngCore.html) and
[OsRng](https://docs.rs/rand/latest/rand/rngs/struct.OsRng.html)

Notes:

- OsRng implements a cryptographically secure random number generator
