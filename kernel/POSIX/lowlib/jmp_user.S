/* $Header: /Users/tonpa/Downloads/b-free/b-free/kernel/POSIX/lowlib/jmp_user.S,v 1.1.1.1 2003/02/05 03:57:17 monaka Exp $ */

/*
 * POSIX 環境 on B-Free 
 */


.globl jmp_user_entry

/*
 * ユーザモードに遷移しつつ、指定したエントリアドレスへジャンプする
 */
jmp_user_entry:
	
	ret