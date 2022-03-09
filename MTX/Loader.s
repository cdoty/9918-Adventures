BaseMem	= 8000h
	
	org	0
	
	db	0FFh
	db	"BURGER INVADERS"	; Program name
	dw	0F8F2h
	
	ds	16 * 22, 0

	db  00h, 0F2h, 0F8h, 02h, 00h, 00h, 00h, 00h
	db	00h, 00h, 00h, 0Ah, 0F9h, 02h, 00h, 00h
	db	00h, 00h, 00h, 00h, 00h, 22h, 0F9h, 02h
	db	00h, 00h, 00h, 00h, 00h, 00h, 00h, 3Ah
	db	0F9h, 02h, 00h, 00h, 00h, 00h, 00h, 00h
	
	org	0F8F2h
	
	db	0					; LSTPG
	dw	0C000h				; VARNAM
	dw	0C001h				; VALBOT
	dw	0C001h				; CALCBOT
	dw	0C001h				; CALCST
	dw	0FB4Bh				; KBDBUF
	db	00h, 00h, 00h, 00h	; USYNT
	db	00h, 0C9h, 0C9h		; USER
	db	00h, 00h, 00h		; $FA8C
	db	01h					; IOPL
	db	0FFh				; REALBY
	db	80h					; KBFLAG
	dw	0F8F2h				; STKLIM
	dw	0FB4Bh				; SYSTOP
	dw	0FD48h				; SSTACK
	db	0C9h, 00h, 00h		; USERINT
	db	0C9h, 00h, 00h		; NODLOC
	db	0C9h, 00h, 00h		; FEXPAND
	db	0C9h, 00h, 00h		; USERNOD
	dw	EndEntry - BaseMem	; NBTOP
	db	0					; NBTPG
	dw	EndEntry - BaseMem	; BASTOP
	db	0					; BASTPG
	dw	4000h				; BASBOT
	dw	EndEntry - BaseMem
	ds	30, 0
	dw 	EndEntry - BaseMem	; ARRTOP
	db 	0					; ARRTPG
	dw 	BaseMem				; BASELIN
	db 	0					; BASLNP
	db 	0					; PAGE
	db 	0					; CRNTPG
	db 	0					; PGN1
	db 	0					; PGN2
	dw	EndEntry - BaseMem	; PGTOP
	ds	105, 0
	dw 	0FAD8h				; GOPTR
	dw 	0					; GOSNUM
	db 	0					; CTYLST
	dw 	BaseMem				; DATAAD
	db 	80h					; DATAPG
	dw 	EndHeader - 1		; DESAVE
	
	org	BaseMem
	
StartHeader:
	dw	EndHeader - StartHeader, 5
	db	80h, 0FFh
EndHeader:

StartEntry:
	dw	EndEntry - StartEntry, 10
	db	0C2h
	dw	EndLoader - StartLoader

StartLoader:
	ld		a, 0
	ld		(0FD67h), a
	ld		a, 1
	ld		(0FD68h), a
	
	ld		hl, BaseMem + 100h		; Load the main file
	ld		de, EndCart - StartCart
	call	0AAEh					
	
	jp		BaseMem + 100h			; Start the game

EndLoader:
	db	0FFh	; End of Basic marker

EndEntry:
	db	0FFh	; End of Basic variables marker
	