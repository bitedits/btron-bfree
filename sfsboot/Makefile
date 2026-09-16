#
#	Makefile for sfsboot image.
# Updated for modern LLVM/Clang cross-compilation.
# Accepts HOST_CC, X86_CC, X86_LD, NASM from parent (Rules.mk).
#

ROOT=../kernel

# Native host compiler for mkmap, mkboot, mkhdboot
GCC := $(if $(HOST_CC),$(HOST_CC),cc)

# -std=gnu89 keeps K&R implicit-function-declaration behavior
CFLAGS=-D__LINUX__ -std=gnu89 -Wno-implicit-function-declaration

all: 1stboot 2ndboot mkmap mkboot

1stboot:
	$(MAKE) -C 1st 1stboot NASM="$(NASM)"

2ndboot:
	$(MAKE) -C 2nd 2ndboot \
	    X86_CC="$(X86_CC)" X86_LD="$(X86_LD)" NASM="$(NASM)" HOST_CC="$(GCC)" OBJCOPY="$(OBJCOPY)"

mkmap: mkmap.c
	$(GCC) $(CFLAGS) -o mkmap mkmap.c

mkboot: mkboot.c
	$(GCC) $(CFLAGS) -o mkboot mkboot.c

mkhdboot: mkhdboot.c
	$(GCC) $(CFLAGS) -o mkhdboot mkhdboot.c

clean:
	$(MAKE) -C 1st clean
	$(MAKE) -C 2nd clean
	rm -f mkmap mkboot mkhdboot
