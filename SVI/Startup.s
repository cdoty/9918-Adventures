	org	ROMStart

	di	

	ld	sp, StackStart	; Set stack pointer

	jr	start
	
	block	0008h-$	; Pad to 0008h

RST8H:
	jp	DefaultHandler

	block  10h-$	; Pad to 0010h

RST10H:
	jp	DefaultHandler

	block	18h-$	; Pad to 0018h

RST18H:
	jp	DefaultHandler

	block	20h-$	; Pad to 0020h

RST20H:
   	jp	DefaultHandler

	block	28h-$	; Pad to 0028h

RST28H:
	jp	DefaultHandler

	block	30h-$	; Pad to 0030h

RST30H:
	jp	DefaultHandler

	block	38h-$	; Pad to 0038h

NMI:
	jp	NMIHandler

	block	40h-$	; Pad to 0040h

start:
	xor		a			; Clear RAM
	
	ld		hl, RAMStart
	ld		(hl), a
	
	ld		de, RAMStart + 1
	ld		bc,	RAMSize
	
	ldir

	call	delay		; Delay the start
	call	setMode2	; Set mode 2
	call	clearVRAM	; Clear VRAM
	
	im		1

	ei
	
	call	showTitle	; Show title
	call	startGame	; Start game

endlessLoop:
	jp		endlessLoop
