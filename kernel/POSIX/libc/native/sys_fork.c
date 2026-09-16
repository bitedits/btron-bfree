/*

B-Free Project の生成物は GNU Generic PUBLIC LICENSE に従います。

GNU GENERAL PUBLIC LICENSE
Version 2, June 1991

(C) B-Free Project.

(C) 2002, Tomohide Naniwa

*/
/* POSIX Library misc function.
*/

/* @(#)$Header: /Users/tonpa/Downloads/b-free/b-free/kernel/POSIX/libc/native/sys_fork.c,v 1.1.1.1 2003/02/05 03:57:15 monaka Exp $  */
static char rcsid[] = "@(#)$Id: sys_fork.c,v 1.1.1.1 2003/02/05 03:57:15 monaka Exp $";


#include "../native.h"

/* fork 用エントリールーチン */
int fork_entry()
{
    ena_int();
    return (0);
}

/* fork 
 *
 */
int
_fork (int esp, int ebp, int ebx, int ecx, int edx, int esi, int edi)
{
  return (call_lowlib (PSC_FORK, esp, ebp, ebx, ecx, edx, esi, edi,
		       fork_entry));
}
