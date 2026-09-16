/*

B-Free Project の生成物は GNU Generic PUBLIC LICENSE に従います。

GNU GENERAL PUBLIC LICENSE
Version 2, June 1991

(C) B-Free Project.

*/
/* $Header: /Users/tonpa/Downloads/b-free/b-free/kernel/POSIX/lowlib/syscalls/fstat.c,v 1.1.1.1 2003/02/05 03:57:17 monaka Exp $ */
static char rcsid[] = "@(#)$Header: /Users/tonpa/Downloads/b-free/b-free/kernel/POSIX/lowlib/syscalls/fstat.c,v 1.1.1.1 2003/02/05 03:57:17 monaka Exp $";

/*
 * $Log: fstat.c,v $
 * Revision 1.1.1.1  2003/02/05 03:57:17  monaka
 * From eota-0.3.4.tgz
 *
 * Revision 1.3  1999/02/19 10:04:33  monaka
 * Addition or fix for parameter structure.
 *
 * Revision 1.2  1999/02/19 08:59:18  monaka
 * added the parameter structure on.
 *
 * Revision 1.1  1997/08/31 13:10:44  night
 * 最初の登録
 *
 *
 *
 */


#include "../lowlib.h"




int
psys_fstat (void *argp)
{
  struct a
    {
      W fd;
      struct stat *st;
    } *args = (struct a *)argp;

  /*
   * まだインプリメントしていない。ENOSYS を返す。
   */
  errno = ENOSYS;

  return (NULL);
}
