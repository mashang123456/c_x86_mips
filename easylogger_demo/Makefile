#export LD_LIBRARY_PATH=./lib/x86/:$LD_LIBRARY_PATH
ifeq ("$(PLATFORM)","X86") #X86平台编译器
    GCC = gcc
    CFLAGS  += -I/usr/local/include/ 
	CFLAGS  += -I./inc/
	LDFLAGS += -L/usr/local/lib/ -lpthread
	LDFLAGS += -L./lib/x86/ -leasylogger
	LDFLAGS += -D X86 #参数传入src文件
endif

ifeq ("$(PLATFORM)","MIPS") #OpenWrt平台编译器
    GCC = /home/xiaomi/OpenWrt-Toolchain-ramips-for-mipsel_24kec+dsp-gcc-4.8-linaro_uClibc-0.9.33.2/toolchain-mipsel_24kec+dsp_gcc-4.8-linaro_uClibc-0.9.33.2/bin/mipsel-openwrt-linux-gcc
	CFLAGS += -I/home/openwrt/mosquitto/include/
	CFLAGS  += -I./inc/
	LDFLAGS+= -L/home/openwrt/mosquitto/lib/ -lpthread -ldl
	LDFLAGS += -L./lib/mips/ -leasylogger
	LDFLAGS += -D MIPS #参数传入src文件
endif

OUTPUT=easylogger_demo

all: $(OUTPUT) 

#libeasylogger.so
SRC_NAME += main.c

$(OUTPUT): $(SRC_NAME)
	$(GCC) -o $(OUTPUT) $(SRC_NAME) $(CFLAGS) $(LDFLAGS)

.PHONY: clean
clean:
	rm -rf $(OUTPUT) *.o
	

	
