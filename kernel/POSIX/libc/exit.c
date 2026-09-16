/*

B-Free Project の生成物は GNU Generic PUBLIC LICENSE に従います。

GNU GENERAL PUBLIC LICENSE
Version 2, June 1991

(C) B-Free Project.

*/
/* POSIX Library misc function.
 */

/* @(#)$Header: /Users/tonpa/Downloads/b-free/b-free/kernel/POSIX/libc/exit.c,v 1.1.1.1 2003/02/05 03:57:14 monaka Exp $ */
static char rcsid[] = "@(#)$Header: /Users/tonpa/Downloads/b-free/b-free/kernel/POSIX/libc/exit.c,v 1.1.1.1 2003/02/05 03:57:14 monaka Exp $";


/* $Log: exit.c,v $
/* Revision 1.1.1.1  2003/02/05 03:57:14  monaka
/* From eota-0.3.4.tgz
/*
/* Revision 1.1  1996/11/11 13:33:00  night
/* 最初の登録
/*
 * Revision 1.2  1995/09/21  15:52:10  night
 * ソースファイルの先頭に Copyright notice 情報を追加。
 *
 * Revision 1.1  1995/08/21  13:20:47  night
 * 最初の登録
 *
 *
 */

#include <sys/types.h>
#include <native/syscall.h>


/*
 * プログラムの処理を終了する。
 */
exit (int exitcode)
{
  shutdown_stdio ();	/* 標準入出力ライブラリの後始末 */
                        /* バッファをフラッシュする */

  _exit (exitcode);
}

