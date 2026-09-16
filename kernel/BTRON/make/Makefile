
# Updated: HOST_CC builds native host tools; X86_CC/X86_LD cross-compile the kernel.
# Accepts HOST_CC, X86_CC, X86_LD, PLATFORM from parent (Rules.mk).

#DEBUG=-DDEBUG

INC=../../ITRON/h
BUILDSRC=build.c $(INC)/itron_module.h
CFLAGS=$(DEBUG)
# Native host compiler for the 'build' tool
# Native host compiler for the 'build' tool
HOST_CC ?= cc

KERNLIB=kernlib
MKERNEL=itron
SERVER=port-manager
# DRIVERS=console keyboard fd765a ide ne2000 rs232c beep hcm_pci pcmcia psaux
DRIVERS=console keyboard fd765a ide psaux 
LOWLIB=posix_lowlib
USERLIBS=posix_libc
SERVERS = wconsole ramdisk
MANAGERS=posix_manager $(SERVERS)
USERAP=init


PROGRAMS=$(MKERNEL) $(DRIVERS) $(LOWLIB) $(USERLIBS) $(MANAGERS) $(USERAP)

all: $(PROGRAMS) btron 

btron: build config.tab dummy
	./build config.tab btron

build.o: build.c $(INC)/itron_module.h
	$(HOST_CC) $(CFLAGS) -c build.c -o build.o

build: build.o
	$(HOST_CC) $(CFLAGS) -o build build.o

clean:
	rm -f build build.o btron
	(cd ../../BTRON/device/console; ${MAKE} clean)
	(cd ../../BTRON/device/keyboard; ${MAKE} clean)
	(cd ../../BTRON/device/fd765a; ${MAKE} clean)
	(cd ../../BTRON/device/ide; ${MAKE} clean)
	(cd ../../BTRON/device/ne2000; ${MAKE} clean)
	(cd ../../BTRON/device/rs232c; ${MAKE} clean)
	(cd ../../BTRON/device/beep; ${MAKE} clean)
	(cd ../../BTRON/device/hcm_pci; ${MAKE} clean)
	(cd ../../BTRON/device/pcmcia; ${MAKE} clean)
	(cd ../../ITRON/make; ${MAKE} clean)
	(cd ../../BTRON/init; ${MAKE} clean)
	(cd ../../POSIX/manager; ${MAKE} clean)
	(cd ../../POSIX/servers/wconsole; ${MAKE} clean)
	(cd ../../POSIX/servers/ramdisk; ${MAKE} clean)
	(cd ../../POSIX/lowlib; ${MAKE} clean)
	(cd ../../POSIX/libc; ${MAKE} clean)
	(cd ../../BTRON/device/psaux; ${MAKE} clean)

dummy:
	echo '*dummy*'

$(DRIVERS):
	(cd ../device/$@; $(MAKE) CC="$(X86_CC)" LD="$(X86_LD)" X86_CC="$(X86_CC)" X86_LD="$(X86_LD)" PLATFORM="$(PLATFORM)" AR="$(AR)" RANLIB="$(RANLIB)")

itron:
	(cd ../../ITRON/make; $(MAKE) CC="$(X86_CC)" LD="$(X86_LD)" X86_CC="$(X86_CC)" X86_LD="$(X86_LD)" PLATFORM="$(PLATFORM)" AR="$(AR)" RANLIB="$(RANLIB)")

posix_lowlib:
	(cd ../../POSIX/lowlib; $(MAKE) CC="$(X86_CC)" LD="$(X86_LD)" X86_CC="$(X86_CC)" X86_LD="$(X86_LD)" PLATFORM="$(PLATFORM)" AR="$(AR)" RANLIB="$(RANLIB)")

$(SERVERS):
	(cd ../../POSIX/servers/$@; $(MAKE) CC="$(X86_CC)" LD="$(X86_LD)" X86_CC="$(X86_CC)" X86_LD="$(X86_LD)" PLATFORM="$(PLATFORM)" AR="$(AR)" RANLIB="$(RANLIB)")

posix_manager:
	(cd ../../POSIX/manager; $(MAKE) CC="$(X86_CC)" LD="$(X86_LD)" X86_CC="$(X86_CC)" X86_LD="$(X86_LD)" PLATFORM="$(PLATFORM)" AR="$(AR)" RANLIB="$(RANLIB)")

posix_libc:
	(cd ../../POSIX/libc; $(MAKE) CC="$(X86_CC)" LD="$(X86_LD)" X86_CC="$(X86_CC)" X86_LD="$(X86_LD)" PLATFORM="$(PLATFORM)" AR="$(AR)" RANLIB="$(RANLIB)")

init:
	(cd ../init; $(MAKE) CC="$(X86_CC)" LD="$(X86_LD)" X86_CC="$(X86_CC)" X86_LD="$(X86_LD)" PLATFORM="$(PLATFORM)" AR="$(AR)" RANLIB="$(RANLIB)")

