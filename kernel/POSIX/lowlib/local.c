/*

B-Free Project の生成物は GNU Generic PUBLIC LICENSE に従います。

GNU GENERAL PUBLIC LICENSE
Version 2, June 1991

(C) B-Free Project.

*/
/* @(#)$Header: /Users/tonpa/Downloads/b-free/b-free/kernel/POSIX/lowlib/local.c,v 1.1.1.1 2003/02/05 03:57:17 monaka Exp $ */


static char rcsid[] = "$Id: local.c,v 1.1.1.1 2003/02/05 03:57:17 monaka Exp $";


#include "lowlib.h"


/* プロセス固有の情報を管理する */

#ifdef notdef
struct posix_process_info	*posix_info;
#else
struct lowlib_data *posix_info;
#endif
