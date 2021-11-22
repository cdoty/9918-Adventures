#include <stdio.h>

#include "File.h"
#include "Macros.h"

void usage();

static const int	gsc_iRomSize	= 32768;	// Rom size

int main(int argc, char* argv[])
{
	if (argc != 3)
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

	if (pFile->getLength() != gsc_iRomSize)
	{
		printf("SwapBanks only works on roms of size %d", gsc_iRomSize);

		return	1;
	}

	DEFINESHAREDBUFFER(pBinary, uint8_t, gsc_iRomSize);

	memset(pBinary.get(), 0xFF, gsc_iRomSize);

	if (false == pFile->readBuffer(pBinary.get(), gsc_iRomSize))
	{
		printf("Unable to read from binary file %s", argv[1]);

		return	1;
	}

	pFile->close();
	pFile.reset();

	pFile	= File::create();

	if (false == pFile->create(argv[2], true))
	{
		printf("Unable to create binary file %s", argv[1]);

		return	1;
	}

	if (false == pFile->writeBuffer(pBinary.get() + gsc_iRomSize / 2, gsc_iRomSize / 2))
	{
		printf("Unable to write to binary file %s", argv[1]);

		return	1;
	}

	if (false == pFile->writeBuffer(pBinary.get(), gsc_iRomSize / 2))
	{
		printf("Unable to write to binary file %s", argv[2]);

		return	1;
	}

	pFile->close();

	return	0;
}

void usage()
{
	printf("Usage: SwapBanks InFile OutFile\n");
}
