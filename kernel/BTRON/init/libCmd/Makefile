# $Id: Makefile,v 1.1.1.1 2003/02/05 03:56:57 monaka Exp $
# 
# Makefile for init.
#
ROOT = ../../..
CFLAGS = -O2 -fno-builtin -Wall -I.. -I../lib -I$(ROOT) -I$(ROOT)/ITRON -I$(ROOT)/ITRON/kernlib -I$(ROOT)/ITRON/h -I$(ROOT)/ITRON/i386
CXXFLAGS = $(CFLAGS)
#CFLAGS = -static -g -I. -I./_include -I$(ROOT) -I../../kernlib -I$(ROOT)/h -I$(ROOT)/i386 -D_DEBUG_ON_UNIX

CC = gcc

OBJS = command.o graphic.o #posix-misc.o posix-file.o 

all: libCmd.a

libCmd.a: $(OBJS)
	ar rv libCmd.a $(OBJS)
	ranlib libCmd.a

command.o: command.c

graphic.o: graphic.c

GraphicOp.o: GraphicOp.c

posix-misc.o: posix-misc.c

posix-file.o: posix-file.c

clean:
	rm -f libCmd.a
	rm -f $(OBJS)
	rm -f *~
