# PK8002
* The graphics hardware is nearly a clone of the TMS-9938/58.  
* The PK8002 supports a keyboard and two joysticks with two buttons each.  
* The cassette image must be encoded to autostart after load.
&emsp;&ensp;This is a simple look up table replacement for every byte in the cassette file, except for the load start, load end, and program start address.  
* [Emu](http://bashkiria-2m.narod.ru/index/emul/0-8) was used for testing the program. The MAME driver isn't complete for the PK8002.  

# Memory locations
Ram/Rom swap ($80)	Four 16k banks can be swapped in and out. Only affects read, writes always go to ram.  
There are two bits for each bank:  
00 Enables rom in that bank.  
01 External 1 (?)  
10 External 2 (?)  
11 Enables ram.  
  
Keyboard read ($81)	Reads the selected keyboard row. A reset bit indicates a keypress.  
  
Keyboard select ($82)	Selects a keyboard row to read. Also sets Speaker output, tape output, and Turbo mode.  
Bit 4 ($10) Sets turbo mode.  
Bit 5 ($20) Indicates RG. (?)  
Bit 6 ($40) Sets tape output.  
Bit 7 ($80) Sets speaker output.  
  
K580BB55 control mode ($83/$87)	Sets K580BB55 mode.  
  
Video mode ($84)	Sets various settings for the video hardware.  
Bit 0 ($01)	Enables or disables sprites.
Bit 2 ($04)	Enables 60 hz mode. If set the system runs at 60 hz, and 50 hz if cleared.  
Bit 3 ($08)	Enables graphics mode. If set, the pattern memory is configured like mode 2 on the TMS9918a. If cleared, it is configured like mode 1.  
&emsp;&ensp;Mode 2 divides the screen into 3 parts and uses a pattern and color buffer for each part. Mode one shares a pattern and color buffer for the entire screen.  
Bit 4 ($10) Controls how the color table location is set. If the bit is set, port $92 controls the location. If cleared, it comes after the name table.  
Bit 5 ($20) Controls the color mode. If the bit is cleared, it operates like the TMS9918a. If set, 2/4 colors per pixelare used.  
Bit 6 and 7 ($C0) Sets upper two bits of the 16 bit VRAM address, in RAM.  
  
Video enable ($86)	Customization settings for more of the video.  
Bit 0 ($01) Printer ready (?)  
Bit 1 ($02) Signal printer (?)  
Bit 3 ($08) Sets the display width to 256 or 512.  
&emsp;&ensp;If the bit is cleared, the screen is 256 pixels wide, and 4 colors per pixel can be used.  
&emsp;&ensp;If the bit is set, the screen is 512 pixels wide, and 2 colors per pixel can be used.  
Bit 4 ($10) Enable screen. If the bit is set, the screen is enabled.  
Bit 5 ($20) Indicates RUS(?)  
Bit 6 ($40) Set the screen height. If the bit is cleared, the screen is 192 pixels tall. If the bit is set, the screen is 212 pixels tall.  
  
Screen color ($88-$89)	Sets borders color/background color and text color.  
Upper 4 bits set border color.  
Lower 4 bits set text color.  
  
Palette index ($8A-$8B)	Sets the pallette index. Port $94 writes data to this index. Only used in 2 color and 4 color per pixel modes.  
  
Joystick port 2 ($8C)	Reads joystick input and sprite collision status.  
Bits 0-5 ($3F) A cleared bit indicates a joystick button or direction is pressed.  
Bit 7 ($80) If set, indicates a sprite collision occured.  

Joystick port 1 ($8D)	Reads joystick input and sprite tape recorder status.  
Bits 0-5 ($3F) A cleared bit indicates a joystick button or direction is pressed.  
Bit 7 ($80) Tape recorder status. (?)  
  
Sprite attribute table ($90) Sets the position of the sprite attribute table / $400. The VRAM location, set in port $84, will be added to this value.  
  
Name table ($91) Sets the position of the name table / $400. The VRAM location, set in port $84, will be added to this value.  
  
Color table ($92) Sets the position of the color table / $400. The VRAM location, set in port $84, will be added to this value.  
  
Pattern table ($93) Sets the position of the pattern table / $400. The VRAM location, set in port $84, will be added to this value.  
  
Palette Data ($94) Writes data to the palette index set in port $8A. Only used in 2 color and 4 color per pixel modes.
                    Format is GGGRRRBB.  
  
Volume setting ($9B) Sets the sound volume.  
  
Timer settings ($9C-9F) Timer settings for K580VI53. (?)  
  
# Compression
File compression is implemented with [ZX0](https://github.com/einar-saukas/ZX0), based on this [code](https://github.com/ivagorRetrocomp/DeZX).