/*

B-Free Project ÇÃê∂ê¨ï®ÇÕ GNU Generic PUBLIC LICENSE Ç…è]Ç¢Ç‹Ç∑ÅB

GNU GENERAL PUBLIC LICENSE
Version 2, June 1991

(C) B-Free Project.

*/

/* $Header: /Users/tonpa/Downloads/b-free/b-free/kernel/BTRON/init/posix_syscall.c,v 1.1.1.1 2003/02/05 03:56:56 monaka Exp $ */

static char rcsid[] = "$Id: posix_syscall.c,v 1.1.1.1 2003/02/05 03:56:56 monaka Exp $";


#include "init.h"

W
sys_noaction (void)
{
  return call_posix (0, NULL);
}
