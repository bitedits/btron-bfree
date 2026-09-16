/*

B-Free Project の生成物は GNU Generic PUBLIC LICENSE に従います。

GNU GENERAL PUBLIC LICENSE
Version 2, June 1991

(C) B-Free Project.

*/

/* $Header: /Users/tonpa/Downloads/b-free/b-free/kernel/POSIX/manager/global.c,v 1.1.1.1 2003/02/05 03:57:17 monaka Exp $ */

/* global.c - POSIX 環境マネージャのための大域変数
 *
 *
 * $Log: global.c,v $
 * Revision 1.1.1.1  2003/02/05 03:57:17  monaka
 * From eota-0.3.4.tgz
 *
 * Revision 1.3  1997/10/24 13:56:32  night
 * rcsid[] の削除。
 *
 * Revision 1.2  1996/12/12 13:43:26  night
 * 文字コードを SJIS から EUC に変更
 *
 * Revision 1.1  1996/12/12 13:42:30  night
 * 最初の登録
 *
 *
 */

#include "posix.h"
#include "utsname.h"


struct utsname		system_name = 
{
  SYS_SYSNAME,
  SYS_NODENAME,
  SYS_RELEASE,
  SYS_VERSION,
  SYS_MACHINE
};


