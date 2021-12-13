ROMStart			%equ	100h
RAMStart			%equ	8000h
RAMSize				%equ	200h
StackStart			%equ	RAMStart + RAMSize
VDPBase				%equ	08h
VDPReadBase			%equ	VDPBase
Tile1VRAM			%equ	0000h		; Tile VRAM locations
Tile2VRAM			%equ	0800h
Tile3VRAM			%equ	1000h
SpritePattern		%equ	1800h		; Sprite pattern location
Color1VRAM			%equ	2000h		; Color VRAM locations
Color2VRAM			%equ	2800h
Color3VRAM			%equ	3000h
ScreenVRAM			%equ	3800h		; Screen VRAM location
SpriteAttributes	%equ	3B00h		; Sprite attributes
VBIAddress			%equ	FB06h		; Video blank interrupt address
