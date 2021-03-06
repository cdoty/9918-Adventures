ROMStart			%equ	0000h
ROMSize				%equ	(32*1024)
RAMStart			%equ	C000h		; Cartridge can use all of memory
RAMSize				%equ	4000h		; RAM size
StackStart			%equ	FFFFh
VDPBase				%equ	80h
VDPReadBase			%equ	84h
Tile1VRAM			%equ	0000h		; Tile VRAM locations
Tile2VRAM			%equ	0800h
Tile3VRAM			%equ	1000h
SpritePattern		%equ	1800h		; Sprite pattern location
Color1VRAM			%equ	2000h		; Color VRAM locations
Color2VRAM			%equ	2800h
Color3VRAM			%equ	3000h
ScreenVRAM			%equ	3800h		; Screen VRAM location
SpriteAttributes	%equ	3B00h		; Sprite attributes
