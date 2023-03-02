#!/bin/bash
set -ex -o pipefail

VERSION="3220000"
DIRNAME="$(pwd)"

# . ./common-linux.sh

# function build_arch_library() {
#   local PLATFORM="$1"
#   local ARCH="$2"
#   local PREFIX="$3"

#   if [[ "$ARCH" == "x86_64" ]]; then
#     HOST="x86_64-apple-darwin"
#   elif [[ "$ARCH" == "arm64" ]]; then
#     HOST="arm-apple-darwin"
#   else
#     exit 1
#   fi

#   configure_environment "$PLATFORM" "$ARCH"

#   ./configure --prefix="$PREFIX" --host="$HOST" --disable-shared --disable-dynamic-extensions
#   make install-includeHEADERS
#   make install-libLTLIBRARIES
#   make clean
# }

# Setup
mkdir -p "build"
cd "build"
if [[ ! -f "sqlite-autoconf-$VERSION.tar.gz" ]]; then
  curl -sfLO "https://www.sqlite.org/2018/sqlite-autoconf-$VERSION.tar.gz"
fi
rm -rf "sqlite-autoconf-$VERSION"
tar -xvf "sqlite-autoconf-$VERSION.tar.gz"

# Patch
cd "sqlite-autoconf-$VERSION"
perl -pi -e "s/SQLITE_THREADSAFE=1/SQLITE_THREADSAFE=2/g" "configure"  # Patch configure so that SQLITE_THREADSAFE=2 instead of SQLITE_THREADSAFE=1

# Build
EXTRA_CFLAGS="-DSQLITE_ENABLE_FTS3 -DSQLITE_ENABLE_FTS3_PARENTHESIS -fPIC"
# build_libraries "$DIRNAME" "libsqlite3"

export CFLAGS=$EXTRA_CFLAGS

./configure --disable-shared --disable-dynamic-extensions \
  --prefix="$(gnustep-config --variable=GNUSTEP_LOCAL_LIBRARY)/GitUpKitSqlite3" \
  --bindir="$(gnustep-config --variable=GNUSTEP_LOCAL_TOOLS)" \
  --libdir="$(gnustep-config --variable=GNUSTEP_LOCAL_LIBRARIES)/GitUpKitSqlite3" \
  --includedir="$(gnustep-config --variable=GNUSTEP_LOCAL_HEADERS)/GitUpKitSqlite3" \
  --program-prefix=GitUpKit

make
sudo -E make install-includeHEADERS
sudo -E make install-libLTLIBRARIES
make clean
