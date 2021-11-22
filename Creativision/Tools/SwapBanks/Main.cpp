#include <stdio.h>

#include "File.h"
#include "Macros.h"

void usage();

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		usage();

		return	1;
	}

	File::Ptr	pFile	= File::create();

	if (false == pFile->open(argv[1], true))
	{
		printf("Unable to open binary file %s", argv[1]);

		return	1;
	}

	if (pFile->getLength() != 16384)
	{
		printf("SwapBanks only works on 16k roms");

		return	1;
	}

	DEFINESHAREDBUFFER(pBinary, uint8_t, 16384);

	memset(pBinary.get(), 0xFF, 16384);

	if (false == pFile->readBuffer(pBinary.get(), 16384))
	{
		printf("Unable to read from binary file %s", argv[1]);

		return	1;
	}

	pFile->close();
	pFile.reset();

	pFile	= File::create();

	if (false == pFile->create(argv[1], true))
	{
		printf("Unable to create binary file %s", argv[1]);

		return	1;
	}

	if (false == pFile->writeBuffer(pBinary.get() + 8192, 8192))
	{
		printf("Unable to write to binary file %s", argv[1]);

		return	1;
	}

	if (false == pFile->writeBuffer(pBinary.get(), 8192))
	{
		printf("Unable to write to binary file %s", argv[1]);

		return	1;
	}

	pFile->close();

	return	0;
}

void usage()
{
	printf("Usage: SwapBanks BinFile\n");
}
