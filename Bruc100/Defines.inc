ROMStart		%equ	4000h
ROMSize				%equ	(32*1024)
RAMStart			%equ	E000h		; C000h for 16kb machines and E000h 8kb machines
RAMSize				%equ	1000h
VDPBase				%equ	98h
VDPReadBase			%equ	VDPBase
InterruptHook		%equ	FD9Ah
PrimarySlotReg		%equ	A8h
ExpansionTable		%equ	FCC1h
Tile1VRAM			%equ	0000h		; Tile VRAM locations
Tile2VRAM			%equ	0800h
Tile3VRAM			%equ	1000h
SpritePattern		%equ	1800h		; Sprite pattern location
Color1VRAM			%equ	2000h		; Color VRAM locations
Color2VRAM			%equ	2800h
Color3VRAM			%equ	3000h
ScreenVRAM			%equ	3800h		; Screen VRAM location
SpriteAttributes	%equ	3B00h		; Sprite attributes
