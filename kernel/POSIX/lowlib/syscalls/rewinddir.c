/*

B-Free Project の生成物は GNU Generic PUBLIC LICENSE に従います。

GNU GENERAL PUBLIC LICENSE
Version 2, June 1991

(C) B-Free Project.

*/
/* $Header: /Users/tonpa/Downloads/b-free/b-free/kernel/POSIX/lowlib/syscalls/rewinddir.c,v 1.1.1.1 2003/02/05 03:57:17 monaka Exp $ */
static char rcsid[] = "@(#)$Header: /Users/tonpa/Downloads/b-free/b-free/kernel/POSIX/lowlib/syscalls/rewinddir.c,v 1.1.1.1 2003/02/05 03:57:17 monaka Exp $";

/*
 * $Log: rewinddir.c,v $
 * Revision 1.1.1.1  2003/02/05 03:57:17  monaka
 * From eota-0.3.4.tgz
 *
 * Revision 1.2  1999/03/21 00:58:01  monaka
 * Major fix. Many system calls runs correctly (...perhaps ;-). But signal and process functions are not yet.
 *
 * Revision 1.1  1997/08/31 13:10:47  night
 * 最初の登録
 *
 *
 *
 */


#include "../lowlib.h"




int
psys_rewinddir (void *argp)
{
  ER			error;
  struct posix_request	req;
  struct posix_response	res;
  struct psc_rewinddir *args = (struct psc_rewinddir *)argp;

  /*
   * まだインプリメントしていない。ENOSYS を返す。
   */
  errno = ENOSYS;

  return (NULL);
}
