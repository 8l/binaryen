	.text
	.file	"/b/build/slave/linux/build/src/buildbot/work/gcc/gcc/testsuite/gcc.c-torture/execute/pr21964-1.c"
	.globl	foo
	.type	foo,@function
foo:                                    # @foo
	.param  	i32, i32
# BB#0:                                 # %entry
	block   	BB0_3
	i32.const	$push1=, 0
	i32.eq  	$push2=, $1, $pop1
	br_if   	$pop2, BB0_3
# BB#1:                                 # %entry
	i32.const	$push3=, 0
	i32.eq  	$push4=, $0, $pop3
	br_if   	$pop4, BB0_3
# BB#2:                                 # %if.then2.split
	call    	abort
	unreachable
BB0_3:                                  # %if.then
	i32.const	$push0=, 0
	call    	exit, $pop0
	unreachable
func_end0:
	.size	foo, func_end0-foo

	.globl	main
	.type	main,@function
main:                                   # @main
	.result 	i32
# BB#0:                                 # %entry
	i32.const	$push0=, 0
	call    	exit, $pop0
	unreachable
func_end1:
	.size	main, func_end1-main


	.ident	"clang version 3.8.0 "
	.section	".note.GNU-stack","",@progbits