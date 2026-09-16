/*

B-Free Project の生成物は GNU Generic PUBLIC LICENSE に従います。

GNU GENERAL PUBLIC LICENSE
Version 2, June 1991

(C) B-Free Project.

(C) 2002, Tomohide Naniwa

*/
/* $Header: /Users/tonpa/Downloads/b-free/b-free/kernel/POSIX/libc/native.h,v 1.1.1.1 2003/02/05 03:57:14 monaka Exp $ */


#ifndef __NATIVE_H__

#include "../manager/posix.h"

#define NAME_MAX	14


#ifdef notdef
struct dirent
{
  long			d_ino;
  unsigned long		d_off;
  unsigned short	d_reclen;
  char			d_name[NAME_MAX + 1];
};
#endif

struct sigaction
{
};

typedef int	sigset_t;

typedef unsigned long	time_t;

struct tms
{
};

typedef unsigned long	clock_t;

typedef unsigned int	pid_t;

#endif


