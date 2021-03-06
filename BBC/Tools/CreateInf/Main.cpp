#include <stdio.h>
#include <string>

#include "File.h"

void usage();

int main(int argc, char* argv[])
{
	if (argc != 8)
	{
		usage();

		return	1;
	}

	File::Ptr	pFile	= File::create();

	if (nullptr == pFile)
	{
		printf("Unable to create file instance\n");

		return	1;
	}

	if (false == pFile->open(argv[2], true))
	{
		printf("Unable to open file\n");

		return	1;
	}

	int	iLength	= pFile->getLength();

	pFile->close();

	uint32_t	loadAddress	= (uint32_t)std::stoi(argv[4]);
	uint32_t	startAddress	= (uint32_t)std::stoi(argv[5]);
	uint32_t	attribute		= (uint32_t)std::stoi(argv[6]);
	uint32_t	type			= (uint32_t)std::stoi(argv[7]);

	char	szValue[1024];

	sprintf(szValue, "$.%s %.6X %.6X %.6X ATTR=%ud TYPE=%ud", argv[3], loadAddress, startAddress, iLength, attribute, type);

	if (false == pFile->create(argv[1]))
	{
		printf("Unable to create inf file\n");

		return	1;
	}

	if (false == pFile->writeLine(szValue))
	{
		printf("Unable to write to inf file\n");

		return	1;
	}

	pFile->close();

	return	0;
}

void usage()
{
	printf("Usage: InfFilename Filename TargeFilename LoadAddress StartAddress\n");
}
