# PK8000/Photon system documentations
* The graphics hardware is nearly a clone of the TMS-9918a, but lacks sprite hardware.
* The PK8000 supports a keyboard and two joysticks with two buttons each.

# Memory locations
Ram/Rom swap ($80): Four 16k banks can be swapped in and out. Only affects read, writes always go to ram.  
There are two bits for each bank:  
00 Enables rom in that bank.  
01 External 1 (?)  
10 External 2 (?)  
11 Enables ram.

For debugging, ram can be enabled to see VRAM, in bank 0. (Set it to 0xFF)  
Interrupts need to be disabled.

Keyboard read ($81)	Reads the selected keyboard row.  
A reset bit indicates a keypress.

Keyboard select ($82)	Selects a keyboard row to read.  
There is no delay between writing to $82 and reading from $81

Video mode ($84)	Upper four bits select the video mode.  
Bit 4 ($10) sets color text mode.  
Bit 5 ($20) If enabled, in monochrome mode, it uses the io space palette. The palette has an entry for each 8 character group in the pattern data.  
Bit 7 ($80) sets bitmap mode.  
20 is mode 0. Mode 0 is a monochrome mode. The video color register set the background and text color. Only the pattern and name table data are used.  
10 is mode 1 or 2.  
	Mode 1 is a multicolor mode, each 8x8 character can have a foreground and background color.  
	Mode 2 is a more advanced multicolor mode, each 8x8 character can have a foreground and background color for each of the 8 lines.  
These modes are effectively the same as the TMS 9918a ones.

Video enable ($86)	Enables and disables video.  
Write $10 to enable, write $00 to disable.

Screen color ($88)	Sets borders color/background color and text color, depending on video mode.  
Upper 4 bits set border color. In mode 0, it also sets the background color.  
Lower 4 bits set text color in mode 0. Lower 4 bits have no effect in graphics mode 1 or 2.

Text data ($90)	Sets the position of the name table / $400, in mode 0 and 1.  
Can only use the the first 14k of video memory, and is limited to increments of $800. On MSX, the sprite table would use the rest.

Name table ($91)	Pointer to start of name table data / $400.  
Can only use the the first 14k of video memory, and is limited to increments of $800. On MSX, the sprite table would use the rest.

Color data ($92)	Sets the position of the color table / $400, in mode 2.  
Can only use the the first 8k of video memory.

Pattern data ($93)	Sets the position of the pattern data / $400.  
Can only use the first 8k of video memory.  
In mode 0, this is one byte per character, split into upper and lower 4 bit parts.  
In mode 1, it's 8 bytes per character.

The value is reversed, when compared to a TMS-9918a. The upper 4 bits is background color and the lower 4 bits is foreground color.

MAME uses the following values for the palette:  
0x000000  
0x000000  
0x00c000  
0x00ff00  
0x0000c0  
0x0000ff  
0x00c0c0  
0x00ffff  
0xc00000  
0xff0000  
0xc0c000  
0xffff00  
0xc000c0  
0xff00ff  
0xc0c0c0  
0xffffff  

Palette entries 6 and 12 are completely different colors, when compared to the TMS-9918a, and several others are a different shade.

color table ($A0 - $BF)	Color table for monochrome mode. It is only used if bit 5, of video mode, is set.  
The format is the same as the color data, the upper 4 bits is background color and the lower 4 bits is foreground color.

# Compression
File compression is implemented with [ZX0](https://github.com/einar-saukas/ZX0), based on this [code](https://github.com/ivagorRetrocomp/DeZX).