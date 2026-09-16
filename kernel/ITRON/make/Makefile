# $Revision: 1.1.1.1 $
#
# Updated for modern LLVM/Clang cross-compilation.
# Accepts X86_CC, X86_LD, PLATFORM from parent Makefile (via Rules.mk).
#
COMMON=../../../include

# Toolchain — override from parent or fall back to legacy defaults
CC     := $(if $(X86_CC),$(X86_CC),gcc)
LD     := $(if $(X86_LD),$(X86_LD),ld -m elf_i386)
AR     := $(if $(AR),$(AR),/opt/homebrew/opt/llvm/bin/llvm-ar)
RANLIB := $(if $(RANLIB),$(RANLIB),/opt/homebrew/opt/llvm/bin/llvm-ranlib)

# Platform — IBMPC (default) or PC9801
PLATFORM ?= IBMPC

ifeq ($(PLATFORM),PC9801)
  HAL_DIR   = ../pc9801
  PLAT_FLAG = -DPC9801
else
  HAL_DIR   = ../ibmpc
  PLAT_FLAG = -DIBMPC
endif

#DEBUG=-DTSKSW_DEBUG
DEBUG=-DKEYBOARD_DEBUG
IDENT=-DTIMER_TEST -DI386 $(PLAT_FLAG) -DAUTO_START -DPORTMANAGER -DKERNLIB -DITRON $(DEBUG)

CFLAGS=-O2 -fno-builtin -ffreestanding -nostdlib \
       -std=gnu89 \
       -Wno-implicit-function-declaration -Wno-return-type \
       -I. -I.. -I../h -I../i386 -I$(HAL_DIR) -I$(COMMON) \
       -Wall $(IDENT)
MKDEPEND=$(CC) -M
STARTADDR=0x80020000
ENTRY=startup


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.S
	$(CC) $(CFLAGS) -c $< -o $@

OBJS= \
	startup.o \
	devconfig.o \
	console.o \
	dummy.o \
	error.o \
	itron_memory.o \
	main.o \
	misc.o \
	kalloc.o \
	pmemory.o \
	printf.o \
	syscall.o \
	syscall-if.o \
	task.o \
	time.o \
	version.o \
	virtual_memory.o \
	semaphore.o \
	tss.o \
	fault.o \
	fpu.o \
	timer.o \
	io.o \
	gdt.o \
	task2.o \
	message.o \
	eventflag.o \
	locore.o \
	interrupt.o  \
	device.o \
	keyboard.o \
	dbg_functions.o \
	system.o \
	lowlib.o \
	posix.o

OTHEROBJ=../kernlib/port_manager.o ../kernlib/message_port.o \
           ../kernlib/sys_errno.o

SRCS=main.c memory.c task.c time.c version.c error.c dummy.c printf.c \
     console.c fault.c syscall.c misc.c timer.c \
     virtual_memory.c itron_memory.c pmemory.c \
     startup.S

#ASRCS=startup.s io.s interrupt.s locore.s

all: itron.image

itron.image: $(OBJS) libkernel.a port_manager
	$(LD) -static -o itron.image -e $(ENTRY) --image-base=$(STARTADDR) -Ttext=$(STARTADDR) $(OBJS) $(OTHEROBJ)

.PHONY: libkernel.a port_manager

libkernel.a:
	$(MAKE) -C ../kernlib X86_CC="$(CC)" X86_LD="$(LD)" AR="$(AR)" RANLIB="$(RANLIB)"

port_manager:
	$(MAKE) -C ../servers X86_CC="$(CC)" X86_LD="$(LD)" AR="$(AR)" RANLIB="$(RANLIB)"

tags:
	etags ../*/*.[hcs]

depend:
	$(MKDEPEND) -x c $(SRCS) > .depend

clean:
	rm -f $(OBJS)
	rm -f itron.image
	${MAKE} -C ../kernlib clean
	${MAKE} -C ../servers clean

include CFILES
include SFILES
