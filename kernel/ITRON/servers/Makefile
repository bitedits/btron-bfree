#
# @(#) $Header: /Users/tonpa/Downloads/b-free/b-free/kernel/ITRON/servers/Makefile,v 1.1.1.1 2003/02/05 03:57:12 monaka Exp $
#
#

TARGET =	port-manager
LOAD_POINT =	0x00010000
ENTRY =		_main
#LD = /usr/local/bin/ld		# ZIMAGE タイプの実行ファイルを作成する
				# ことができる LD を使う。
#LD=/usr/bin/ld
LD=ld

CC=gcc
INC=-I../../ITRON/h -I../../ITRON/i386
CFLAGS=$(INC) -O2 -fno-builtin


OBJS=port-manager.o database.o


all: $(TARGET)


$(TARGET): $(OBJS)
	$(LD) -static -o $(TARGET) -e $(ENTRY) -Ttext=$(LOAD_POINT)  $(OBJS) ../kernlib/libkernel.a	


clean:
	rm -f $(OBJS) $(TARGET)


database.o: port-manager.h

port-manager.o: port-manager.h
