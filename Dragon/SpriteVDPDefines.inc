VDPBase				equ	$C000 + $2000
VDPRead				equ VDPBase
VDPStatus			equ VDPBase + 1
VDPWrite			equ VDPBase
VDPRegister			equ VDPBase + 1
Tile1VRAM			equ	$0000		; Tile VRAM locations
Tile2VRAM			equ	$0800
Tile3VRAM			equ	$1000
SpritePattern		equ	$1800		; Sprite pattern location
Color1VRAM			equ	$2000		; Color VRAM locations
Color2VRAM			equ	$2800
Color3VRAM			equ	$3000
ScreenVRAM			equ	$3800		; Screen VRAM location
SpriteAttributes	equ	$3B00		; Sprite attributes
