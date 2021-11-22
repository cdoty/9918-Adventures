#include <stdio.h>

#include "Cassette.h"

void usage();

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		usage();

		return	1;
	}

	Cassette::Ptr	pCassette	= Cassette::create(argv[1]);

	if (nullptr == pCassette)
	{
		return	1;
	}

	if (false == pCassette->save(argv[2]))
	{
		return	1;
	}

	return	0;
}

void usage()
{
	printf("Usage: BinToCas BinFile CasFile\n");
}
