#
# $Header: /Users/tonpa/Downloads/b-free/b-free/kernel/BTRON/manager/FM/Makefile,v 1.1.1.1 2003/02/05 03:57:01 monaka Exp $
#
#
# $Log: Makefile,v $
# Revision 1.1.1.1  2003/02/05 03:57:01  monaka
# From eota-0.3.4.tgz
#
# Revision 1.1  1996/10/29 16:19:12  night
# ╨г╫И╓непо©
#
#
#

CPP=/lib/cpp
CFLAGS= -b i486-linuxaout -I. -I../../../ITRON -I../../../kernlib -fno-builtin $(IDENT)
CC=gcc
AS=/usr/local/bin/as
KP=kp -input-code euc
MKDEPEND=$(CC) -M
STARTADDR=0x80100000
ENTRY=_start
LIBS=../kernlib/libkernel.a FM/libfm.a PM/libpm.a MM/libmm.a
LD=/usr/local/bin/ld


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.s
	$(CPP) $(ASFLAGS) $*.s | $(AS) -o $*.o


OBJS=dummy.o

all: libfm.a

libfm.a: $(OBJS)
	ar rv $@ $<

	
