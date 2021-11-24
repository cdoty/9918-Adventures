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

	int	iLength	= pFile->getLength();

	DEFINESHAREDBUFFER(pBinary, uint8_t, iLength);

	memset(pBinary.get(), 0xFF, iLength);

	if (false == pFile->readBuffer(pBinary.get(), iLength))
	{
		printf("Unable to read from binary file %s", argv[1]);

		return	1;
	}

	pFile->close();
	pFile.reset();

	uint8_t*	pBuffer	= pBinary.get();

	for (int iLoop = 0; iLoop < iLength; ++iLoop)
	{
		uint8_t	value	= *pBuffer;
		uint8_t	lower	= (value & 0x0F);
		uint8_t	upper	= (value & 0xF0);

		switch (lower)
		{
			case 0x0C:
				lower	= 0x03;

				break;
		}

		switch (upper)
		{
			case 0xC0:
				upper	= 0x30;

				break;
		}

		*pBuffer	= (lower << 4) | (upper >> 4);

		pBuffer++;
	}

	pFile	= File::create();

	if (false == pFile->create(argv[1], true))
	{
		printf("Unable to create binary file %s", argv[1]);

		return	1;
	}

	if (false == pFile->writeBuffer(pBinary.get(), iLength))
	{
		printf("Unable to write to binary file %s", argv[1]);

		return	1;
	}

	pFile->close();

	return	0;
}

void usage()
{
	printf("Usage: SwapNibbles BinFile\n");
}
