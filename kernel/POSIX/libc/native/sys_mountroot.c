/*

B-Free Project の生成物は GNU Generic PUBLIC LICENSE に従います。

GNU GENERAL PUBLIC LICENSE
Version 2, June 1991

(C) B-Free Project.

*/
/* POSIX Library misc function.
*/

/* @(#)$Header: /Users/tonpa/Downloads/b-free/b-free/kernel/POSIX/libc/native/sys_mountroot.c,v 1.1.1.1 2003/02/05 03:57:15 monaka Exp $  */
static char rcsid[] = "@(#)$Id: sys_mountroot.c,v 1.1.1.1 2003/02/05 03:57:15 monaka Exp $";


#include "../native.h"


/* mountroot
 *
 */
int
mountroot (int devnum)
{
  int result;
#ifdef notdef
  printf("mountroot: begin.");
#endif
  result = call_lowlib (PSC_MOUNTROOT, devnum); 
#ifdef notdef
  printf("mountroot: end.");
#endif
  return (result);
}


