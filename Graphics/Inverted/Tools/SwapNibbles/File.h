#pragma once

#include "Macros.h"

class File
{
	public:
		PTR(File)

		enum SeekPoint
		{
			SeekFromStart	= 0,
			SeekFromCurrent,
			SeekFromEnd
		};

		// Destructor
		virtual ~File();

		// Create
		static Ptr create();

		// Open file
		bool open(const std::string& _strFilename, bool _bBinary = false);
	
		// Create file
		bool create(const std::string& _strFilename, bool _bBinary = false);
	
		// Append file
		bool append(const std::string& _strFilename, bool _bBinary = false);
	
		// Close file
		bool close();
		
		// Read 8 bit value
		bool read8Bit(char& _iValue) const;
		
		// Read unsigned 8 bit value
		bool readUnsigned8Bit(uint8_t& _iValue) const;
		
		// Read 16 bit
		bool read16Bit(short& _iValue) const;
		
		// Read unsigned 16 bit
		bool readUnsigned16Bit(uint16_t& _iValue) const;
		
		// Read 32 bit
		bool read32Bit(int& _iValue) const;
		
		// Read unsigned 32 bit
		bool readUnsigned32Bit(uint32_t& _iValue) const;
		
		// Read 64 bit
		bool read64Bit(int64_t& _iValue) const;
		
		// Read unsigned 64 bit
		bool readUnsigned64Bit(uint64_t& _iValue) const;
		
		// Read null terminated string into std::string
		bool readString(std::string& _strValue);

		// Read line
		bool readLine(std::string& _strLine, int _iMaxSize = 8192) const;

		// Read buffer
		bool readBuffer(void* _pBuffer, int _iBufferSize, int _iElementSize = 1) const;
		bool readBuffer(uint8_t** _pBuffer, int _iBufferSize, int _iElementSize = 1) const;

		// Write signed/unsigned 8 bit value
		bool write8Bit(uint8_t _iValue) const;
		
		// Write signed/unsigned 32 bit value
		bool write32Bit(int _iValue) const;
		
		// Write signed/unsigned 64 bit value
		bool write64Bit(int64_t _iValue) const;
		
		// Write float value
		bool writeFloat(float _fValue) const;
		
		// Write line
		bool writeLine(const std::string& _strLine) const;

		// Write buffer
		bool writeBuffer(const uint8_t* _pBuffer, int iBufferSize) const;
		
		// Write string
		bool writeString(const std::string& _strString) const;
		
		// Delete file
		static bool deleteFile(const std::string& _strFilename);
		
		// Seek
		bool seek(int _iOffset, SeekPoint _eSeekPoint = SeekFromCurrent) const;
		
		// Get position
		int getPosition() const;
		
		// Get length
		int getLength() const;
		
		// End of file?
		bool endOfFile() const;

		// Get handle
		FILE* getHandle() const {return m_pHandle;}

	private:
		FILE*	m_pHandle;	// File handle
		bool	m_bBinary;	// Writing in binary format?

		// Constructor
		File();
};
