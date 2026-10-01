#!/bin/sh
# Fetch the build toolchain into .toolchain/ (no root needed):
#   MIPS binutils (Fedora RPM, unpacked locally), wibo (Win32 loader),
#   and Metrowerks CodeWarrior for PS2 3.0.1 build 151 (as hosted for decomp.me).
set -e
cd "$(dirname "$0")/.."
mkdir -p .toolchain/mwcps2
cd .toolchain

if [ ! -x usr/bin/mips64-linux-gnu-as ]; then
    dnf download binutils-mips64-linux-gnu
    rpm2cpio binutils-mips64-linux-gnu-*.rpm | cpio -idm
fi

if [ ! -x wibo ]; then
    curl -fL -o wibo https://github.com/decompals/wibo/releases/download/1.2.0/wibo-x86_64
    chmod +x wibo
fi

for v in 3.0.1b151-050317 3.0.1b145-050209; do
    if [ ! -f "mwcps2/$v/mwccps2.exe" ]; then
        mkdir -p "mwcps2/$v"
        curl -fL "https://github.com/decompme/compilers/releases/download/compilers/mwcps2-$v.tar.gz" | tar xz -C "mwcps2/$v"
    fi
done
echo "toolchain ready"
