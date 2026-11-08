obj-m := hello.o

# 可按需覆盖：for 编译验证可保持默认；交叉编译针对 VM/板再设 ARCH/CROSS_COMPILE
KDIR ?= /lib/modules/$(shell uname -r)/build
ARCH ?=
CROSS_COMPILE ?=

all:
	$(MAKE) -C $(KDIR) M=$(PWD) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean

