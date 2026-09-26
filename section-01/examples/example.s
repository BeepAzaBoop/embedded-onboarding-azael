	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 15, 0	sdk_version 15, 5
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #64
	stp	x29, x30, [sp, #48]             ; 16-byte Folded Spill
	add	x29, sp, #48
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	stur	wzr, [x29, #-4]
	stur	w0, [x29, #-8]
	stur	x1, [x29, #-16]
	adrp	x0, l_.str@PAGE
	add	x0, x0, l_.str@PAGEOFF
	bl	_printf
	mov	x9, sp
	mov	x8, #7                          ; =0x7
	str	x8, [x9]
	adrp	x0, l_.str.1@PAGE
	add	x0, x0, l_.str.1@PAGEOFF
	bl	_printf
	adrp	x0, l_.str.2@PAGE
	add	x0, x0, l_.str.2@PAGEOFF
	bl	_printf
	ldur	w8, [x29, #-8]
	subs	w8, w8, #1
	b.le	LBB0_6
	b	LBB0_1
LBB0_1:
	ldur	w8, [x29, #-8]
	mov	w9, #1                          ; =0x1
	str	w9, [sp, #24]                   ; 4-byte Folded Spill
	subs	w10, w8, #1
	mov	x9, sp
                                        ; implicit-def: $x8
	mov	x8, x10
	str	x8, [x9]
	adrp	x0, l_.str.3@PAGE
	add	x0, x0, l_.str.3@PAGEOFF
	bl	_printf
	ldr	w8, [sp, #24]                   ; 4-byte Folded Reload
	stur	w8, [x29, #-20]
	b	LBB0_2
LBB0_2:                                 ; =>This Inner Loop Header: Depth=1
	ldur	w8, [x29, #-20]
	ldur	w9, [x29, #-8]
	subs	w8, w8, w9
	b.ge	LBB0_5
	b	LBB0_3
LBB0_3:                                 ;   in Loop: Header=BB0_2 Depth=1
	ldur	w8, [x29, #-20]
	mov	x10, x8
	ldur	x8, [x29, #-16]
	ldursw	x9, [x29, #-20]
	ldr	x8, [x8, x9, lsl #3]
	mov	x9, sp
	str	x10, [x9]
	str	x8, [x9, #8]
	adrp	x0, l_.str.4@PAGE
	add	x0, x0, l_.str.4@PAGEOFF
	bl	_printf
	b	LBB0_4
LBB0_4:                                 ;   in Loop: Header=BB0_2 Depth=1
	ldur	w8, [x29, #-20]
	add	w8, w8, #1
	stur	w8, [x29, #-20]
	b	LBB0_2
LBB0_5:
	b	LBB0_7
LBB0_6:
	adrp	x0, l_.str.5@PAGE
	add	x0, x0, l_.str.5@PAGEOFF
	bl	_printf
	b	LBB0_7
LBB0_7:
	mov	w0, #0                          ; =0x0
	ldp	x29, x30, [sp, #48]             ; 16-byte Folded Reload
	add	sp, sp, #64
	ret
	.cfi_endproc
                                        ; -- End function
	.section	__TEXT,__cstring,cstring_literals
l_.str:                                 ; @.str
	.asciz	"Hello, world!\n"

l_.str.1:                               ; @.str.1
	.asciz	"The sum of 3 and 4 is: %d\n"

l_.str.2:                               ; @.str.2
	.asciz	"Debug mode is disabled.\n"

l_.str.3:                               ; @.str.3
	.asciz	"You provided %d argument(s):\n"

l_.str.4:                               ; @.str.4
	.asciz	"Argument %d: %s\n"

l_.str.5:                               ; @.str.5
	.asciz	"No additional arguments provided.\n"

.subsections_via_symbols
