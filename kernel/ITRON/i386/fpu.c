/*

B-Free Project の生成物は GNU Generic PUBLIC LICENSE に従います。

GNU GENERAL PUBLIC LICENSE
Version 2, June 1991

(C) B-Free Project.

*/
/*
 * $Log: fpu.c,v $
 * Revision 1.1.1.1  2003/02/05 03:57:11  monaka
 * From eota-0.3.4.tgz
 *
 *
 */

#include "itron.h"
#include "func.h"
#include "task.h"

void fpu_save(T_TCB *taskp)
{
  __asm__("fsave %0" : "=m" (taskp->fpu_context));
}

void fpu_restore(T_TCB *taskp)
{
  __asm__("frstor %0" : "=m" (taskp->fpu_context));
}

void fpu_start(T_TCB *taskp)
{
  if (taskp->use_fpu) return;
  dis_int();
  if (run_task == taskp) {
    __asm__("finit");
    __asm__("fsave %0" : "=m" (taskp->fpu_context));
    taskp->use_fpu = 1;
  }
  else {
    if (run_task->use_fpu) {
      __asm__("fsave %0" : "=m" (run_task->fpu_context));
    }
    __asm__("finit");
    __asm__("fsave %0" : "=m" (taskp->fpu_context));
    if (run_task->use_fpu) {
      __asm__("frstor %0" : "=m" (run_task->fpu_context));
    }
    taskp->use_fpu = 1;
  }
  ena_int();
}
