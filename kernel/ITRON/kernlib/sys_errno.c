/*

B-Free Project の生成物は GNU Generic PUBLIC LICENSE に従います。

GNU GENERAL PUBLIC LICENSE
Version 2, June 1991

(C) B-Free Project.

*/
/* @(#)$Header: /Users/tonpa/Downloads/b-free/b-free/kernel/ITRON/kernlib/sys_errno.c,v 1.1.1.1 2003/02/05 03:57:12 monaka Exp $ */
static char rcsid[] = "@(#)$Header: /Users/tonpa/Downloads/b-free/b-free/kernel/ITRON/kernlib/sys_errno.c,v 1.1.1.1 2003/02/05 03:57:12 monaka Exp $";

/* $Log: sys_errno.c,v $
/* Revision 1.1.1.1  2003/02/05 03:57:12  monaka
/* From eota-0.3.4.tgz
/*
/* Revision 1.1  1999/04/18 17:48:34  monaka
/* Port-manager and libkernel.a is moved to ITRON. I guess it is reasonable. At least they should not be in BTRON/.
/*
/* Revision 1.1  1996/07/22 23:52:06  night
/* 最初の登録
/*
 * Revision 1.2  1995/09/21  15:51:42  night
 * ソースファイルの先頭に Copyright notice 情報を追加。
 *
 * Revision 1.1  1995/09/17  17:07:03  night
 * 最初の登録
 *
 *
 */

#include "types.h"

/* エラー番号を記憶するためのモジュール。
 * エラー番号を返さない関数が使用する。
 */

ER	sys_errno;
