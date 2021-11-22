#include "File.h"
#include "stdio.h"

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

	uint32_t	iLoadAddress	= (uint32_t)std::stoi(argv[4]);
	uint32_t	iStartAddress	= (uint32_t)std::stoi(argv[5]);
	uint32_t	iAttribute		= (uint32_t)std::stoi(argv[6]);
	uint32_t	iType			= (uint32_t)std::stoi(argv[7]);

	char	szValue[1024];

	sprintf(szValue, "$.%s %.6X %.6X %.6X ATTR=%d TYPE=%d", argv[3], iLoadAddress, iStartAddress, iLength, iAttribute, iType);

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
