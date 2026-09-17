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
