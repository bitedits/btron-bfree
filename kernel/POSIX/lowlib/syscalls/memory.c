/*

B-Free Project の生成物は GNU Generic PUBLIC LICENSE に従います。

GNU GENERAL PUBLIC LICENSE
Version 2, June 1991

(C) B-Free Project.

(C) 2002, Tomohide Naniwa

*/
/* $Header: /Users/tonpa/Downloads/b-free/b-free/kernel/POSIX/lowlib/syscalls/memory.c,v 1.1.1.1 2003/02/05 03:57:17 monaka Exp $ */
static char rcsid[] =
    "@(#)$Header: /Users/tonpa/Downloads/b-free/b-free/kernel/POSIX/lowlib/syscalls/memory.c,v 1.1.1.1 2003/02/05 03:57:17 monaka Exp $";

/*
 * $Log: memory.c,v $
 * Revision 1.1.1.1  2003/02/05 03:57:17  monaka
 * From eota-0.3.4.tgz
 *
 * Revision 1.1  1997/08/31 13:10:46  night
 * 最初の登録
 *
 *
 *
 */


#include "../lowlib.h"

int psys_memory(void *argp)
{
#ifdef notdef
    struct a {
	/* ここに引数の定義を入れる */
    } *args = (struct a *) argp;
#endif

    /*
     * まだインプリメントしていない。ENOSYS を返す。
     */
    errno = ENOSYS;

    return (NULL);
}
