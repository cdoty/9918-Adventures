	ROMStart			= $1900
	RAMStart			= $3000
	ZPStart				= $E8		; Needs 6 bytes
	HFMStart			= $F6		; Huffmunch start, needs 9 bytes
	VDPRead				= $FCA0
	VDPWrite			= $FCA1
	VDPStatus			= $FCA2
	VDPRegister			= $FCA3
	Tile1VRAM			= $0000		; Tile VRAM locations
	Tile2VRAM			= $0800
	Tile3VRAM			= $1000
	SpritePattern		= $1800		; Sprite pattern location
	Color1VRAM			= $2000		; Color VRAM locations
	Color2VRAM			= $2800
	Color3VRAM			= $3000
	ScreenVRAM			= $3800		; Screen VRAM location
	SpriteAttributes	= $3B00		; Sprite attributes
	