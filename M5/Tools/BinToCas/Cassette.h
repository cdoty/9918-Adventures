#pragma once

#include "File.h"
#include "Macros.h"

class Cassette
{
	public:
		PTR(Cassette)

		// Destructor
		~Cassette();

		// Create
		static Ptr create(const std::string& _strFilename);

		// Initialize
		bool initialize(const std::string& _strFilename);

		// Close
		void close();

		// Save
		bool save(const std::string& _strFilename);

	private:
		SHAREDPTR(uint8_t, m_pBinaryBuffer);	// Binary buffer

		int	m_iFileLength;		// File length
		int	m_iBufferLength;	// Buffer length

		// Constructor
		Cassette();

		// Load
		bool load(const std::string& _strFilename);

		// Write block
		bool writeBlock(File::Ptr _pFile, uint8_t* _pBuffer, int _iSize);

		// Calculate checksum
		uint8_t calculateChecksum(uint8_t* _pBuffer, int _iSize);
};
