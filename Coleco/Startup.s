	ORG		ROMStart

	ifdef	DISPLAY_COLECO_LOGO
	dw	55AAh			; Display logo screen
	else	
	dw	0AA55h			; Boot right to cart
	endif
	dw	Ram.SpriteTable	; Sprite table
	dw	Ram.SpriteOrder	; Sprite order table
	dw	Ram.WorkBuffer	; Work buffer
	db	0				; Disable joystick 1 polling
	db	0				; Disable joystick 2 polling
	dw	start			; Start of code

RST8H:
	reti
	nop

RST10H:
	reti
	nop

RST18H:
	reti
	nop

RST20H:
	reti
	nop

RST28H:
	reti
	nop

RST30H:
	reti
	nop

IRQ:
	reti
	nop

NMI:
	jp		NMIHandler
	
	db	"BURGER INVADERS/PRESENTS/2020"	; Cartridge title

start:
	call	1FD6h		; Disable sound
	call	setMode2	; Set mode 2
	call	clearVRAM	; Clear VRAM

	call	showTitle	; Show title
	call	startGame	; Start game
	
endlessLoop:
	jp		endlessLoop
	