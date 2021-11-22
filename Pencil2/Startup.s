%org	ROMStart

%def8	"COPYRIGHT SOUNDIC"	; Boot message
	jp	start				; Start of code
	jp	NMIHandler
	jp	RST08H
	jp	RST10H
	jp	RST18H
	jp	RST20H
	jp	RST28H
	jp	RST30H
	jp	IM1Handler
	
%defb   8034h-%apos							; Pad to 8034h
%def8	"RASTERSOFT!BURGER INVADERS!2020"	; Cartridge title
%def8	0

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
	