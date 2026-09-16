/*

B-Free Project の生成物は GNU Generic PUBLIC LICENSE に従います。

GNU GENERAL PUBLIC LICENSE
Version 2, June 1991

(C) B-Free Project.

*/
/* @(#)$Header: /Users/tonpa/Downloads/b-free/b-free/kernel/ITRON/kernlib/sys_interrupt.c,v 1.1.1.1 2003/02/05 03:57:12 monaka Exp $ */
static char rcsid[] = "@(#)$Header: /Users/tonpa/Downloads/b-free/b-free/kernel/ITRON/kernlib/sys_interrupt.c,v 1.1.1.1 2003/02/05 03:57:12 monaka Exp $";

/*
 * $Log: sys_interrupt.c,v $
 * Revision 1.1.1.1  2003/02/05 03:57:12  monaka
 * From eota-0.3.4.tgz
 *
 * Revision 1.1  1999/04/18 17:48:34  monaka
 * Port-manager and libkernel.a is moved to ITRON. I guess it is reasonable. At least they should not be in BTRON/.
 *
 * Revision 1.2  1996/07/23 17:17:08  night
 * IBM PC 用の make 環境に merge
 *
 * Revision 1.1  1996/07/22  23:52:06  night
 * 最初の登録
 *
 * Revision 1.2  1995/09/21  15:51:43  night
 * ソースファイルの先頭に Copyright notice 情報を追加。
 *
 * Revision 1.1  1995/09/19  18:07:38  night
 * 最初の登録
 *
 *
 */

#include "../ITRON/h/types.h"
#include "../ITRON/h/itron.h"
#include "../ITRON/h/syscall.h"
#include "../ITRON/h/errno.h"


/*
 * 割り込みハンドラの登録
 */
ER
def_int (W intno, T_DINT *pk_dint)
{
  return (call_syscall (SYS_DEF_INT, intno, pk_dint));
}
