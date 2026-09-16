/*

B-Free Project の生成物は GNU Generic PUBLIC LICENSE に従います。

GNU GENERAL PUBLIC LICENSE
Version 2, June 1991

(C) B-Free Project.

*/
/* @(#)$Header: /Users/tonpa/Downloads/b-free/b-free/kernel/BTRON/device/svga_cons/svga_conslow.c,v 1.1.1.1 2003/02/05 03:56:56 monaka Exp $ */
static char rcs[] = "@(#)$Header: /Users/tonpa/Downloads/b-free/b-free/kernel/BTRON/device/svga_cons/svga_conslow.c,v 1.1.1.1 2003/02/05 03:56:56 monaka Exp $";


/*
 *
 *
 */

#include "svga_cons.h"
#include "svga_cons_internal.h"

UW	initilized = 0;


/* SVGA_CONS アダプタが存在しているかどうかをチェックする
 */
ER
probe (struct device *dev)
{
  /*** ここに ***/

  return (E_OK);
}


/* 
 * $Log: svga_conslow.c,v $
 * Revision 1.1.1.1  2003/02/05 03:56:56  monaka
 * From eota-0.3.4.tgz
 *
 * Revision 1.1  1999/04/11 14:41:33  kishida0
 * for debug function
 *
 * Revision 1.1  1998/12/19 07:50:25  monaka
 * Pre release version.
 *
 */
