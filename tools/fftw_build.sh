#!/bin/sh

NDK_DIR=/home/shidephen/android/sdk/ndk-bundle

ARCH=armv7-a
TOOLCHAIN_PREFIX=arm-linux-androideabi

INSTALL_DIR="`pwd`/$ARCH"
TOOLCHAIN_DIR="$NDK_DIR/toolchains/"$TOOLCHAIN_PREFIX"-4.9/prebuilt/linux-x86_64/bin"

#export PATH="$NDK_DIR/toolchains/"$TOOLCHAIN_PREFIX"-4.9/prebuilt/linux-x86_64/bin:$PATH"

export SYS_ROOT="$NDK_DIR/platforms/android-23/arch-arm"

export CC="$TOOLCHAIN_DIR"/"$TOOLCHAIN_PREFIX""-gcc"
export LD="$TOOLCHAIN_DIR"/"$TOOLCHAIN_PREFIX""-ld"
export AR="$TOOLCHAIN_DIR"/"$TOOLCHAIN_PREFIX""-ar"
export RANLIB="$TOOLCHAIN_DIR"/"$TOOLCHAIN_PREFIX""-ranlib"
export STRIP="$TOOLCHAIN_DIR"/"$TOOLCHAIN_PREFIX""-strip"
export CFLAGS="-march=$ARCH -mfpu=neon -mfloat-abi=softfp --sysroot=$SYS_ROOT"
#export LIBS="-lc -lgcc"
#export LDFLAGS="-L$SYSROOT/usr/lib"
#export CFLAGS="-march=$ARCH -mfpu=neon -mfloat-abi=softfp"

./configure --host=$TOOLCHAIN_PREFIX --prefix=$INSTALL_DIR \
    --enable-single --enable-neon \
    --enable-static \
    --with-sysroot=$SYS_ROOT
