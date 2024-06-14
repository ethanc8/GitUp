# Building GitUp on Debian/Ubuntu derivatives

## Installation of GNUstep

```bash
wget https://apt.llvm.org/llvm.sh
chmod +x llvm.sh
sudo ./llvm.sh 18
sudo apt install clang-18 clangd-18

export KERNEL=`uname -s | sed "s/\-.*//g" | awk '{print(tolower($0))}'`
echo "Begin setup for ${KERNEL}"

export USER=`whoami`
curl -fsSL > ./setup-${KERNEL} https://raw.githubusercontent.com/gnustep/tools-scripts/master/setup-${KERNEL}
. ./setup-${KERNEL}
rm ./setup-${KERNEL}

mkdir -p gnustep
cd gnustep
git clone https://github.com/gnustep/tools-scripts
./tools-scripts/clone-essential-repos-https

./tools-scripts/install-dependencies-${KERNEL}

./tools-scripts/clang-build clang-18 clang++-18

./tools-scripts/post-install-${KERNEL}

echo "Done..."
```

## Installing additional GNUstep libraries

### MiscHeaders

```bash
git clone https://github.com/ethanc8/MiscHeaders
cd MiscHeaders
./install.sh
cd ..
```

### CoreFoundation

```bash
git clone https://github.com/ethanc8/CoreFoundation
cd CoreFoundation/CoreFoundation
make && sudo -E make install
cd ../..
```

### Boron (CarbonCore)

We need to use the `testing-segfault` branch to avoid a segfault in libobjc2.

```bash
git clone https://github.com/ethanc8/libs-boron --branch testing-segfault
cd libs-boron
make && sudo -E make install
cd ..
```

### Opal (CoreGraphics/Quartz2D)

We need to use the `testing-segfault` branch to avoid a segfault in libobjc2.

```bash
sudo apt install liblcms2-dev libcairo2-dev libjpeg8-dev libpng-dev libtiff5-dev
git clone https://github.com/ethanc8/libs-opal --branch testing-segfault
cd libs-opal
make && sudo -E make install
cd ..
```

### QuartzCore (CoreAnimation)

You can also use `gnustep/libs-quartzcore`; my fork only changes the `.gitignore` file.

```bash
git clone https://github.com/ethanc8/libs-quartzcore
cd libs-quartzcore
make && sudo -E make install
cd ..
```

### XCTest

XCTest allows running the testsuite.

```bash
git clone https://github.com/gnustep/tools-xctest.git
cd tools-xctest
make && sudo -E make install
cd ..
```

### EJCAsset and AssetCompiler

AssetCompiler compiles asset catalogs into formats that libEJCAsset can read. libEJCAsset provides categories on top of various Foundation and AppKit classes that allow reading the compiled asset catalogs with the same APIs as provided on macOS for reading asset catalogs.

```bash
git clone https://github.com/ethanc8/DeveloperTools
cd DeveloperTools/AssetCompiler
make && sudo -E make install
cd ../EJCAsset
make && sudo -E make install
cd ../..
```

## Other dependencies

### libgit2

```bash
sudo apt install openssl libssl-dev libssh2-1 libssh2-1-dev libmbedtls-dev libpcre2-dev zlib1g-dev python3
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

### libsqlite3

```bash
cd Third-Party
./rebuild-libsqlite3-linux.sh
cd ..
```

## Building GitUpKit

```bash
make && sudo -E make install
```

## Building the example apps

The example apps are described in [the README](../README.md). The example apps can be found in [../Examples/](../Examples/) and can be built using `make && sudo -E make install`.
