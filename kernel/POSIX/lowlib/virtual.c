/*

B-Free Project の生成物は GNU Generic PUBLIC LICENSE に従います。

GNU GENERAL PUBLIC LICENSE
Version 2, June 1991

(C) B-Free Project.

*/
/* @(#)$Header: /Users/tonpa/Downloads/b-free/b-free/kernel/POSIX/lowlib/virtual.c,v 1.1.1.1 2003/02/05 03:57:17 monaka Exp $ */
static char rcsid[] = "@(#)$Header: /Users/tonpa/Downloads/b-free/b-free/kernel/POSIX/lowlib/virtual.c,v 1.1.1.1 2003/02/05 03:57:17 monaka Exp $";

/*
 * 仮想記憶関連の処理を行うファイル。
 *
 *
 * $Log: virtual.c,v $
 * Revision 1.1.1.1  2003/02/05 03:57:17  monaka
 * From eota-0.3.4.tgz
 *
 * Revision 1.1  1996/11/11 13:36:06  night
 * IBM PC 版への最初の登録
 *
 * ----------------
 *
 *
 */

#include "lowlib.h"

/* vm_create - ユーザプロセスの仮想空間を作成する。
 *
 */
int
vm_create (ID taskid, UW vaddr, UW size, UW permission, UW mode)
{
}

