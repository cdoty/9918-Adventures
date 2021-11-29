; #######################################################################################################################################

; apLib decruncher for the PC-Engine
; /Mic, 2010
;
; Assembles with wla-dx
;
; Example (decrunching packed_data into RAM at $2200):
;
;	lda		#<packed_data
;	sta		<APLIB_SRC
;	lda		#>packed_data
;	sta		<APLIB_SRC+1
;	lda		#$00
;	sta		<APLIB_DEST
;	lda		#$22
;	sta		<APLIB_DEST+1
;	jsr		aplib_decrunch
;
;
; Decruncher footprint: 272-307 bytes ROM, 19 bytes RAM (zp)

; #######################################################################################################################################

; Base address for the zeropage variables used by the decruncher 
.DEFINE APLIB_ZP_BASE $2010

; Uncomment the next line if you want to get information about the number of bytes that were output by the
; decruncher (unsigned 16-bit stored in APLIB_NUMBYTES) (adds 18 bytes to the decruncher).
;.DEFINE APLIB_REPORT_NUMBYTES 

; Uncomment the next line if you want to use the faster (but larger) gamma decoding routine (adds 17 bytes
; to the decruncher)
;.DEFINE APLIB_FAST_GAMMA_DECODER


; Zeropage variables
.EQU APLIB_TII		APLIB_ZP_BASE+$00
.EQU APLIB_SRC2		APLIB_ZP_BASE+$01
.EQU APLIB_DEST		APLIB_ZP_BASE+$03
.EQU APLIB_GAMMA	APLIB_ZP_BASE+$05
.EQU APLIB_JMP		APLIB_ZP_BASE+$07
.EQU APLIB_SRC		APLIB_ZP_BASE+$0A
.EQU APLIB_OFFS		APLIB_ZP_BASE+$0C
.EQU APLIB_OFFS2	APLIB_ZP_BASE+$0E
.EQU APLIB_BITS		APLIB_ZP_BASE+$10
.EQU APLIB_OLDDEST	APLIB_ZP_BASE+$11
.EQU APLIB_NUMBYTES	APLIB_ZP_BASE+$03	; Re-use the space used for DEST


; #######################################################################################################################################

; Increase a 16-bit zeropage variable
.macro apl_inc16_zp 
	inc	<\1		;6
	bne	+		;2/4
	inc	<\1+1	;6 (=10/14)
 	+:
 .endm ; 6 bytes


; Decrease a 16-bit zeropage variable
.macro apl_dec16_zp 
	lda	<\1		;4
	bne	+		;2/4
	dec	<\1+1	;6
 	+:
 	dec	<\1		;6 (=14/18)
 .endm ; 8 bytes
 

.macro apl_mov16_zp 
	lda 	<\2
	sta 	<\1
	lda 	<\2+1
	sta 	<\1+1
 .endm ; 8 bytes
 
; #######################################################################################################################################
 
	
; In:
; APLIB_SRC = source address
; APLIB_DEST = dest address
;
; Out:
; APLIB_NUMBYTES = uncompressed size in bytes
;
aplib_decrunch:
	; Setup code in zeropage RAM
	lda		#$73				; Opcode for 'tii'
	sta		<APLIB_TII
	tii		_ad_jump,APLIB_JMP,3
	
	.IFDEF APLIB_REPORT_NUMBYTES	
	apl_mov16_zp APLIB_OLDDEST,APLIB_DEST
	.ENDIF

	stz		<APLIB_OFFS+1
	clx							; LWM
	ldy		#1					; BITCOUNT
_ad_copy_byte:
	jsr		_ad_read_byte
_ad_write_byte:
	sta		(<APLIB_DEST)
	apl_inc16_zp APLIB_DEST
_ad_next_sequence_init:
	clx
_ad_next_sequence:
	bsr		_ad_get_bit
	bcc		_ad_copy_byte		; if bit sequence is %0..., then copy next byte
	bsr		_ad_get_bit
	bcc 	_ad_code_pair		; if bit sequence is %10..., then is a code pair
	bsr		_ad_get_bit
	stz		<APLIB_OFFS
	stz		<APLIB_OFFS+1
	bcs		+
	jmp		_ad_short_match		; if bit sequence is %110..., then is a short match
+:
	; The sequence is %111..., the next 4 bits are the offset (0-15)
   	phx
   	ldx #4
-:
	bsr		_ad_get_bit
	rol		<APLIB_OFFS
   	dex
   	bne 	-
   	plx
	lda		<APLIB_OFFS
	beq		_ad_write_byte		; if offset == 0, then write 0x00
	; If offset != 0, then write the byte at destination - offset
	jsr		_ad_calc_src2
	lda		(<APLIB_SRC2)
	bra 	_ad_write_byte

; get_bit: Get bits from the crunched data and insert the most significant bit in the carry flag.
_ad_get_bit:
	dey							; 2
	bne		_ad_still_bits_left	; 2/4
	ldy		#8					; 2
	jsr		_ad_read_byte
	sta		<APLIB_BITS			; 4
_ad_still_bits_left:
	asl		<APLIB_BITS			; 6
	rts							; 7 

	; Code pair %10...
_ad_code_pair:
	jsr		_ad_decode_gamma
	; GAMMA -= 2
	lda		<APLIB_GAMMA
	sec
	sbc		#2
	sta		<APLIB_GAMMA
	lda		<APLIB_GAMMA+1
	sbc		#0
	sta		<APLIB_GAMMA+1
	ora		<APLIB_GAMMA	
	bne		_ad_normal_code_pair
	txa
	bne		_ad_normal_code_pair
	bsr		_ad_decode_gamma
	apl_mov16_zp APLIB_OFFS,APLIB_OFFS2
	jmp		_ad_copy_code_pair
	
_ad_normal_code_pair:
	txa							;2
	bne 	+					;2/4
	lda		<APLIB_GAMMA		;4
	bne		++					;2/4
	dec		<APLIB_GAMMA+1		;6
 	++:					
 	dec		<APLIB_GAMMA		;6 (=6/18/22)	
+:
	lda		<APLIB_GAMMA
	sta		<APLIB_OFFS+1
	jsr		_ad_read_byte
	sta		<APLIB_OFFS
	bsr		_ad_decode_gamma
	lda		<APLIB_OFFS+1
	phx
	clx
	cmp		#$7D				; OFFS >= 32000 ?
	bcc		_ad_compare_1280
   	inx
_ad_compare_1280:
	cmp		#$05				; OFFS >= 1280 ?
	bcc		_ad_compare_128
   	inx	
	bra _ad_update_gamma
_ad_compare_128:
	cmp		#1
	bcs		+ 
	lda		<APLIB_OFFS
	cmp		#128				; OFFS < 128 ?
	bcs		+ 
   	inx
   	inx
_ad_update_gamma:
   	txa
   	clc
   	adc 	<APLIB_GAMMA
   	sta 	<APLIB_GAMMA
   	cla
   	adc 	<APLIB_GAMMA+1
   	sta 	<APLIB_GAMMA+1
+:
   	plx	
	bra		_ad_continue_short_match

_ad_read_byte:
	lda		(<APLIB_SRC)
	apl_inc16_zp APLIB_SRC
	rts
	
; decode_gamma: Decode values from the crunched data using gamma code
_ad_decode_gamma:
	bsr		_ad_init_gamma
_ad_get_more_gamma:
	.IFDEF APLIB_FAST_GAMMA_DECODER
	cpy		#3					; 2
	bcc		+					; 2/4
	dey							; 2
	dey							; 2
	asl		<APLIB_BITS			; 6
	rol		<APLIB_GAMMA		; 6
	rol		<APLIB_GAMMA+1		; 6
	asl		<APLIB_BITS			; 6
	bcs		_ad_get_more_gamma	; 2/4 
	rts	
+:
	.ENDIF
	jsr		_ad_get_bit			; 7 + 19/40/44
	rol		<APLIB_GAMMA		; 6
	rol		<APLIB_GAMMA+1		; 6
	jsr		_ad_get_bit			; 7 + 19/40/44
	bcs		_ad_get_more_gamma	; 2/4
	rts

_ad_init_gamma:
	lda		#1
	sta		<APLIB_GAMMA
	stz		<APLIB_GAMMA+1
	rts

; Short match %110...
_ad_short_match:  
	bsr		_ad_init_gamma
	bsr		_ad_read_byte
	lsr		a
	beq		_ad_end_decrunch
	rol		<APLIB_GAMMA
	sta		<APLIB_OFFS
	stz		<APLIB_OFFS+1
_ad_continue_short_match:
	apl_mov16_zp APLIB_OFFS2,APLIB_OFFS
_ad_copy_code_pair:
	; Overwrite source for the TII instruction in RAM 
	bsr		_ad_calc_src2
	jmp		APLIB_TII
_ad_after_copy:
	; DEST += GAMMA
	ldx		#<APLIB_DEST
	clc
	set
	adc		<APLIB_GAMMA
	inx
	set
	adc		<APLIB_GAMMA+1
	ldx		#1
	jmp		_ad_next_sequence
_ad_end_decrunch:
	.IFDEF APLIB_REPORT_NUMBYTES
	ldx		#<APLIB_DEST
	sec
	set
	sbc		<APLIB_OLDDEST
	inx
	set
	sbc		<APLIB_OLDDEST+1
	.ENDIF
	rts
_ad_jump:
	jmp 	_ad_after_copy
_ad_calc_src2:
	lda		<APLIB_DEST
 	sec
 	sbc		<APLIB_OFFS
 	sta		<APLIB_SRC2
 	lda		<APLIB_DEST+1
 	sbc		<APLIB_OFFS+1
 	sta		<APLIB_SRC2+1
	rts	


