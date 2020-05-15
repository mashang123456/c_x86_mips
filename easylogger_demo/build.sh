#!/bin/sh
#./build.sh (默认X86) 1表示MIPS(./build.sh 1)
if [ ! $1 ];then
#ELF 64-bit LSB  executable, x86-64, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.24, BuildID[sha1]=316e05baf1ff2c80137637d8cdd15e176462d803, not stripped
    echo "PLATFORM=X86"
	make clean
	make PLATFORM=X86
else
#ELF 32-bit LSB  executable, MIPS, MIPS32 rel2 version 1, dynamically linked (uses shared libs), not stripped
export STAGING_DIR=/home/xiaomi/OpenWrt-Toolchain-ramips-for-mipsel_24kec+dsp-gcc-4.8-linaro_uClibc-0.9.33.2/toolchain-mipsel_24kec+dsp_gcc-4.8-linaro_uClibc-0.9.33.2/bin
	echo "PLATFORM=MIPS"
	make clean
	make PLATFORM=MIPS
fi
