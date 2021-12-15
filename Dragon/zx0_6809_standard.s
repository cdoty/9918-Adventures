; zx0_6809_standard.asm - ZX0 decompressor for M6809 - 109 bytes
;
; Copyright (c) 2021 Doug Masten
; ZX0 compression (c) 2021 Einar Saukas, https://github.com/einar-saukas/ZX0
;
; This software is provided 'as-is', without any express or implied
; warranty. In no event will the authors be held liable for any damages
; arising from the use of this software.
;
; Permission is granted to anyone to use this software for any purpose,
; including commercial applications, and to alter it and redistribute it
; freely, subject to the following restrictions:
;
; 1. The origin of this software must not be misrepresented; you must not
;    claim that you wrote the original software. If you use this software
;    in a product, an acknowledgment in the product documentation would be
;    appreciated but is not required.
; 2. Altered source versions must be plainly marked as such, and must not be
;    misrepresented as being the original software.
; 3. This notice may not be removed or altered from any source distribution.

;------------------------------------------------------------------------------
; Function    : zx0_decompress
; Entry       : Reg X = start of compressed data
;             : Reg U = start of decompression buffer
; Exit        : Reg X = end of compressed data + 1
;             : Reg U = end of decompression buffer + 1
; Destroys    : Regs D, Y
; Description : Decompress ZX0 data (version 1)
zx0_decompress:
	ldd		#$ffff
	std		zx0_offset+2		; init offset = -1
	lda		#$80
	sta		zx0_bit				; init bit stream

; 0 - literal (copy next N bytes from compressed data)
zx0_literals:
	bsr		zx0_elias			; obtain length
	tfr		d, y				;  "      "
zx0_literals_loop:
	ldb		, x+				; copy literals
	stb		, u+				;  "    "
	
	leay	-1, y				; decrement loop counter
	bne		zx0_literals_loop	; loop until done
	
	lsl		zx0_bit				; get next bit
	bcs		zx0_new_offset		; branch if next block is new-offset

; 0 - copy from last offset (repeat N bytes from last offset)
	bsr		zx0_elias       	; obtain length

zx0_copy:
	pshs	x					; save reg X
	
	tfr		d, x				; setup length

zx0_offset:
	leay	>$ffff, u			; calculate offset address

zx0_offset_loop:
	ldb		, y+				; copy match
	stb		, u+				;  "    "
	leax	-1, x				; decrement loop counter
	bne		zx0_offset_loop		; loop until done
	
	puls	x					; restore reg X
	
	lsl		zx0_bit				; get next bit
	bcc		zx0_literals		; branch if next block is literals

; 1 - copy from new offset (repeat N bytes from new offset)
zx0_new_offset:
	bsr		zx0_elias			; obtain offset MSB
	negb						; adjust for negative offset (set carry for RORA below)
	beq		zx0_eof				; eof? (length = 256) if so exit
	tfr		b, a				; transfer to MSB position
	ldb		, x+				; obtain LSB offset
	rora						; last offset bit becomes first length bit
	rorb						;  "     "     "    "      "     "      "
	std		zx0_offset+2		; preserve new offset
	ldd		#1					; set elias = 1
	bcs		zx0_new_offset_skip	; test first length bit
	bsr		zx0_backtrace		; get elias but skip first bit

zx0_new_offset_skip:
	incb						; elias = elias + 1
	bne		zx0_copy			; if no carryover, branch to copy new offset match
	
	inca						; increment MSB elias carryover
	bra		zx0_copy			; copy new offset match

; interlaced elias gamma coding
zx0_elias:
	ldd		#1					; set elias = 1
	bra		zx0_backtrace_start	; goto start of elias gamma coding

zx0_backtrace:
zx0_backtrace_loop:
	lsl		zx0_bit				; get next bit
	rolb						; rotate elias value
	rola						;   "     "     "

zx0_backtrace_start:
	lsl		zx0_bit				; get next bit
	bne		zx0_backtrace_skip	; branch if bit stream is not empty
	
	pshs	a					; save reg A
	
	lda		, x+				; load another 8-bits
	rola						; get next bit
	sta		zx0_bit				; save bit stream
	
	puls	a					; restore reg A

zx0_backtrace_skip:
	bcc		zx0_backtrace_loop	; loop until done

zx0_eof:
	rts							; return


; bit stream
zx0_bit:
	fcb	$80
