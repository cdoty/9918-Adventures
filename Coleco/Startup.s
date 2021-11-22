%org	ROMStart

%def16	AA55h		; Boot right to cart
;%def16	55AAh		; Display logo screen
%def16	SpriteTable	; Sprite table
%def16	SpriteOrder	; Sprite order table
%def16	WorkBuffer	; Work buffer
%def8	0			; Disable joystick 1 polling
%def8	0			; Disable joystick 2 polling
%def16	start		; Start of code

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
	jp	NMIHandler
	
%def8	"BURGER INVADERS/PRESENTS/2020"	; Cartridge title

start:
	call	1FD6h		; Disable sound
	call	setMode2	; Set mode 2
	call	clearVRAM	; Clear VRAM
	call	showTitle	; Show title
	call	startGame	; Start game
	
endlessLoop:
	jp		endlessLoop
	