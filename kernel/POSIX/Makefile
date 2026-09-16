#
#	B-Free OS ºîÀ®ÍÑ makefile
#
#$Id: Makefile,v 1.1.1.1 2003/02/05 03:57:14 monaka Exp $
#

COMPONENT=kernlib posix libc

all: $(COMPONENT)


kernlib: 
	${MAKE} -C ../BTRON/kernlib

posix: kernlib
	${MAKE} -C manager

libc: kernlib
	${MAKE} -C libc

clean:
	${MAKE} -C libc clean
	${MAKE} -C manager clean
