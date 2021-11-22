#include <stdio.h>

#include "File.h"
#include "Macros.h"

void usage();

static const int	gsc_iFileSize	= 64 * 1024;	// File size

template <typename T, typename U> const T BIT(T x, U n) { return (x >> n) & T(1); }

template <typename T, typename U> const T bitswap(T val, U b) { return BIT(val, b) << 0U; }

template <typename T, typename U, typename... V> const T bitswap(T val, U b, V... c)
{
	return (BIT(val, b) << sizeof...(c)) | bitswap(val, c...);
}

// explicit version that checks number of bit position arguments
template <unsigned B, typename T, typename... U> T bitswap(T val, U... b)
{
	static_assert(sizeof...(b) == B, "wrong number of bits");
	static_assert((sizeof(std::remove_reference_t<T>) * 8) >= B, "return type too small for result");
	return bitswap(val, b...);
}

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

	if (pFile->getLength() != gsc_iFileSize)
	{
		printf("SwapBanks only works on 64k roms");

		return	1;
	}

	DEFINESHAREDBUFFER(pBinary, uint8_t, gsc_iFileSize);

	memset(pBinary.get(), 0xFF, gsc_iFileSize);

	if (false == pFile->readBuffer(pBinary.get(), gsc_iFileSize))
	{
		printf("Unable to read from binary file %s", argv[1]);

		return	1;
	}

	pFile->close();
	pFile.reset();

	uint8_t *mem	= pBinary.get();
	 
	// data swap
	for (int i = 0; i < gsc_iFileSize; i++)
	{
//		mem[i] = bitswap<8>(mem[i],3,5,6,7,0,4,2,1);
		mem[i] = bitswap<8>(mem[i],4,5,6,2,7,1,0,3);
	}

	// address line swap
	std::vector<uint8_t> buf(&mem[0], &mem[gsc_iFileSize]);

	for (int i = 0; i < gsc_iFileSize; i++)
	{
//		mem[bitswap<16>(i,11,9,8,13,14,15,12,7,6,5,4,3,2,1,0,10)] = buf[i];
		mem[i] = buf[bitswap<16>(i,11,9,8,13,14,15,12,7,6,5,4,3,2,1,0,10)];
	}

	pFile	= File::create();

	if (false == pFile->create(argv[2], true))
	{
		printf("Unable to create binary file %s", argv[1]);

		return	1;
	}

	if (false == pFile->writeBuffer(pBinary.get(), gsc_iFileSize))
	{
		printf("Unable to write to binary file %s", argv[2]);

		return	1;
	}

	pFile->close();

	return	0;
}

void usage()
{
	printf("Usage: Swap BinFile OutFile\n");
}
