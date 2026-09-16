/*	ITRON にトラップをかけて呼び出す(システムコール)
 *
 */

/* $Header: /Users/tonpa/Downloads/b-free/b-free/kernel/POSIX/libc/call_posix.S,v 1.1.1.1 2003/02/05 03:57:14 monaka Exp $ */
	


.globl	call_lowlib
	


/* call_posix: POSIX システムコールルーチン
 *
 * . スタック形式:
 *
 *		+--------------------+
 *		|    return addr     |	+4
 *		+--------------------+
 *		|    syscall no.     |  +8
 *		+--------------------+
 *		|    argument #1     |  +12
 *		+--------------------+
 *		|    argument #2     |  +16
 *		+--------------------+
 *		|    argument #3     |
 *
 */
call_lowlib:
		pushl 	%ebp
		movl	%esp,%ebp
		movl	8(%ebp), %eax
		leal	12(%ebp), %edx
#if 0
		int	$65
#else
		lcall	$0x38,$0
#endif
		leave
		ret


