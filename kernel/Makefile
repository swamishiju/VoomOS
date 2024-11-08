DESTDIR?=
INCLUDEDIR?=/usr/include
ARCHDIR?=arch/i386
BOOTDIR?=/boot

include $(ARCHDIR)/make.config

KERNEL_OBJS=\
$(KERNEL_ARCH_OBJS) \
kernel/kernel.o \


LIBS:= -nostdlib -lk -lgcc

OBJS=\
$(ARCHDIR)/crti.o \
$(ARCHDIR)/crtbegin.o \
$(KERNEL_OBJS) \
$(ARCHDIR)/crtend.o \
$(ARCHDIR)/crtn.o \

LINK_LIST=\
$(LDFLAGS) \
$(ARCHDIR)/crti.o \
$(ARCHDIR)/crtbegin.o \
$(KERNEL_OBJS) \
$(LIBS) \
$(ARCHDIR)/crtend.o \
$(ARCHDIR)/crtn.o \


myos.kernel: $(OBJS) $(ARCHDIR)/linker.ld
	$(CC) -T $(ARCHDIR)/linker.ld -o $@ $(CFLAGS) $(LINK_LIST)
	grub-file --is-x86-multiboot myos.kernel


install-headers:
	mkdir -p $(DESTDIR)$(INCLUDEDIR)	
	cp -R --preserve=timestamps include/. $(DESTDIR)$(INCLUDEDIR)/.

install-lib: myos.kernel
	mkdir -p $(DESTDIR)$(BOOTDIR)
	cp $< $(DESTDIR)$(BOOTDIR)/$<

$(ARCHDIR)/crtbegin.o $(ARCHDIR)/crtend.o:
	OBJ=`$(CC) $(CFLAGS) $(LDFLAGS) -print-file-name=$(@F)` && cp "$$OBJ" $@


.c.o:
	$(CC) -c $< -o $@ $(CFLAGS)	-std=gnu11

.s.o: 
	$(CC) -c $< -o $@ $(CFLAGS)	

clean:
	rm -rf $(OBJS) myos.kernel
