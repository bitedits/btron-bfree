#
# Updated for modern LLVM/Clang cross-compilation.
# Accepts X86_CC, X86_LD from parent (via Rules.mk).
#

TARGET =	port-manager
LOAD_POINT =	0x00010000
ENTRY =		_main

CC := $(if $(X86_CC),$(X86_CC),gcc -m32)
LD := $(if $(X86_LD),$(X86_LD),ld -m elf_i386)

INC=-I../../ITRON/h -I../../ITRON/i386 -I../../ITRON/ibmpc
CFLAGS=$(INC) -O2 -fno-builtin -ffreestanding -nostdlib -std=gnu89 \
       -Wno-implicit-function-declaration -Wno-return-type


OBJS=port-manager.o database.o


all: $(TARGET)


$(TARGET): $(OBJS) ../kernlib/libkernel.a
	$(LD) -static -o $(TARGET) -e $(ENTRY) --image-base=$(LOAD_POINT) -Ttext=$(LOAD_POINT) $(OBJS) ../kernlib/libkernel.a


clean:
	rm -f $(OBJS) $(TARGET)


database.o: port-manager.h

port-manager.o: port-manager.h
