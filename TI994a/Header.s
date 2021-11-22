	.dc.w	0AA01h, 0100h, 0000h, Entry		; Standard header (AAh), version 1
	.dc.w	0000h, 0000h, 0000h, 0000h

Entry:
	.dc.w	0000h, Start					; Link to next object, Address of item
	
	.dc.b	15								; Name lengh
	.asciiz	"BURGER INVADERS"
