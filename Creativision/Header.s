	* = $BFE8
	
	!16	start	; Start address
	!16	$FF52	; IRQ address
	
	!fill	4, $FF
	
	; VDP Setup: Graphics Mode 2
	!8	$02	; Disable external VDP interrupt, set M2 for Graphics mode 2
	!8	$A2	; Enable 16K VRAM, Screen Off, NMI interrupt, and 16x16 sprites
	!8	$0E	; Set Name Table location to 3800h, in VRAM
	!8	$FF	; Set Color Table location to 2000h, in VRAM
	!8	$03	; Set Pattern Table location to 0000h, in VRAM
	!8	$76	; Set Sprite Attribute Table location to 3B00h, in VRAM
	!8	$03	; Set Sprite Pattern Table location to 1800h, in VRAM
	!8	$00	; Set background color to black
	
	!fill	4, $FF
	
	!16	$F808	; Reset
	!16	irq		; BIOS NMI address
	