BaseMem	%equ	8000h
	
%org	0
	
	db	FFh
	db	"BURGER INVADERS"	; Program name
	dw	F8F2h
	
	ds	16 * 22, 0

	db  00h, F2h, F8h, 02h, 00h, 00h, 00h, 00h
	db	00h, 00h, 00h, 0Ah, F9h, 02h, 00h, 00h
	db	00h, 00h, 00h, 00h, 00h, 22h, F9h, 02h
	db	00h, 00h, 00h, 00h, 00h, 00h, 00h, 3Ah
	db	F9h, 02h, 00h, 00h, 00h, 00h, 00h, 00h
	
%org	F8F2h
	
	db	0					; LSTPG
	dw	C000h				; VARNAM
	dw	C001h				; VALBOT
	dw	C001h				; CALCBOT
	dw	C001h				; CALCST
	dw	FB4Bh				; KBDBUF
	db	00h, 00h, 00h, 00h	; USYNT
	db	00h, C9h, C9h		; USER
	db	00h, 00h, 00h		; $FA8C
	db	01h					; IOPL
	db	FFh					; REALBY
	db	80h					; KBFLAG
	dw	F8F2h				; STKLIM
	dw	FB4Bh				; SYSTOP
	dw	FD48h				; SSTACK
	db	C9h, 00h, 00h		; USERINT
	db	C9h, 00h, 00h		; NODLOC
	db	C9h, 00h, 00h		; FEXPAND
	db	C9h, 00h, 00h		; USERNOD
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
	dw 	FAD8h				; GOPTR
	dw 	0					; GOSNUM
	db 	0					; CTYLST
	dw 	BaseMem				; DATAAD
	db 	80h					; DATAPG
	dw 	EndHeader - 1		; DESAVE
	
%org	BaseMem
	
StartHeader:
	dw	EndHeader - StartHeader, 5
	db	80h, FFh
EndHeader:

StartEntry:
	dw	EndEntry - StartEntry, 10
	db	C2h
	dw	EndLoader - StartLoader

StartLoader:
	ld		a, 0
	ld		(FD67h), a
	ld		a, 1
	ld		(FD68h), a
	
	ld		hl, BaseMem + 100h		; Load the main file
	ld		de, EndCart - StartCart
	call	AAEh					
	
	jp		BaseMem + 100h			; Start the game

EndLoader:
	db	FFh	; End of Basic marker

EndEntry:
	db	FFh	; End of Basic variables marker
	