%org	0C800h

Boot:
	di

	ld		a, b
	ld		(CurrentDevice), a
	
	ld		a, ProgramSize / BlockSize
	ld		(BlocksToLoad), a

	ld		de, 1
	ld		hl, ROMStart

blockLoadLoop:
	ld		a, (CurrentDevice)
	ld		bc, 0

RetryRead:
	push	de
	push	hl

	call	FCF3h		; Read one block

	pop		hl
	pop		de

	jr		nz, RetryRead

	inc		de

	ld		bc, BlockSize
	add		hl, bc
	
	ld		a, (BlocksToLoad)
	dec		a
	ld		(BlocksToLoad), a
	
	jr 		nz, blockLoadLoop

	jp		start
	
CurrentDevice:
	db	0

BlocksToLoad:
	db	0

%defb	(Boot+BlockSize)-%apos, FFh	; Pad to ROMSize
