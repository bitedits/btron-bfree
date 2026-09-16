/*

B-Free Project の生成物は GNU Generic PUBLIC LICENSE に従います。

GNU GENERAL PUBLIC LICENSE
Version 2, June 1991

(C) B-Free Project.

(C) 2001, Tomohide Naniwa

*/
/*
 * 文字列の長さを返す関数群
 */

/* $Header: /Users/tonpa/Downloads/b-free/b-free/kernel/POSIX/libc/string/strlen.c,v 1.1.1.1 2003/02/05 03:57:17 monaka Exp $ */

static char rcsid[] =
    "$Header: /Users/tonpa/Downloads/b-free/b-free/kernel/POSIX/libc/string/strlen.c,v 1.1.1.1 2003/02/05 03:57:17 monaka Exp $";
/* 
 * $Log: strlen.c,v $
 * Revision 1.1.1.1  2003/02/05 03:57:17  monaka
 * From eota-0.3.4.tgz
 *
 * Revision 1.2  2000/02/17 14:29:04  naniwa
 * minor fix on log comment
 *
 * Revision 1.1  2000/01/15 15:26:10  naniwa
 * first version
 *
 */

/*
 * 文字列の長さをバイト単位で返す関数。
 *
 */
int strlen(char *s)
{
    int count;

    for (count = 0; *s++; count++);
    return (count);
}
/*
 * 文字列の長さをバイト単位で返す関数(制限値付き)
 *
 */
int strnlen(char *s, int count)
{
    char *sc;

    for (sc = s; count-- && *sc != '\0'; ++sc);
    return sc - s;
}
