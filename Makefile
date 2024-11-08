SYSROOT:=$(shell pwd)/sysroot
PROJECTS:=libc kernel

export arch:=i686-elf
export CC:=$(arch)-gcc --sysroot=$(SYSROOT) -isystem=/usr/include
export AS:=$(arch)-as
export AR:=$(arch)-ar

WARNINGS := -Wall -Wextra -pedantic -Wshadow -Wpointer-arith -Wcast-align \
            -Wwrite-strings -Wmissing-prototypes -Wmissing-declarations \
            -Wredundant-decls -Wnested-externs -Winline -Wno-long-long \
            -Wconversion -Wstrict-prototypes
export CFLAGS := -g -O2 $(WARNINGS) -ffreestanding


define GRUB_CFG
menuentry "VoomOS" {
	multiboot /boot/myos.kernel
}
endef
export GRUB_CFG

iso: libs
	mkdir -p isodir/boot/grub
	cp $(SYSROOT)/boot/myos.kernel isodir/boot/myos.kernel
	@echo "$$GRUB_CFG" > isodir/boot/grub/grub.cfg
	grub-mkrescue -o VoomOS.iso isodir

headers:
	$(foreach proj,$(PROJECTS),cd $(proj) && DESTDIR="$(SYSROOT)" make install-headers ${\n})

libs: headers
	$(foreach proj,$(PROJECTS),cd $(proj) && DESTDIR="$(SYSROOT)" make install-lib ${\n})

clean:
	$(foreach proj,$(PROJECTS),cd $(proj) && DESTDIR="$(SYSROOT)" make clean ${\n})
	rm -rf sysroot isodir


qemu:
	qemu-system-i386 -cdrom VoomOS.iso

define \n 


endef

