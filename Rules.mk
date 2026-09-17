# Rules.mk --- Centralized toolchain configuration for B-Free OS
# Include this from all sub-Makefiles with:  include $(ROOT)/Rules.mk
# (where ROOT points to the btron-bfree workspace root)

# -----------------------------------------------------------------------
# Host detection
# -----------------------------------------------------------------------
UNAME_S := $(shell uname -s)

# -----------------------------------------------------------------------
# LLVM / Clang (preferred on macOS; fallback to system gcc on Linux)
# -----------------------------------------------------------------------
LLVM_CLANG := $(shell \
  for p in \
    /opt/homebrew/opt/llvm/bin/clang \
    /usr/local/opt/llvm/bin/clang \
    clang; \
  do if command -v "$$p" >/dev/null 2>&1; then echo "$$p"; break; fi; done)

LLD_BIN := $(shell \
  for p in \
    /opt/homebrew/bin/ld.lld \
    /usr/local/bin/ld.lld \
    ld.lld; \
  do if command -v "$$p" >/dev/null 2>&1; then echo "$$p"; break; fi; done)

ifeq ($(UNAME_S), Darwin)
  # Cross-compile i386 ELF kernel/drivers with Clang targeting bare metal
  X86_CC  ?= $(LLVM_CLANG) --target=i686-none-elf -march=i386 -mno-sse -mno-mmx -std=gnu89 -ffreestanding -fcommon -Wno-implicit-function-declaration -Wno-incompatible-function-pointer-types -Wno-int-conversion -Wno-return-mismatch
  X86_LD  ?= $(LLD_BIN) -m elf_i386 --image-base=0 --omagic
  # Native host tools (build, mksfs, statfs, mkmap, mkboot …) as Mach-O
  HOST_CC ?= clang -std=gnu89 -Wno-implicit-function-declaration -Wno-implicit-int
else
  # Linux: use system gcc/ld with -m32 for the target
  X86_CC  ?= gcc -m32 -std=gnu89 -ffreestanding -fcommon -Wno-implicit-function-declaration -Wno-incompatible-function-pointer-types -Wno-int-conversion -Wno-return-mismatch
  X86_LD  ?= ld -m elf_i386
  HOST_CC ?= gcc
endif

# Assembler (NASM for both platforms)
NASM    ?= nasm

# -----------------------------------------------------------------------
# Common CFLAGS for kernel / drivers / boot code
# -----------------------------------------------------------------------
# -std=gnu89  – original K&R-adjacent C used by the sources
# -fno-builtin – don't assume libc built-ins
# -ffreestanding – no hosted runtime
# -nostdlib    – no standard startup or libraries
# -O2          – optimise (safe for bare-metal)
# -Wall        – warnings
# Suppressed: implicit-function-declaration (K&R style), return-mismatch
X86_CFLAGS_COMMON := \
  -std=gnu89 \
  -fno-builtin \
  -ffreestanding \
  -nostdlib \
  -O2 \
  -Wall \
  -Wno-implicit-function-declaration \
  -Wno-return-type \
  -Wno-int-conversion

# -----------------------------------------------------------------------
# Platform switch  (set PLATFORM=PC9801 for PC-98 build, default=IBMPC)
# -----------------------------------------------------------------------
PLATFORM ?= IBMPC

ifeq ($(PLATFORM), PC9801)
  PLATFORM_CFLAGS := -DPC9801
else
  PLATFORM_CFLAGS := -DIBMPC
endif

# -----------------------------------------------------------------------
# QEMU invocation (IBMPC / i386 target)
# -----------------------------------------------------------------------
QEMU_I386 ?= qemu-system-i386

QEMU_FLAGS_PC := \
  -drive file=fd.img,format=raw,if=floppy \
  -boot a \
  -hda hda.qcow2 \
  -net user \
  -net nic,model=rtl8139 \
  -rtc base=localtime \
  -display cocoa,show-cursor=on,zoom-to-fit=on

# -----------------------------------------------------------------------
# QEMU PC-98 invocation (requires qemu-system-pc98 / patched build)
# -----------------------------------------------------------------------
QEMU_PC98 ?= qemu-system-pc98

QEMU_FLAGS_PC98 := \
  -hda hda.qcow2 \
  -rtc base=localtime

# -----------------------------------------------------------------------
# qemu-img
# -----------------------------------------------------------------------
QEMU_IMG ?= qemu-img

# -----------------------------------------------------------------------
# objcopy (use llvm-objcopy on macOS; GNU objcopy on Linux)
# -----------------------------------------------------------------------
OBJCOPY ?= $(shell \
  for p in \
    /opt/homebrew/opt/llvm/bin/llvm-objcopy \
    /usr/local/opt/llvm/bin/llvm-objcopy \
    llvm-objcopy \
    objcopy; \
  do if command -v "$$p" >/dev/null 2>&1; then echo "$$p"; break; fi; done)

# -----------------------------------------------------------------------
# ar / ranlib — use LLVM versions for ELF cross-compiled objects on macOS
# (system ar/ranlib only handle Mach-O and will produce empty archives)
# -----------------------------------------------------------------------
override AR := $(shell \
  for p in \
    /opt/homebrew/opt/llvm/bin/llvm-ar \
    /usr/local/opt/llvm/bin/llvm-ar \
    llvm-ar \
    ar; \
  do if command -v "$$p" >/dev/null 2>&1; then echo "$$p"; break; fi; done)

override RANLIB := $(shell \
  for p in \
    /opt/homebrew/opt/llvm/bin/llvm-ranlib \
    /usr/local/opt/llvm/bin/llvm-ranlib \
    llvm-ranlib \
    ranlib; \
  do if command -v "$$p" >/dev/null 2>&1; then echo "$$p"; break; fi; done)
