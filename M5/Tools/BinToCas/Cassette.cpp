#include <locale>

#include "Cassette.h"

Cassette::Cassette()	:
	m_iFileLength(0),
	m_iBufferLength(0)
{
}

Cassette::~Cassette()
{
	close();
}

Cassette::Ptr Cassette::create(const std::string& _strFilename)
{
	INSTANCE(pCassette, Cassette())

	if (false == pCassette->initialize(_strFilename))
	{
		pCassette.reset();
	}

	return	pCassette;
}

bool Cassette::initialize(const std::string& _strFilename)
{
	if (false == load(_strFilename))
	{
		return	false;
	}

	return	true;
}

void Cassette::close()
{
}

bool Cassette::save(const std::string& _strFilename)
{
	File::Ptr	pFile	= File::create();

	if (nullptr == pFile)
	{
		printf("Unable to create file interface.\n");

		return	false;
	}

	if (false == pFile->create(_strFilename, true))
	{
		printf("Unable to create cas file");

		return	false;
	}

	uint8_t	buffer[32];

	memset(buffer, 0, 32);

	memcpy(buffer, "SORDM5", 6);

	// Write cas file header
	if (false == pFile->writeBuffer(buffer, 16))
	{
		printf("Unable to write to cas file");

		return	false;
	}

	// Write header block IDENT
	if (false == pFile->write8Bit('H'))
	{
		printf("Unable to write to cas file");
		
		return	false;
	}

	// Write size of data block
	if (false == pFile->write8Bit(0x1F))
	{
		printf("Unable to write to cas file");
		
		return	false;
	}

	memset(buffer, 0, 32);

	// Set attribute
	buffer[0]	= 0x03;

	std::string	strName	= File::getFilenameFromPath(_strFilename).c_str();

	int	t_c	= strName.length();

	if (t_c > 9)
	{
		t_c	= 9;
	}

	for (int iLoop = 0; iLoop < t_c; ++iLoop)
	{
		buffer[iLoop + 1]	= toupper(strName[iLoop]);
	}

	// Set load address
	*(uint16_t*)(&buffer[0x0A])	= 0x7300;
	
	// Set data length
	*(uint16_t*)(&buffer[0x0C])	= m_iFileLength;
	
	// Set start address
	*(uint16_t*)(&buffer[0x0E])	= 0x7300;
	
	// Set extended attribute
	buffer[0x10]				= 0;

	buffer[0x1F]				= calculateChecksum(buffer, 0x1F);

	if (false == pFile->writeBuffer(buffer, 32))
	{
		printf("Unable to write to cas file");
		
		return	false;
	}

	int	iBlocks	= m_iBufferLength / 256;

	for (int iLoop = 0; iLoop < iBlocks; ++iLoop)
	{
		writeBlock(pFile, m_pBinaryBuffer.get() + iLoop * 256, 256);
	}

	pFile->close();

	return	true;
}

bool Cassette::load(const std::string& _strFilename)
{
	File::Ptr	pFile	= File::create();

	if (false == pFile->open(_strFilename, true))
	{
		printf("Unable to load binary file %s\n", _strFilename.c_str());

		return	false;
	}

	m_iFileLength	= pFile->getLength();

	m_iBufferLength	= m_iFileLength;

	if (0 == m_iBufferLength)
	{
		printf("Binary file is invalid\n");

		return	false;
	}

	// Ensure size is a multiple of 256
	if ((m_iBufferLength & 0xFF) != 0)
	{
		m_iBufferLength	+= 256;

		m_iBufferLength &= 0x7FFFFF00;
	}

	SHAREDBUFFER(m_pBinaryBuffer, uint8_t, m_iBufferLength);

	memset(m_pBinaryBuffer.get(), 0, m_iBufferLength);

	if (false == pFile->readBuffer(m_pBinaryBuffer.get(), m_iFileLength))
	{
		printf("Unable to read binary file\n");

		return	false;
	}

	pFile->close();

	return	true;
}

bool Cassette::writeBlock(File::Ptr _pFile, uint8_t* _pBuffer, int _iSize)
{
	// Write data IDENT
	if (false == _pFile->write8Bit('D'))
	{
		printf("Unable to write to cas file");

		return	false;
	}

	// Write block data size. 0 = 0x100
	if (false == _pFile->write8Bit(0))
	{
		printf("Unable to write to cas file");

		return	false;
	}

	if (false == _pFile->writeBuffer(_pBuffer, _iSize))
	{
		printf("Unable to write to cas file");

		return	false;
	}

	if (false == _pFile->write8Bit(calculateChecksum(_pBuffer, _iSize)))
	{
		printf("Unable to write to cas file");

		return	false;
	}

	return	true;
}

uint8_t Cassette::calculateChecksum(uint8_t* _pBuffer, int _iSize)
{
	uint8_t	checkSum	= 0;

	for (int iLoop = 0; iLoop < _iSize; ++iLoop)
	{
		checkSum	+= _pBuffer[iLoop];
	}

	return	checkSum;
}
