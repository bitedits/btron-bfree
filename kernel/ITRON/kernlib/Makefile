#
# Updated for modern LLVM/Clang cross-compilation.
# Accepts X86_CC, X86_LD from parent (via Rules.mk).
#

# Toolchain — X86_CC must be the full cross-compiler command
CC  := $(if $(X86_CC),$(X86_CC),gcc -m32)
LD  := $(if $(X86_LD),$(X86_LD),ld -m elf_i386)
AR  := $(if $(AR),$(AR),/opt/homebrew/opt/llvm/bin/llvm-ar)
RANLIB := $(if $(RANLIB),$(RANLIB),/opt/homebrew/opt/llvm/bin/llvm-ranlib)

CFLAGS = -O2 -fno-builtin -ffreestanding -nostdlib -std=gnu89 \
         -Wno-implicit-function-declaration -Wno-return-type \
         -I../h -I../i386 -I../ibmpc -I.. -I../servers

OBJS =	call_kernel.o sys_task.o sys_message.o sys_debug.o \
	port_manager.o message_port.o io.o sys_errno.o sys_interrupt.o \
	sys_virtual.o sys_misc.o eventflag.o sys_eventflag.o sys_time.o

OTHEROBJS = string.o binary.o interrupt.o sys_lowlib.o \
	malloc.o dma.o

# Explicit pattern rules so .S files use the cross-compiler
# (which has Clang's integrated assembler understanding AT&T syntax)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.S
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all libkernel.a libitron.a

all: libkernel.a libitron.a

libkernel.a: $(OBJS) $(OTHEROBJS)
	rm -f $@
	$(AR) rv $@ $(OBJS) $(OTHEROBJS)
	$(RANLIB) $@

libitron.a: $(OBJS)
	rm -f $@
	$(AR) rv $@ $(OBJS)
	$(RANLIB) $@

clean:
	rm -f $(OBJS) $(OTHEROBJS) libkernel.a libitron.a
