/*

B-Free Project の生成物は GNU Generic PUBLIC LICENSE に従います。

GNU GENERAL PUBLIC LICENSE
Version 2, June 1991

(C) B-Free Project.

*/
/*
    $Header: /Users/tonpa/Downloads/b-free/b-free/kernel/POSIX/libc/native/fork.S,v 1.1.1.1 2003/02/05 03:57:15 monaka Exp $
*/

.text
.globl fork

fork:
	movl	%esp,%eax
	pushl	%edi
	pushl	%esi
	pushl	%edx
	pushl	%ecx
	pushl	%ebx
	pushl	%ebp
	pushl	%eax
	call	_fork
	addl	$28,%esp
	ret
