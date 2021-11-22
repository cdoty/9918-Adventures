; #######################################################################################################################################

; apLib decruncher for the NES (VRAM version)
; /Mic, 2010
;
; Assembles with NESASM
;
; Example (decrunching packed_data into VRAM at $2400):
;
;	lda		#(packed_data % 256)
;	sta		<APLIB_SRC
;	lda		#(packed_data / 256)
;	sta		<APLIB_SRC+1
;	lda		#$00
;	sta		<APLIB_DEST
;	lda		#$24
;	sta		<APLIB_DEST+1
;	jsr		aplib_decrunch_vram
;

; #######################################################################################################################################

; Zeropage variables
	APLIB_LWM 		= $10
	APLIB_BITS 		= $12
	APLIB_BITCOUNT 	= $13
	APLIB_OFFS 		= $14
	APLIB_OFFS2 	= $16
	APLIB_GAMMA 	= $18
	APLIB_SRC 		= $1A
	APLIB_DEST 		= $1C
	APLIB_SRC2 		= $1E

; #######################################################################################################################################

; Increase a 16-bit zeropage variable
!macro apl_inc16_zp .zpAddress {
	inc+1	.zpAddress
	bne		.x
	inc+1	.zpAddress+1
.x:
}

; Decrease a 16-bit zeropage variable
!macro apl_dec16_zp .zpAddress {
	lda+1	.zpAddress
	bne		.x
	dec+1	.zpAddress+1
.x:
 	dec+1	.zpAddress
}

; Add an 8-bit zeropage variable to a 16-bit zeropage variable
!macro apl_add16_8_zp .zpAddress, .address {
	lda 	.zpAddress
	clc
 	adc 	.address
 	sta 	.zpAddress
 	rol		.zpAddress+1
}

; Subtract one zeropage variable from another
!macro apl_sub16_zp .zpAddress, .address {
	lda 	.zpAddress
 	sec
 	sbc 	.address
 	sta 	.zpAddress
 	lda 	.zpAddress+1
 	sbc 	.zpAddress+1
 	sta 	.zpAddress+1
}

!macro apl_mov16_zp .address, .zpAddress {
	lda+1 	.zpAddress
	sta 	.address
	lda+1 	.zpAddress+1
	sta 	.address+1
}

!macro apl_set_vram_addr .address {
 	lda 	#.address / 256
 	sta 	$2006
 	lda 	#.address % 256
 	sta 	$2006
}
 
; #######################################################################################################################################
 	
; In:
; APLIB_SRC = source address
; APLIB_DEST = vram address
;
; b2 of $2000 should be cleared to give single-byte increments after each VRAM access
;
decompressToVRAM:
	; Skip the 24-byte header added by appack
	lda 	<APLIB_SRC
	clc
 	adc 	#24
 	sta 	<APLIB_SRC
 	lda 	<APLIB_SRC+1
 	adc 	#0
 	sta 	<APLIB_SRC+1
 	
	lda 	#0
	sta 	<APLIB_OFFS+1
	sta		<APLIB_LWM+1
	lda		#1
	sta		<APLIB_BITCOUNT
	ldy		#0
	+apl_set_vram_addr APLIB_DEST	
_adv_copy_byte:
	lda		(APLIB_SRC),y
	sta		$2007
	+apl_inc16_zp APLIB_SRC
	+apl_inc16_zp APLIB_DEST
_adv_next_sequence_init:
	lda		#0
	sta		<APLIB_LWM
_adv_next_sequence:
	jsr		_adv_get_bit
	bcc		_adv_copy_byte		; if bit sequence is %0..., then copy next byte
	jsr		_adv_get_bit
	bcc 	_adv_code_pair		; if bit sequence is %10..., then is a code pair
	jsr		_adv_get_bit
	lda		#0
	sta		<APLIB_OFFS
	sta		<APLIB_OFFS+1
	bcs		_adv_skip_jmp
	jmp		_adv_short_match		; if bit sequence is %110..., then is a short match
_adv_skip_jmp:
	; The sequence is %111..., the next 4 bits are the offset (0-15)
	jsr		_adv_get_bit
	rol		<APLIB_OFFS
	jsr		_adv_get_bit
	rol		<APLIB_OFFS
	jsr		_adv_get_bit
	rol		<APLIB_OFFS
	jsr		_adv_get_bit
	rol		<APLIB_OFFS
	lda		<APLIB_OFFS
	beq		_adv_write_byte		; if offset == 0, then write 0x00
	
	; If offset != 0, then write the byte at destination - offset
	+apl_mov16_zp APLIB_SRC2,APLIB_DEST
	+apl_sub16_zp APLIB_SRC2,APLIB_OFFS
	+apl_set_vram_addr APLIB_SRC2
	lda		$2007				; dummy read
	lda		$2007
	pha
	+apl_set_vram_addr APLIB_DEST
	pla
_adv_write_byte:
	sta		$2007
	+apl_inc16_zp APLIB_DEST
	jmp		_adv_next_sequence_init

	; Code pair %10...
_adv_code_pair:
	jsr		_adv_decode_gamma
	+apl_dec16_zp APLIB_GAMMA
	+apl_dec16_zp APLIB_GAMMA
	lda		<APLIB_GAMMA
	ora		<APLIB_GAMMA+1
	bne		_adv_normal_code_pair
	lda		APLIB_LWM
	bne		_adv_normal_code_pair
	jsr		_adv_decode_gamma
	+apl_mov16_zp APLIB_OFFS,APLIB_OFFS2
	jmp		_adv_copy_code_pair
_adv_normal_code_pair:
	+apl_add16_8_zp APLIB_GAMMA,APLIB_LWM
	+apl_dec16_zp APLIB_GAMMA
	lda		<APLIB_GAMMA
	sta		<APLIB_OFFS+1
	lda		(APLIB_SRC),y
	sta		<APLIB_OFFS
	+apl_inc16_zp APLIB_SRC
	jsr		_adv_decode_gamma
	lda		<APLIB_OFFS+1
	cmp		#$7D					; OFFS >= 32000 ?
	bcc		_adv_compare_1280
	+apl_inc16_zp APLIB_GAMMA
_adv_compare_1280:
	cmp		#$05					; OFFS >= 1280 ?
	bcc		_adv_compare_128
	+apl_inc16_zp APLIB_GAMMA
	jmp		_adv_continue_short_match
_adv_compare_128:
	cmp		#1
	bcs		_adv_continue_short_match
	lda		<APLIB_OFFS
	cmp		#128					; OFFS < 128 ?
	bcs		_adv_continue_short_match
	+apl_inc16_zp APLIB_GAMMA
	+apl_inc16_zp APLIB_GAMMA
	jmp		_adv_continue_short_match
	
; get_bit: Get bits from the crunched data and insert the most significant bit in the carry flag.
_adv_get_bit:
	dec		<APLIB_BITCOUNT
	bne		_adv_still_bits_left
	lda		#8
	sta		<APLIB_BITCOUNT
	lda		(APLIB_SRC),y
	sta		<APLIB_BITS
	+apl_inc16_zp APLIB_SRC
_adv_still_bits_left:
	asl		<APLIB_BITS
	rts

; decode_gamma: Decode values from the crunched data using gamma code
_adv_decode_gamma:
	lda		#1
	sta		<APLIB_GAMMA
	lda		#0
	sta		<APLIB_GAMMA+1
_adv_get_more_gamma:
	jsr		_adv_get_bit
	rol		<APLIB_GAMMA
	rol		<APLIB_GAMMA+1
	jsr		_adv_get_bit
	bcs		_adv_get_more_gamma
	rts

; Short match %110...
_adv_short_match:  
	lda		#1
	sta		<APLIB_GAMMA
	lda		#0
	sta		<APLIB_GAMMA+1
	lda		(APLIB_SRC),y	; Get offset (offset is 7 bits + 1 bit to mark if copy 2 or 3 bytes) 
	+apl_inc16_zp APLIB_SRC
	lsr
	bne		_adv_not_done
	jmp		_adv_end_decrunch
_adv_not_done:
	rol		<APLIB_GAMMA
	sta		<APLIB_OFFS
	lda		#0
	sta		<APLIB_OFFS+1
_adv_continue_short_match:
	+apl_mov16_zp APLIB_OFFS2,APLIB_OFFS
_adv_copy_code_pair:
	+apl_mov16_zp APLIB_SRC2,APLIB_DEST
	+apl_sub16_zp APLIB_SRC2,APLIB_OFFS
	tya
	pha
	lda		<APLIB_GAMMA+1
	beq		_adv_short_copy
_adv_loop_do_copy:
	+apl_set_vram_addr APLIB_SRC2
	lda		$2007			; dummy read
	ldy 	$2007
	+apl_set_vram_addr APLIB_DEST
	sty		$2007
	+apl_inc16_zp APLIB_SRC2
	+apl_inc16_zp APLIB_DEST
	+apl_dec16_zp APLIB_GAMMA
	lda		<APLIB_GAMMA
	ora		<APLIB_GAMMA+1
	bne		_adv_loop_do_copy	
	jmp		_adv_next
_adv_short_copy:
	ldx		<APLIB_GAMMA
_adv_short_loop_do_copy:
	+apl_set_vram_addr APLIB_SRC2
	lda		$2007			; dummy read
	ldy 	$2007
	+apl_set_vram_addr APLIB_DEST
	sty		$2007
	+apl_inc16_zp APLIB_SRC2
	+apl_inc16_zp APLIB_DEST
	dex
	bne		_adv_short_loop_do_copy
_adv_next:
	pla
	tay
	lda		#1
	sta		<APLIB_LWM
	jmp		_adv_next_sequence
	
_adv_end_decrunch:
	rts
	