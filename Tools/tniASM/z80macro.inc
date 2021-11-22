; Z80 macros

; carry flag to accumulator
; Cf = 0 -> A =  1
; Cf = 1 -> A = -1
%macro ld a,signed 1 from carry
	sbc	a,a
	sbc	a,-1
%endmacro

; increase with ceiling
%macro inc a,%n
	sub  #1
	adc  a,#1
%endmacro

; decrease with floor
%macro dec a,%n
 	add  a,-#1-1 & 255
 	sbc  a,-#1-1 & 255
%endmacro

; 16 bit index loads
%macro ld bc,[ix%n] \ ld c,[ix+#1] \ ld b,[ix+#1+1] \ %endmacro
%macro ld de,[ix%n] \ ld e,[ix+#1] \ ld d,[ix+#1+1] \ %endmacro
%macro ld hl,[ix%n] \ ld l,[ix+#1] \ ld h,[ix+#1+1] \ %endmacro
%macro ld bc,[iy%n] \ ld c,[iy+#1] \ ld b,[iy+#1+1] \ %endmacro
%macro ld de,[iy%n] \ ld e,[iy+#1] \ ld d,[iy+#1+1] \ %endmacro
%macro ld hl,[iy%n] \ ld l,[iy+#1] \ ld h,[iy+#1+1] \ %endmacro
%macro ld [ix%n],bc \ ld [ix+#1],c \ ld [ix+#1+1],b \ %endmacro
%macro ld [ix%n],de \ ld [ix+#1],e \ ld [ix+#1+1],d \ %endmacro
%macro ld [ix%n],hl \ ld [ix+#1],l \ ld [ix+#1+1],h \ %endmacro
%macro ld [ix%n],word %n \ ld [ix+#1],#2 & FFh \ ld [ix+#1+1],#2 >> 8 \ %endmacro
%macro ld [iy%n],bc \ ld [iy+#1],c \ ld [iy+#1+1],b \ %endmacro
%macro ld [iy%n],de \ ld [iy+#1],e \ ld [iy+#1+1],d \ %endmacro
%macro ld [iy%n],hl \ ld [iy+#1],l \ ld [iy+#1+1],h \ %endmacro
%macro ld [iy%n],word %n \ ld [iy+#1],#2 & FFh \ ld [iy+#1+1],#2 >> 8 \ %endmacro

; 16 bit compare
%macro cp hl,bc
	and	a
	sbc	hl,bc
	add	hl,bc
%endmacro
%macro cp hl,de
	and	a
	sbc	hl,de
	add	hl,de
%endmacro

; 16 bit sub
%macro sub hl,bc
	and	a
	sbc	hl,bc
%endmacro
%macro sub hl,de
	and	a
	sbc	hl,de
%endmacro
%macro sub hl,hl
	and	a
	sbc	hl,hl
%endmacro

; 16 bit register loads
%macro ld bc,de \ ld c,e \ ld b,d \ %endmacro
%macro ld bc,hl \ ld c,l \ ld b,h \ %endmacro
%macro ld de,bc \ ld e,c \ ld d,b \ %endmacro
%macro ld de,hl \ ld e,l \ ld d,h \ %endmacro
%macro ld hl,bc \ ld l,c \ ld h,b \ %endmacro
%macro ld hl,de \ ld l,e \ ld h,d \ %endmacro
%macro ld bc,ix \ ld c,ixl \ ld b,ixh \ %endmacro
%macro ld ix,bc \ ld ixl,c \ ld ixh,b \ %endmacro
%macro ld de,ix \ ld e,ixl \ ld d,ixh \ %endmacro
%macro ld ix,de \ ld ixl,e \ ld ixh,d \ %endmacro
%macro ld bc,iy \ ld c,iyl \ ld b,iyh \ %endmacro
%macro ld iy,bc \ ld iyl,c \ ld iyh,b \ %endmacro
%macro ld de,iy \ ld e,iyl \ ld d,iyh \ %endmacro
%macro ld iy,de \ ld iyl,e \ ld iyh,d \ %endmacro

; 16 bit register shifts
%macro sla bc \ sla c \ rl b \ %endmacro
%macro sla de \ sla e \ rl d \ %endmacro
%macro sla hl \ sla l \ rl h \ %endmacro
%macro sra bc \ sra b \ rr c \ %endmacro
%macro sra de \ sra d \ rr e \ %endmacro
%macro sra hl \ sra h \ rr l \ %endmacro
%macro srl bc \ srl b \ rr c \ %endmacro
%macro srl de \ srl d \ rr e \ %endmacro
%macro srl hl \ srl h \ rr l \ %endmacro

; push previous, pushes value behind the current top of the stack
; note: register is changed to value @ stack-top
%macro pushp hl
	ex	[sp],hl
	push	hl
%endmacro
%macro pushp ix
	ex	[sp],ix
	push	ix
%endmacro
%macro pushp iy
	ex	[sp],iy
	push	iy
%endmacro

; pop previous, pops value from behind the current top of the stack
%macro popp hl
	pop	hl
	ex	[sp],hl
%endmacro
%macro popp ix
	pop	ix
	ex	[sp],ix
%endmacro
%macro popp iy
	pop	iy
	ex	[sp],iy
%endmacro

; open a stack frame with size n, register points to lowest address
%macro frame	hl,%n
	ld	hl,-#1
	add	hl,sp
	ld	sp,hl
%endmacro
%macro frame	ix,%n
	ld	ix,-#1
	add	ix,sp
	ld	sp,ix
%endmacro
%macro frame	iy,%n
	ld	iy,-#1
	add	iy,sp
	ld	sp,iy
%endmacro
%macro frame	hl,de
	ld	hl,0
	and	a
	sbc	hl,de
	add	hl,sp
	ld	sp,hl
%endmacro

; close a stack frame with size n, register points to SP
%macro unframe	hl,%n
	ld	hl,#1
	add	hl,sp
	ld	sp,hl
%endmacro
%macro unframe	ix,%n
	ld	ix,#1
	add	ix,sp
	ld	sp,ix
%endmacro
%macro unframe	iy,%n
	ld	iy,#1
	add	iy,sp
	ld	sp,iy
%endmacro
%macro unframe	hl,de
	ld	l,e
	ld	h,d
	add	hl,sp
	ld	sp,hl
%endmacro

%macro pop null
	inc	sp
	inc	sp
%endmacro

%macro push %n
	push	hl
	ld	hl,#1
	ex	[sp],hl
%endmacro

%macro pop [%n]
	ex	[sp],hl
	ld	[#1],hl
	pop	hl
%endmacro

%macro push [%n]
	push	hl
	ld	hl,[#1]
	ex	[sp],hl
%endmacro

; sign-extend
%macro exts hl
	ld	l,a
	rlca
	sbc	a,a
	ld	h,a
%endmacro
%macro exts de
	ld	e,a
	rlca
	sbc	a,a
	ld	d,a
%endmacro
%macro exts bc
	ld	c,a
	rlca
	sbc	a,a
	ld	b,a
%endmacro
%macro exts ix
	ld	ixl,a
	rlca
	sbc	a,a
	ld	ixh,a
%endmacro
%macro exts iy
	ld	iyl,a
	rlca
	sbc	a,a
	ld	iyh,a
%endmacro

; 16 bit neg
%macro neg hl
	xor	a
	sub	l
	ld	l,a
	sbc	a,a
	sub	h
	ld	h,a
%endmacro
%macro neg de
	xor	a
	sub	e
	ld	e,a
	sbc	a,a
	sub	d
	ld	d,a
%endmacro
%macro neg bc
	xor	a
	sub	c
	ld	c,a
	sbc	a,a
	sub	b
	ld	b,a
%endmacro
%macro neg ix
	xor	a
	sub	ixl
	ld	ixl,a
	sbc	a,a
	sub	ixh
	ld	ixh,a
%endmacro
%macro neg iy
	xor	a
	sub	iyl
	ld	iyl,a
	sbc	a,a
	sub	iyh
	ld	iyh,a
%endmacro

; conditional jumps for signed operations: (not) less
%macro jp nl,%n
	jp	p,.#p
	jp	po,#1
	jr	.#l
.#p:	jp	pe,#1
.#l:
%endmacro

%macro jp l,%n
	jp	p,.#p
	jp	pe,#1
	jr	.#nl
.#p:	jp	po,#1
.#nl:
%endmacro
