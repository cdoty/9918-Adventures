	.org	8000h
	
	.dc.w	5555h
	
Start:
	bl		@setMode2	; Set VDP mode 2
	bl		@clearVRAM	; Clear VRAM
	bl		@showTitle	; Show title
	bl		@startGame	; Start game

EndlessLoop:
	jmp		EndlessLoop
	