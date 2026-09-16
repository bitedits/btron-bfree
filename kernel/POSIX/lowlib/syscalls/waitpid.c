/*

B-Free Project の生成物は GNU Generic PUBLIC LICENSE に従います。

GNU GENERAL PUBLIC LICENSE
Version 2, June 1991

(C) B-Free Project.

(C) 2002, Tomohide Naniwa

*/
/* $Header: /Users/tonpa/Downloads/b-free/b-free/kernel/POSIX/lowlib/syscalls/waitpid.c,v 1.1.1.1 2003/02/05 03:57:17 monaka Exp $ */
static char rcsid[] =
    "@(#)$Header: /Users/tonpa/Downloads/b-free/b-free/kernel/POSIX/lowlib/syscalls/waitpid.c,v 1.1.1.1 2003/02/05 03:57:17 monaka Exp $";

/*
 * $Log: waitpid.c,v $
 * Revision 1.1.1.1  2003/02/05 03:57:17  monaka
 * From eota-0.3.4.tgz
 *
 * Revision 1.3  1999/07/21 15:07:19  naniwa
 * implemented
 *
 * Revision 1.2  1999/03/21 00:58:31  monaka
 * Major fix. Many system calls runs correctly (...perhaps ;-). But signal and process functions are not yet.
 *
 * Revision 1.1  1997/08/31 13:10:51  night
 * 最初の登録
 *
 *
 *
 */


#include "../lowlib.h"

int psys_waitpid(void *argp)
{
    ER error;
    struct posix_request req;
    struct posix_response res;
    struct psc_waitpid *args = (struct psc_waitpid *) argp;

    req.param.par_waitpid.pid = args->pid;
    req.param.par_waitpid.statloc = args->statloc;
    req.param.par_waitpid.opts = args->opts;

    error = _make_connection(PSC_WAITPID, &req, &res);
    if (error != E_OK) {
	/* What should I do? */
    }
    else if (res.errno) {
	ERRNO = res.errno;
	return (-1);
    }

    if (args->statloc != NULL)
	*(args->statloc) = res.ret1;
    return (res.status);
}
