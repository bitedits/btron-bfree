/*

B-Free Project の生成物は GNU Generic PUBLIC LICENSE に従います。

GNU GENERAL PUBLIC LICENSE
Version 2, June 1991

(C) B-Free Project.

*/
/* @(#)$Header: /Users/tonpa/Downloads/b-free/b-free/kernel/BTRON/device/fd765a/misc.c,v 1.1.1.1 2003/02/05 03:56:54 monaka Exp $ */
static char rcsid[] = "@(#)$header$";

/*
 * $Log: misc.c,v $
 * Revision 1.1.1.1  2003/02/05 03:56:54  monaka
 * From eota-0.3.4.tgz
 *
 * Revision 1.1  1996/07/28 19:59:33  night
 * IBM PC 版への最初の登録
 *
 * Revision 1.3  1995/09/21  15:50:58  night
 * ソースファイルの先頭に Copyright notice 情報を追加。
 *
 * Revision 1.2  1995/09/06  16:12:28  night
 * 中間バージョン。
 * start() の中で起動メッセージを出すところまで作成。
 *
 * Revision 1.1  1995/03/18  14:09:03  night
 * 最初の登録
 *
 *
 */

/*
 * 雑多な関数を定義するファイル
 *
 */

void
busywait(int x)
{
  int i,j;
  int	tmp;

  for (i = 0; i < x; i++)
     for (j = 0; j < 100; j++)
       tmp = j;
}


