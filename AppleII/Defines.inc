	ROMStart		= $1000
	RAMStart		= $4000
	ZPStart			= $E8		; Needs 6 bytes
	HFMStart		= $F6		; Huffmunch start, needs 9 bytes
	VDPRead			= $C090
	VDPStatus		= $C091
	VDPWrite		= $C090
	VDPRegister		= $C091
	Tile1VRAM		= $0000		; Tile VRAM locations
	Tile2VRAM		= $0800
	Tile3VRAM		= $1000
	Color1VRAM		= $2000		; Color VRAM locations
	Color2VRAM		= $2800
	Color3VRAM		= $3000
	ScreenVRAM		= $3800		; Screen VRAM location
	