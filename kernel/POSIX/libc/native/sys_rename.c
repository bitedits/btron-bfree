/*

B-Free Project の生成物は GNU Generic PUBLIC LICENSE に従います。

GNU GENERAL PUBLIC LICENSE
Version 2, June 1991

(C) B-Free Project.

(C) 2001, Tomohide Naniwa

*/
/* POSIX Library misc function.
*/

/* @(#)$Header: /Users/tonpa/Downloads/b-free/b-free/kernel/POSIX/libc/native/sys_rename.c,v 1.1.1.1 2003/02/05 03:57:15 monaka Exp $  */
static char rcsid[] =
    "@(#)$Id: sys_rename.c,v 1.1.1.1 2003/02/05 03:57:15 monaka Exp $";


#include "../native.h"


/* rename 
 *
 */
int rename(char *src, char *dst)
{
    int errno;
#if 0
    return (call_lowlib(PSC_RENAME, strlen(src), src, strlen(dst), dst));
#endif
    errno = link(src, dst);
    if (errno)
	return (errno);
    errno = unlink(src);
    return (errno);
}
