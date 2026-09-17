ROOT=../..
ECFLAGS=-O -Wall -I. -I$(ROOT) -I$(ROOT)/ITRON -I$(ROOT)/ITRON/h -I$(ROOT)/ITRON/i386 -I$(ROOT)/POSIX/libc/others -DEOTA $(IDENT)
STARTADDR=0x00001000
ENTRY=_main
KERNLIBS=$(ROOT)/POSIX/libc/libc.a #$(ROOT)/ITRON/kernlib/libitron.a 

# Native host compiler — accepts HOST_CC from parent or falls back to cc
CC := $(if $(HOST_CC),$(HOST_CC),cc)
CFLAGS=-Wall

all: mksfs statfs sfsck

mksfs: mkfs.o
	$(CC) $(CFLAGS) -o mksfs mkfs.o

statfs: statfs.o
	$(CC) $(CFLAGS) -o statfs statfs.o

sfsck: sfsck.o
	$(CC) $(CFLAGS) -o sfsck sfsck.o

# Create a bootable 1.44M Floppy SFS image
fd-image: mksfs statfs
	@echo "==> Creating SFS Floppy boot image (1.44MB) ..."
	rm -f fd_boot.bin
	cp -f ../../../sfsboot/1st/1stboot fd_boot.bin
	./mksfs fd_boot.bin 2880 512 12
	./statfs fd_boot.bin mkdir /system
	./statfs fd_boot.bin write /system/2ndboot ../../../sfsboot/2nd/2ndboot
	./statfs fd_boot.bin write /system/btron386 ../../../kernel/BTRON/make/btron
	./statfs fd_boot.bin write /system/wconsole ../../POSIX/servers/wconsole/wconsole
	./statfs fd_boot.bin chmod 755 /system/wconsole
	./statfs fd_boot.bin write /system/ramdisk ../../POSIX/servers/ramdisk/ramdisk
	./statfs fd_boot.bin chmod 755 /system/ramdisk
	./statfs fd_boot.bin mkdir /dev
	./statfs fd_boot.bin mknod /dev/console 0x00000000
	./statfs fd_boot.bin mknod /dev/win1 0x00000001
	./statfs fd_boot.bin mknod /dev/win2 0x00000002
	./statfs fd_boot.bin mknod /dev/keyboard 0x00010000
	./statfs fd_boot.bin mknod /dev/psaux 0x00020000
	./statfs fd_boot.bin mknod /dev/fd 0x80000000
	./statfs fd_boot.bin mknod /dev/ide0 0x80010000
	./statfs fd_boot.bin mknod /dev/ide1 0x80010001
	./statfs fd_boot.bin mknod /dev/ide2 0x80010002
	./statfs fd_boot.bin mknod /dev/ide3 0x80010003
	./statfs fd_boot.bin mknod /dev/ide4 0x80010004
	./statfs fd_boot.bin mknod /dev/ide5 0x80010005
	./statfs fd_boot.bin mknod /dev/ide6 0x80010006
	./statfs fd_boot.bin mknod /dev/ide7 0x80010007
	./statfs fd_boot.bin mknod /dev/ide8 0x80010008
	./statfs fd_boot.bin mknod /dev/ide9 0x80010009
	./statfs fd_boot.bin mknod /dev/rd 0x80020000
	./statfs fd_boot.bin write /init.fm init.fm
	../../../sfsboot/mkmap fd_boot.bin /system/2ndboot | ../../../sfsboot/mkboot fd_boot.bin
	python3 -c "with open('fd_boot.bin', 'ab') as f: f.truncate(1474560)"
	@echo "==> fd_boot.bin created (1474560 bytes)."

# Create a bootable HDD SFS image (called by root Makefile 'make pc')
hd-image: mksfs statfs fd-image
	@echo "==> Creating SFS HDD boot image ..."
	rm -f hd_boot.bin
	cp -f ../../../sfsboot/1st/1stboot hd_boot.bin
	./mksfs hd_boot.bin 20480 512 12
	./statfs hd_boot.bin mkdir /system
	./statfs hd_boot.bin write /system/2ndboot ../../../sfsboot/2nd/2ndboot
	./statfs hd_boot.bin write /system/btron386 ../../../kernel/BTRON/make/btron
	./statfs hd_boot.bin write /system/wconsole ../../POSIX/servers/wconsole/wconsole
	./statfs hd_boot.bin chmod 755 /system/wconsole
	./statfs hd_boot.bin write /system/ramdisk ../../POSIX/servers/ramdisk/ramdisk
	./statfs hd_boot.bin chmod 755 /system/ramdisk
	./statfs hd_boot.bin mkdir /dev
	./statfs hd_boot.bin mknod /dev/console 0x00000000
	./statfs hd_boot.bin mknod /dev/win1 0x00000001
	./statfs hd_boot.bin mknod /dev/win2 0x00000002
	./statfs hd_boot.bin mknod /dev/keyboard 0x00010000
	./statfs hd_boot.bin mknod /dev/psaux 0x00020000
	./statfs hd_boot.bin mknod /dev/fd 0x80000000
	./statfs hd_boot.bin mknod /dev/ide0 0x80010000
	./statfs hd_boot.bin mknod /dev/ide1 0x80010001
	./statfs hd_boot.bin mknod /dev/ide2 0x80010002
	./statfs hd_boot.bin mknod /dev/ide3 0x80010003
	./statfs hd_boot.bin mknod /dev/ide4 0x80010004
	./statfs hd_boot.bin mknod /dev/ide5 0x80010005
	./statfs hd_boot.bin mknod /dev/ide6 0x80010006
	./statfs hd_boot.bin mknod /dev/ide7 0x80010007
	./statfs hd_boot.bin mknod /dev/ide8 0x80010008
	./statfs hd_boot.bin mknod /dev/ide9 0x80010009
	./statfs hd_boot.bin mknod /dev/rd 0x80020000
	./statfs hd_boot.bin write /init.fm init.fm
	@echo "==> hd_boot.bin created."

mksfs-e: mkfs.no $(NLIBS) $(NKERNLIBS)
	$(LD) -Bstatic -o $@ -e ${NENTRY} -Ttext=$(STARTADDR) mkfs.no $(NLIBS) $(NKERNLIBS) 
	strip $@

statfs-e: statfs.no $(NLIBS) $(NKERNLIBS)
	$(LD) -Bstatic -o $@ -e ${NENTRY} -Ttext=$(STARTADDR) statfs.no $(NLIBS) $(NKERNLIBS)
	strip $@

sfsck-e: sfsck.no $(NLIBS) $(NKERNLIBS)
	$(LD) -Bstatic -o $@ -e ${NENTRY} -Ttext=$(STARTADDR) sfsck.no $(NLIBS) $(NKERNLIBS) 
	strip $@

clean:
	rm -f statfs mksfs sfsck
	rm -f *.o *.eo *.no
	rm -f mksfs-e statfs-e
	rm -f *.img *.bin
	(cd ../app; ${MAKE} clean)
