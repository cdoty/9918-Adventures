	* = $BFE8
	
	!16	start	; Start address
	!16	irq		; IRQ address
	
	!fill	4, $FF
	
	; VDP Setup: Graphics Mode 2
	!8	$02							; Disable external VDP interrupt, set M2 for Graphics mode 2.
	!8	$82							; Enable 16K VRAM, Screen Off, and 16x16 sprites. Disable NMI interrupt.
	!8	ScreenVRAM / $400			; Set Name Table location, in VRAM.
	!8	(Color1VRAM / $40) | $7F	; Set Color Table location, in VRAM.
	!8	(Tile1VRAM / $800) | 3		; Set Pattern Table location, in VRAM.
	!8	SpriteAttributes / $80		; Set Sprite Attribute Table location, in VRAM.
	!8	SpritePattern / $800		; Set Sprite Pattern Table location, in VRAM.
	!8	$00							; Set background color to black.
	
	!fill	4, $FF
	
	!16	$F808	; Reset
	!16	nmi		; BIOS NMI address
	