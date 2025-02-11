# Building and Installing on GNUstep

## Dependencies

### Debian and Ubuntu

```bash
```

### Other ones (not in package manager)

* [MiscHeaders](https://github.com/ethanc8/MiscHeaders)
* A GNUstep which uses libobjc2 and libdispatch
  * [libobjc2 (GNUstep Next-Generation Objective-C 2.0 Runtime)](https://github.com/gnustep/libobjc2)
  * [GNUstep Makefiles Library](https://github.com/gnustep/tools-make)
  * [GNUstep-base (Foundation Kit)](https://github.com/gnustep/libs-base)
  * [XCTest](https://github.com/gnustep/tools-xctest.git)
* A CoreFoundation which provides bridging to Foundation
  * [Catalina-CoreFoundation with bridging](https://github.com/ethanc8/swift-corelibs-foundation)

#### Dependencies for graphical components

* [GNUstep-gui (AppKit)](https://github.com/gnustep/libs-base)
* [Opal - Core Graphics](https://github.com/gnustep/libs-opal)
* [QuartzCore - Core Animation](https://github.com/gnustep/libs-quartzcore)

Opal's dependencies:

```bash
sudo apt install liblcms2-dev libcairo2-dev libjpeg8-dev libpng-dev libtiff5-dev
```

### libgit2

#### Dependencies - Debian and Ubuntu

```bash
sudo apt install openssl libssl-dev libssh2-1 libssh2-1-dev libmbedtls-dev libpcre2-dev zlib1g-dev python3
```

#### Dependencies - Other distros

While the library (libgit2) provides git functionality without the need for dependencies, it can make use of a few libraries to add to it:

* pthreads (non-Windows) to enable threadsafe access as well as multi-threaded pack generation
* OpenSSL (non-Windows) to talk over HTTPS and provide the SHA-1 functions
* LibSSH2 to enable the SSH transport
* iconv (OSX) to handle the HFS+ path encoding peculiarities

Additionally, it seems to check for the following libraries:

* mbedTLS, mbed X509, mbed Crypto
* http-parser version 2 (bundled)
* libpcre
* zlib
* heimdal-gssapi
* python3

#### Building libgit2

Please find-and-replace `C_STANDARD 90` to `C_STANDARD 17` before building.

```bash
cd GitUpKit/Third-Party/libgit2
rm -r build; \
    cmake -B build/ \
    -DUSE_SSH=1 \
    -DLIBGIT2_FILENAME=GitUpKitGit2 \
    -DCMAKE_INSTALL_BINDIR=$(gnustep-config --variable=GNUSTEP_LOCAL_TOOLS) \
    -DCMAKE_INSTALL_LIBDIR=$(gnustep-config --variable=GNUSTEP_LOCAL_LIBRARIES) \
    -DCMAKE_INSTALL_INCLUDEDIR=$(gnustep-config --variable=GNUSTEP_LOCAL_HEADERS)/GitUpKitGit2 \
    && cmake --build build/ \
    && sudo -E cmake --install build/
```

A bit faster:

```bash
cd GitUpKit/Third-Party/libgit2
rm -r build; \
    cmake -B build/ \
    -DUSE_SSH=1 \
    -DLIBGIT2_FILENAME=GitUpKitGit2 \
    -DCMAKE_INSTALL_BINDIR=$(gnustep-config --variable=GNUSTEP_LOCAL_TOOLS) \
    -DCMAKE_INSTALL_LIBDIR=$(gnustep-config --variable=GNUSTEP_LOCAL_LIBRARIES) \
    -DCMAKE_INSTALL_INCLUDEDIR=$(gnustep-config --variable=GNUSTEP_LOCAL_HEADERS)/GitUpKitGit2 \
    -G Ninja \
    && cmake --build build/ \
    && sudo -E cmake --install build/
```

### libsqlite3

Run `Third-Party/rebuild-libsqlite3-linux.sh`
