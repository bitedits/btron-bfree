/*

B-Free Project ÇÃê∂ê¨ï®ÇÕ GNU Generic PUBLIC LICENSE Ç…è]Ç¢Ç‹Ç∑ÅB

GNU GENERAL PUBLIC LICENSE
Version 2, June 1991

(C) B-Free Project.

*/
/* POSIX Library misc function.
*/

/* @(#)$Header: /Users/tonpa/Downloads/b-free/b-free/kernel/POSIX/libc/native/sys_utime.c,v 1.1.1.1 2003/02/05 03:57:15 monaka Exp $  */
static char rcsid[] = "@(#)$Id: sys_utime.c,v 1.1.1.1 2003/02/05 03:57:15 monaka Exp $";


#include "../native.h"


/* utime 
 *
 */
int
utime (char *path, struct utimbuf *buf)
{
  return (call_lowlib (PSC_UTIME, strlen (path), path, buf));
}


