/*

B-Free Project の生成物は GNU Generic PUBLIC LICENSE に従います。

GNU GENERAL PUBLIC LICENSE
Version 2, June 1991

(C) B-Free Project.

*/
/* @(#)$Header: /Users/tonpa/Downloads/b-free/b-free/kernel/BTRON/device/beep/beeplow.c,v 1.1.1.1 2003/02/05 03:56:53 monaka Exp $ */
static char rcs[] = "@(#)$Header: /Users/tonpa/Downloads/b-free/b-free/kernel/BTRON/device/beep/beeplow.c,v 1.1.1.1 2003/02/05 03:56:53 monaka Exp $";


/*
 *
 *
 */

#include "beep.h"
#include "beep_internal.h"

UW	initilized = 0;


/* BEEP アダプタが存在しているかどうかをチェックする
 */
ER
probe (struct device *dev)
{
  /*** ここに ***/

  return (E_OK);
}


/* 
 * $Log: beeplow.c,v $
 * Revision 1.1.1.1  2003/02/05 03:56:53  monaka
 * From eota-0.3.4.tgz
 *
 * Revision 1.1  1999/02/17 04:23:56  monaka
 * First version.
 *
 * Revision 1.1  1998/12/19 07:50:25  monaka
 * Pre release version.
 *
 */
