# sfsboot/2nd/Makefile
# Updated for modern LLVM/Clang cross-compilation.
# Accepts X86_CC, X86_LD, NASM, HOST_CC from parent (Rules.mk).

CC      := $(if $(X86_CC),$(X86_CC),gcc -m32)
LD      := $(if $(X86_LD),$(X86_LD),ld -m elf_i386)
NASM    ?= nasm
HOST_CC := $(if $(HOST_CC),$(HOST_CC),cc)
OBJCOPY := $(if $(OBJCOPY),$(OBJCOPY),$(shell \
  for p in \
    /opt/homebrew/opt/llvm/bin/llvm-objcopy \
    /usr/local/opt/llvm/bin/llvm-objcopy \
    llvm-objcopy \
    objcopy; \
  do if command -v "$$p" >/dev/null 2>&1; then echo "$$p"; break; fi; done))

GSTRIP = strip
RM = /bin/rm

.SUFFIXES : .asm

.asm.o :
	$(NASM) -f elf $<

CSRC=main.c console.c keyboard.c memory.c \
     date.c idt.c cinterrupt.c fd.c fdboot.c\
     dma.c page.c lib.c ide.c \
     evaluate.c bootos.c time.c

OBJ32 = main.o console.o keyboard.o memory.o  \
	date.o io.o idt.o interrupt.o cinterrupt.o fd.o fdboot.o\
	dma.o page.o paging.o lib.o ide.o sfs.o \
	evaluate.o bootos.o time.o
LIBS =

OBJ16 = start16.o

TOOLS = build_boot2

START_ADDR = 0x380000

COMMON = ../../include
ITRON = ../../kernel/ITRON
INCPATH = -I. -I$(COMMON) -I$(ITRON) -I$(ITRON)/h

# -mno-80387: Clang equivalent of -msoft-float for x87 avoidance
# -std=gnu89 + -Wno-implicit-function-declaration: K&R implicit declarations
NOFLAGS=-c -mno-80387 -fno-builtin -std=gnu89 \
        -Wno-implicit-function-declaration -Wno-return-type \
        -D__LINUX__ -DSUPPORT_144 $(DEBUG) -DIBMPC $(HDBOOT) $(INCPATH)
CFLAGS=-O $(NOFLAGS)

LDOPT32 = -n -Ttext=$(START_ADDR) --image-base=$(START_ADDR) -static -e _main

########################################################################
#
#	2ndboot ...... 最終的に作られる Second BOOT イメージ
#
2ndboot: $(TOOLS) init mode32
	$(OBJCOPY) -O binary mode32 mode32.raw
	./build_boot2 init mode32.raw 2ndboot

init: start16 start32
	cat start16 start32 > init

start16: start16.asm
	$(NASM) -f bin -o start16 start16.asm

start32: start32.asm
	$(NASM) -f bin -o start32 start32.asm

mode32: $(OBJ32)
	$(LD) $(LDOPT32) -o mode32 $(OBJ32) $(LIBS)
	cp mode32 mode32.sym
	$(GSTRIP) mode32

memory.o: memory.c
	$(CC) $(NOFLAGS) memory.c -o $@

clean:
	$(RM) -f $(OBJ32) $(OBJ16)
	$(RM) -f core mode32 start16 start32 build_boot2 mode32.raw mode32.sym
	$(RM) -f 2ndboot init

tags:
	$(ETAGS) $(CSRC)

mkdepend:
	$(CC) -M -D__LINUX__ $(CSRC) > DEPEND

#######################################################################
#
#		T O O L S
#

build_boot2: build_boot2.c
	$(HOST_CC) -std=gnu89 -Wno-implicit-function-declaration -D__LINUX__ -DGCC_USE -o build_boot2 build_boot2.c

#include DEPEND





