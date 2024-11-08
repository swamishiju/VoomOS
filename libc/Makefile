DESTDIR?=
INCLUDEDIR?=/usr/include
LIBDIR?=/usr/lib

SRC:=$(wildcard ./**/*.c)

OBJ:=$(SRC:.c=.o)
LIBK_OBJS:=$(OBJ:.o=.libk.o)	
LIBKD_OBJS:=$(OBJ:.o=.libk.d)

CFLAGS:=$(CFLAGS) -fstack-protector

install-headers:
	mkdir -p $(DESTDIR)$(INCLUDEDIR)	
	cp -R --preserve=timestamps include/. $(DESTDIR)$(INCLUDEDIR)/.

install-lib: libk.a
	mkdir -p $(DESTDIR)$(LIBDIR)
	cp $< $(DESTDIR)$(LIBDIR)/libk.a 

libk.a: $(LIBK_OBJS)
	$(AR) rcs $@ $(LIBK_OBJS)

%.o: %.c
	$(CC) -std=gnu11 -c $< -o $@ $(CFLAGS)

%.libk.o: %.c
	$(CC) -MD -c $< -o $@ -std=gnu11 $(CFLAGS)

%.libk.o: %.s
	$(CC) -MD -c $< -o $@ $(CFLAGS)

clean:
	rm -rf libk.a $(OBJ) $(LIBKD_OBJS) $(LIBK_OBJS)
