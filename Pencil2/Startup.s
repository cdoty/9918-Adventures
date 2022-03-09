	org	ROMStart

	db	"COPYRIGHT SOUNDIC"	; Boot message

	jp	start				; Start of code
	jp	NMIHandler
	jp	RST08H
	jp	RST10H
	jp	RST18H
	jp	RST20H
	jp	RST28H
	jp	RST30H
	jp	IM1Handler
	
	db   8034h-$, 0							; Pad to 8034h
	db	"RASTERSOFT!BURGER INVADERS!2020"	; Cartridge title
	db	0

RST08H:
	ret

RST10H:
	ret

RST18H:
	ret

RST20H:
	ret

RST28H:
	ret

RST30H:
	ret

start:
	call	setMode2	; Set mode 2
	call	clearVRAM	; Clear VRAM
	
	call	showTitle	; Show title
	call	startGame	; Start game
	
endlessLoop:
	jp		endlessLoop
	