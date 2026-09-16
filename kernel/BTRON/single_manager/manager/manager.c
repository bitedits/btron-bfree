/*

B-Free Project の生成物は GNU Generic PUBLIC LICENSE に従います。

GNU GENERAL PUBLIC LICENSE
Version 2, June 1991

(C) B-Free Project.

*/

/* @(#)$Header: /Users/tonpa/Downloads/b-free/b-free/kernel/BTRON/single_manager/manager/manager.c,v 1.1.1.1 2003/02/05 03:57:09 monaka Exp $
 */

static char rcsid[] = "@(#)$Header: /Users/tonpa/Downloads/b-free/b-free/kernel/BTRON/single_manager/manager/manager.c,v 1.1.1.1 2003/02/05 03:57:09 monaka Exp $";


/*
 * $Log: manager.c,v $
 * Revision 1.1.1.1  2003/02/05 03:57:09  monaka
 * From eota-0.3.4.tgz
 *
 * Revision 1.2  1998/11/10 14:57:43  night
 * main 関数の名前を startup に変更。
 * 註釈の追加。
 *
 * Revision 1.1  1998/10/23 17:18:40  night
 * 最初の登録
 *
 *
 */




/* このファイルは、BTRON single manager のメイン処理モジュールが
 * 入っている。
 */


#include "manager.h"

/* B-Free BTRON single manager のメイン処理関数
 *
 * 
 */
void
startup ()
{
  /* マネージャの資源の初期化
   */
  

  /* マネージャが要求を受信するためのポートを作成
   */


  /* ポートをポートマネージャに登録。登録名は、 "BTRON/manager"
   */


  /* マネージャ内の各モジュールの初期化
   */


  /* 処理ループ: ポートにデータが入ったかどうかをチェックし続ける
   */
  for (;;)
    {
    }

  /* ここには来ない */
}
