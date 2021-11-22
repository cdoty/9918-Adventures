#pragma once

#include <stdio.h>
#include <string>
#include <vector>

#include "Macros.h"

// File read and writing class. Wraps FILE*, and provides additional functionality.
class File
{
	public:
		enum SeekPoint
		{
			SeekFromStart	= 0,
			SeekFromCurrent,
			SeekFromEnd
		};

		PTR(File)

		// Destructor
		~File();

		// Create
		static Ptr create();

		// Open file
		bool open(const std::string& _strFilename, bool _bBinary = false);
		bool open(const std::wstring& _strFilename, bool _bBinary = false);
	
		// Create file
		bool create(const std::string& _strFilename, bool _bBinary = false);
		bool create(const std::wstring& _strFilename, bool _bBinary = false);
	
		// Append file
		bool append(const std::string& _strFilename, bool _bBinary = false);
		bool append(const std::wstring& _strFilename, bool _bBinary = false);
	
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
		bool readString(std::wstring& _strValue);

		// Read line
		bool readLine(std::string& _strLine, int _iMaxSize = 8192) const;
		bool readLine(std::wstring& _strLine, int _iMaxSize = 8192) const;

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
		bool writeString(const std::wstring& _strString) const;
		
		// Seek
		bool seek(int _iOffset, SeekPoint _eSeekPoint = SeekFromCurrent) const;
		
		// Get position
		int getPosition() const;
		
		// Get length
		int getLength() const;
		
		// End of file?
		bool endOfFile() const;

		// File exists?
		static bool fileExists(const std::string& _strFilename, bool _bIgnoreDirectories = true);
		static bool fileExists(const std::wstring& _strFilename, bool _bIgnoreDirectories = true);
		
		// Directory exists?
		static bool directoryExists(const std::string& _strDirectoryName);
		static bool directoryExists(const std::wstring& _strDirectoryName);
		
		// Copy file
		static bool copyFile(const std::string& _strSrc, const std::string& _strDest);
		static bool copyFile(const std::wstring& _strSrc, const std::wstring& _strDest);

		// Delete file
		static bool deleteFile(const std::string& _strFilename);
		static bool deleteFile(const std::wstring& _strFilename);
		
		// Delete multiple files
		static bool deleteMultipleFiles(const std::string& _strFilename);
		static bool deleteMultipleFiles(const std::wstring& _strFilename);
		
		// Delete directory
		static bool deleteDirectory(const std::string& _strDirectory);
		static bool deleteDirectory(const std::wstring& _strDirectory);
		
		// Recursively delete directory
		static bool recursivelyDeleteDirectory(const std::string& _strDirectory);
		static bool recursivelyDeleteDirectory(const std::wstring& _strDirectory);

		// Create directory
		static bool createDirectory(const std::string& _strFilename);
		static bool createDirectory(const std::wstring& _strFilename);
		
		// Get current directory
		static std::string getCurrentDirectory();
		static std::wstring getCurrentDirectoryWideString();

		// Set current directory
		static bool setCurrentDirectory(const std::string& _strDirectory);
		static bool setCurrentDirectory(const std::wstring& _strDirectory);

		// Set working directory
		static bool setWorkingDirectory();

		// Get program directory
		static std::string getProgramDirectory();
		static std::wstring getProgramDirectoryWideString();

		// Get filename from path
		static std::string getFilenameFromPath(const std::string& _strPath);

		// Get extension from path
		static std::string getExtensionFromPath(const std::string& _strPath);
		static std::wstring getExtensionFromPath(const std::wstring& _strPath);

		// Get filename + extension from path
		static std::string getFullFilenameFromPath(const std::string& _strPath);

		// Get directory from path
		static std::string getDirectoryFromPath(const std::string& _strPath);
		static std::wstring getDirectoryFromPath(const std::wstring& _strPath);

		// Find files
		static bool findFiles(const std::string& _strPath, std::vector<std::string>& _vecFiles);
		static bool findFiles(const std::wstring& _strPath, std::vector<std::wstring>& _vecFiles);

		// Find directories
		static bool findDirectories(const std::string& _strPath, std::vector<std::string>& _vecDirectories);
		static bool findDirectories(const std::wstring& _strPath, std::vector<std::wstring>& _vecDirectories);

		// Append directory separator
		static void addDirectorySeparator(std::string& _strPath);
		static void addDirectorySeparator(std::wstring& _strPath);

		// Convert to file URL
		static void convertToFileURL(std::string& _strPath);
		static void convertToFileURL(std::wstring& _strPath);

		// Get handle
		FILE* getHandle() const {return m_pHandle;}

	private:
		FILE*	m_pHandle;	// File handle
		bool	m_bBinary;	// Writing in binary format?

		// Constructor
		File();
};
