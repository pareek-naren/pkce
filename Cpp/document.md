## Overview

This project provides a Proof Key for Code Exchange (PKCE) generator in C++, fully compliant with RFC 7636.
It helps create secure code verifiers and code challenges for OAuth 2.0 and OpenID Connect authorization flows.

## Usage
# Build Instructions
# Linux / macOS
Ensure OpenSSL development headers are installed:
```bash
    sudo apt install libssl-dev      # Debian/Ubuntu
# or
brew install openssl             # macOS
```
Then compile:

```bash
g++ -std=c++17 main.cpp PkceGenerator.cpp -lcrypto -o pkce
```
Run:

```bash
./pkce
```


# Windows (with vcpkg or prebuilt OpenSSL)

Install [Openssl](https://slproweb.com/products/Win32OpenSSL.html) or via [vcpkg](https://github.com/microsoft/vcpkg):

```bash
vcpkg install openssl
```

Compile:

```bash
g++ -std=c++17 main.cpp PkceGenerator.cpp -I"path_to_openssl_include" -L"path_to_openssl_lib" -lcrypto -o pkce.exe
```

Run:

```bash
pkce.exe
```