	.align 16

Start:
	bl		@setMode2	; Set VDP mode 2
	bl		@clearVRAM	; Clear VRAM
	bl		@showTitle	; Show title

	li		r1, 6004h
	li		r2, Start
	
	b		@SwapBank
	