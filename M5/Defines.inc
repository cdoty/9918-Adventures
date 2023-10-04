ROMStart			= 2000h
	ifdef RAM_8K_2000
ROMSize				= (8*1024)
	endif
	ifdef RAM_8K_4000
ROMSize				= (8*1024)
	endif
	ifdef RAM_16K_2000
ROMSize				= (16*1024)
	endif
RAMStart			= 7300h
RAMSize				= 0D00h
StackStart			= 7FFFh
VDPBase				= 10h
VDPReadBase			= VDPBase
Tile1VRAM			= 0000h		; Tile VRAM locations
Tile2VRAM			= 0800h
Tile3VRAM			= 1000h
SpritePattern		= 1800h		; Sprite pattern location
Color1VRAM			= 2000h		; Color VRAM locations
Color2VRAM			= 2800h
Color3VRAM			= 3000h
ScreenVRAM			= 3800h		; Screen VRAM location
SpriteAttributes	= 3B00h		; Sprite attributes
VBIAddress			= 7006h		; Z80CTC Channel 3 interrupt routine address
