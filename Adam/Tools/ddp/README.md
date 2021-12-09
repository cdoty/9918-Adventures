ddp
===

A simple DDP creation tool for Adam EOS software development.

Author:
	Thom Cherryhomes <thom.cherryhomes@gmail.com>

Usage:
	ddp <boot.bin> <program.bin> <output.ddp>

	boot.bin
		A binary file to be placed in block 0 for the boot. The binary should be assembled to C800H.

	program.bin
		A binary file to be placed in block 1, continuing to end of tape. maximum size 261,120 bytes.

	output.ddp
		The output filename for the resulting DDP image.
Return:
	The program returns exit code 0, and no messages, if successful. Otherwise, an error message is returned.

