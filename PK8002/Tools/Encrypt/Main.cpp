#include <stdio.h>

#include "File.h"
#include "Macros.h"
#include "EncodingTable.h"

void usage();

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

	int	iLength	= pFile->getLength();

	DEFINESHAREDBUFFER(pBinary, uint8_t, iLength);

	memset(pBinary.get(), 0x00, iLength);

	if (false == pFile->readBuffer(pBinary.get(), iLength))
	{
		printf("Unable to read from binary file %s", argv[1]);

		return	1;
	}

	pFile->close();

	uint8_t*	pBuffer	= pBinary.get();

	// Skip header and then encrypt all other bytes
	for (int iLoop = 0x26; iLoop < iLength; ++iLoop)
	{
		uint8_t	uValue	= pBuffer[iLoop];

		pBuffer[iLoop]	= gsc_encodedTable[uValue];
	}

	if (false == pFile->create(argv[2], true))
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
	printf("Usage: Encrypt InFile OutFile\n");
}
