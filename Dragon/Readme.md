# Dragon 32/64 and Tandy Color Computer
* The Premier Microsystems Sprites, [WordPak 2+](https://sites.google.com/site/tandycocoloco/wordpak-2), and [Super Sprite FM+](https://www.dragonplus-electronics.co.uk/super-sprite-fm-plus/) cards are supported.
* Mame's [imgtool](https://www.mamedev.org/) is used to support creating VDK and DSK files.
* In the current configuration, the Dragon 32 is configured for the Premier Microsystems Sprites card, and the Color Computer is configured for the WordPak 2+ and Super Sprite FM+. The WordPak 2+ and Super Sprite FM+ will work on the Dragon 32 also.
* The disk image can be started with RUN "BOOT
* You have to type bindly on the Super Sprite FM+ version, as MAME doesn't seem to handle the overlayed screens correctly.

# Compression
File compression is implemented with [ZX0](https://github.com/einar-saukas/ZX0), based on this [code](https://github.com/dougmasten/zx0-6x09).