
# B-Free OS — Root Makefile
# -----------------------------------------------------------------------
# Original build:  make (legacy, expects gcc + as86/ld86 on Linux)
# New targets:
#   make pc        — build for IBMPC and create hda.qcow2 (QEMU i386)
#   make pc98      — build for NEC PC-9801 (compile-only, no disk image)
#   make run-pc    — run QEMU i386 with hda.qcow2
#   make run-pc98  — run qemu-system-pc98 with hda.qcow2
#   make clean     — remove all generated artifacts
# -----------------------------------------------------------------------

# Pull in centralised toolchain definitions
include Rules.mk

# -----------------------------------------------------------------------
# PC (IBM-PC / QEMU i386) build — full disk image
# -----------------------------------------------------------------------
.PHONY: pc
pc: PLATFORM=IBMPC
pc:
	@echo "==> Building B-Free OS for IBM-PC / QEMU i386"
	# 1. Build sfsboot (1st-stage + 2nd-stage loader)
	$(MAKE) -C sfsboot PLATFORM=$(PLATFORM) \
	    X86_CC="$(X86_CC)" X86_LD="$(X86_LD)" NASM="$(NASM)" HOST_CC="$(HOST_CC)" OBJCOPY="$(OBJCOPY)"
	# 2. Build all kernel modules + OS image (btron)
	$(MAKE) -C kernel/BTRON/make PLATFORM=$(PLATFORM) \
	    X86_CC="$(X86_CC)" X86_LD="$(X86_LD)" HOST_CC="$(HOST_CC)" AR="$(AR)" RANLIB="$(RANLIB)"
	cp kernel/BTRON/make/btron ./2nd_fd.img
	# 3. Build host filesystem tools (mksfs, statfs)
	$(MAKE) -C kernel/POSIX/mkfs HOST_CC="$(HOST_CC)"
	# 4. Create HDD SFS image with bootloader + 2ndboot + btron
	$(MAKE) -C kernel/POSIX/mkfs hd-image \
	    HOST_CC="$(HOST_CC)"
	# 5. Prepare boot floppy (fd.img) and HDD (hda.qcow2) for QEMU
	cp kernel/POSIX/mkfs/fd_boot.bin ./fd.img
	cp kernel/POSIX/mkfs/fd_boot.bin ./1st_fd.img
	$(QEMU_IMG) convert -f raw -O qcow2 kernel/POSIX/mkfs/hd_boot.bin hda.qcow2
	@echo "==> Done. Run:  make run-pc"

# -----------------------------------------------------------------------
# PC-98 (NEC PC-9801) build — compile-only check
# -----------------------------------------------------------------------
.PHONY: pc98
pc98: PLATFORM=PC9801
pc98:
	@echo "==> Building B-Free OS for NEC PC-9801 (compile check)"
	$(MAKE) -C kernel/ITRON/make PLATFORM=$(PLATFORM) \
	    X86_CC="$(X86_CC)" X86_LD="$(X86_LD)" AR="$(AR)" RANLIB="$(RANLIB)"
	@echo "==> PC-98 kernel compile successful."

# -----------------------------------------------------------------------
# Run targets
# -----------------------------------------------------------------------
.PHONY: run-pc
run-pc: hda.qcow2
	@echo "==> Launching B-Free in QEMU (i386) ..."
	$(QEMU_I386) $(QEMU_FLAGS_PC)

.PHONY: run-pc98
run-pc98: hda.qcow2
	@echo "==> Launching B-Free in QEMU (PC-98) ..."
	$(QEMU_PC98) $(QEMU_FLAGS_PC98)

# -----------------------------------------------------------------------
# Legacy / original build (unchanged, kept for historical reference)
# -----------------------------------------------------------------------
.PHONY: legacy
legacy:
	(cd sfsboot; $(MAKE))
	(cd kernel/BTRON/make; $(MAKE))
	cp kernel/BTRON/make/btron ./2nd_fd.img
	(cd kernel/POSIX/mkfs; $(MAKE))
	(cd kernel/POSIX/mkfs; ./mk_img.sh)
	cp kernel/POSIX/mkfs/posix_fd.img ./3rd_fd.img
	(cd kernel/POSIX/mkfs; ./mk_hdboot.sh)
	cp kernel/POSIX/mkfs/hd_boot.bin ./1st_fd.img

.PHONY: applications
applications:
	(cd contribution/applications/frtm-bf/src; $(MAKE))

# -----------------------------------------------------------------------
# Clean
# -----------------------------------------------------------------------
.PHONY: clean
clean:
	-$(MAKE) -C sfsboot clean
	-$(MAKE) -C kernel/BTRON/make clean
	-$(MAKE) -C kernel/POSIX/mkfs clean
	-$(MAKE) -C kernel/ITRON/make clean
	rm -f 1st_fd.img 2nd_fd.img 3rd_fd.img hda.qcow2

.PHONY: dummy
dummy:
	echo '*dummy*'

