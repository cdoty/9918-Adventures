// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#endif

#include <windows.h>
#include <tchar.h>
#include <direct.h>
#include <Shellapi.h>

#include "File.h"

File::File() :
	m_pHandle(NULL),
	m_bBinary(false)
{
}

File::~File()
{
	close();
}

File::Ptr File::create()
{
	INSTANCE(pFile, File());

	return	pFile;
}

bool File::open(const std::string& _strFilename, bool _bBinary)
{
	// Close a previously opened file.
	if (m_pHandle != NULL)
	{
		close();
	}
	
	fopen_s(&m_pHandle, _strFilename.c_str(), true == _bBinary ? "rb" : "rt");
	
	if (NULL == m_pHandle)
	{
		return	false;
	}
	
	m_bBinary	= _bBinary;

	return	true;
}

bool File::create(const std::string& _strFilename, bool _bBinary)
{
	// Close a previously opened file.
	if (m_pHandle != NULL)
	{
		close();
	}
	
	fopen_s(&m_pHandle, _strFilename.c_str(), true == _bBinary ? "wb" : "wt");
	
	if (NULL == m_pHandle)
	{
		return	false;
	}
	
	m_bBinary	= _bBinary;

	return	true;
}

bool File::append(const std::string& _strFilename, bool _bBinary)
{
	// Close a previously opened file.
	if (m_pHandle != NULL)
	{
		close();
	}
	
	fopen_s(&m_pHandle, _strFilename.c_str(), true == _bBinary ? "ab" : "at");
	
	if (NULL == m_pHandle)
	{
		return	false;
	}
	
	m_bBinary	= _bBinary;

	return	true;
}

bool File::close()
{
	if (m_pHandle != NULL)
	{
		fclose(m_pHandle);
	
		m_pHandle	= NULL;
	}
	
	return	true;
}

bool File::read8Bit(char& _iValue) const
{
	if (fread(&_iValue, sizeof(char), 1, m_pHandle) != 1)
	{
		return	false;
	}
	
	return	true;
}

bool File::readUnsigned8Bit(uint8_t& _iValue) const
{
	if (fread(&_iValue, sizeof(uint8_t), 1, m_pHandle) != 1)
	{
		return	false;
	}
	
	return	true;
}

bool File::read16Bit(short& _iValue) const
{
	if (fread(&_iValue, sizeof(short), 1, m_pHandle) != 1)
	{
		return	false;
	}
	
	return	true;
}

bool File::readUnsigned16Bit(uint16_t& _iValue) const
{
	if (fread(&_iValue, sizeof(uint16_t), 1, m_pHandle) != 1)
	{
		return	false;
	}
	
	return	true;
}

bool File::read32Bit(int& _iValue) const
{
	if (fread(&_iValue, sizeof(int), 1, m_pHandle) != 1)
	{
		return	false;
	}
	
	return	true;
}

bool File::readUnsigned32Bit(uint32_t& _iValue) const
{
	if (fread(&_iValue, sizeof(uint32_t), 1, m_pHandle) != 1)
	{
		return	false;
	}
	
	return	true;
}

bool File::read64Bit(int64_t& _iValue) const
{
	if (fread(&_iValue, sizeof(int64_t), 1, m_pHandle) != 1)
	{
		return	false;
	}
	
	return	true;
}

bool File::readUnsigned64Bit(uint64_t& _iValue) const
{
	if (fread(&_iValue, sizeof(uint64_t), 1, m_pHandle) != 1)
	{
		return	false;
	}
	
	return	true;
}

bool File::readString(std::string& _strValue)
{
	_strValue.clear();

	while (true)
	{
		char	value;

		if (false == read8Bit(value))
		{
			return	false;
		}
		
		if (0 == value)
		{
			break;
		}

		_strValue	+= value;
	}

	return	true;
}

bool File::readLine(std::string& _strLine, int _iMaxSize) const
{
	_strLine.clear();

	DEFINESHAREDBUFFER(pBuffer, char, _iMaxSize);
							
	if (nullptr == pBuffer || NULL == fgets(pBuffer.get(), _iMaxSize, m_pHandle))
	{
		return	false;
	}

	_strLine	= pBuffer.get();

	size_t	found	= _strLine.find('\n');
	
	if (found != std::string::npos)
	{
		_strLine.erase(found, 1);
	}

	return	true;
}

bool File::readBuffer(void* _pBuffer, int _iBufferSize, int _iElementSize) const
{
	if (fread(_pBuffer, (size_t)_iElementSize, (size_t)_iBufferSize, m_pHandle) != (size_t)_iBufferSize)
	{
		return	false;
	}
	
	return	true;
}

bool File::readBuffer(uint8_t** _pBuffer, int _iBufferSize, int _iElementSize) const
{
	if (NULL == *_pBuffer)
	{
		*_pBuffer	= new (std::nothrow) uint8_t[(size_t)_iBufferSize];

		if (nullptr == *_pBuffer)
		{
			return	false;
		}
	}
	
	return	readBuffer(*_pBuffer, _iBufferSize, _iElementSize);
}

bool File::write8Bit(uint8_t _iValue) const
{
	if (fwrite(&_iValue, sizeof(uint8_t), 1, m_pHandle) != 1)
	{
		return	false;
	}
	
	return	true;
}

bool File::write32Bit(int _iValue) const
{
	if (fwrite(&_iValue, sizeof(int), 1, m_pHandle) != 1)
	{
		return	false;
	}
	
	return	true;
}

bool File::write64Bit(int64_t _iValue) const
{
	if (fwrite(&_iValue, sizeof(int64_t), 1, m_pHandle) != 1)
	{
		return	false;
	}
	
	return	true;
}

bool File::writeFloat(float _fValue) const
{
	if (fwrite(&_fValue, sizeof(float), 1, m_pHandle) != 1)
	{
		return	false;
	}
	
	return	true;
}

bool File::writeBuffer(const uint8_t* _pBuffer, int iBufferSize) const
{
	if (fwrite(_pBuffer, 1, (size_t)iBufferSize, m_pHandle) != (size_t)iBufferSize)
	{
		return	false;
	}
	
	return	true;
}

bool File::writeLine(const std::string& _strLine) const
{
	if (false == writeString(_strLine))
	{
		return	false;
	}

	if (false == writeString("\n"))
	{
		return	false;
	}

	return	true;
}

bool File::writeString(const std::string& _strString) const
{
	if (false == _strString.empty())
	{
		size_t	iBufferSize;
		
		if (true == m_bBinary)
		{
			iBufferSize	= _strString.length() + 1;
		}
		
		else
		{
			iBufferSize	= _strString.length();
		}
		
		return	writeBuffer(reinterpret_cast<const uint8_t*>(_strString.c_str()), (int)iBufferSize);
	}
	
	return	true;
}

bool File::seek(int _iOffset, SeekPoint _eSeekPoint) const
{
	int	iOrigin;
	
	switch (_eSeekPoint)
	{
		case SeekFromStart:
			iOrigin	= SEEK_SET;
			
			break;
			
		case SeekFromCurrent:
			iOrigin	= SEEK_CUR;
			
			break;
			
		case SeekFromEnd:
			iOrigin	= SEEK_END;
			
			break;
	
		default:
			return	false;
	}
	
	if (fseek(m_pHandle, _iOffset, iOrigin) != 0)
	{
		return	false;
	}
	
	return	true;
}

int File::getPosition() const
{
	return	ftell(m_pHandle);
}

int File::getLength() const
{
	int	iCurrentPosition	= ftell(m_pHandle);
	
	if (-1 == iCurrentPosition || fseek(m_pHandle, 0, SEEK_END) != 0)
	{
		return	-1;
	}
	
	int	iLength	= ftell(m_pHandle);
	
	fseek(m_pHandle, iCurrentPosition, SEEK_SET);
	
	return	iLength;
}

bool File::endOfFile() const
{
	return	feof(m_pHandle) != 0;
}

bool File::fileExists(const std::string& _strFilename, bool _bIgnoreDirectories)
{
	DWORD	uFileAttributes	= GetFileAttributesA(_strFilename.c_str());
	
	if (uFileAttributes != INVALID_FILE_ATTRIBUTES)
	{
		if (FILE_ATTRIBUTE_DIRECTORY == (uFileAttributes & FILE_ATTRIBUTE_DIRECTORY) && true == _bIgnoreDirectories)
		{
			return	false;
		}
		
		return	true;
	}
	
	return	false;
}

bool File::directoryExists(const std::string& _strFilename)
{
	DWORD	uFileAttributes	= GetFileAttributesA(_strFilename.c_str());
	
	if (uFileAttributes != INVALID_FILE_ATTRIBUTES && FILE_ATTRIBUTE_DIRECTORY == (uFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
	{
		return	true;
	}
	
	return	false;
}

bool File::copyFile(const std::string& _strSrc, const std::string& _strDest)
{
	if (FALSE == CopyFileA(_strSrc.c_str(), _strDest.c_str(), FALSE))
	{
		return	false;
	}

	return	true;
}

bool File::deleteFile(const std::string& _strFilename)
{
	if (FALSE == DeleteFileA(_strFilename.c_str()))
	{
		return	false;
	}
	
	return	true;
}

bool File::deleteMultipleFiles(const std::string& _strFilename)
{
	WIN32_FIND_DATAA	findData;
	DWORD				uFileFlags	= FILE_ATTRIBUTE_HIDDEN | FILE_ATTRIBUTE_DIRECTORY | FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_SYSTEM | FILE_ATTRIBUTE_REPARSE_POINT | FILE_ATTRIBUTE_OFFLINE; 

	std::string	strDirectory	= getDirectoryFromPath(_strFilename);

	HANDLE	hFindFile	= FindFirstFileA(_strFilename.c_str(), &findData);
	
	if (INVALID_HANDLE_VALUE == hFindFile)
	{
		return	false;
	}
	
	do 
	{
		if (0 == (uFileFlags & findData.dwFileAttributes))
		{
			char	szFilename[FILENAME_MAX];

			_snprintf_s(szFilename, FILENAME_MAX, "%s\\%s", strDirectory.c_str(), findData.cFileName);

			if (false == deleteFile(szFilename))
			{
				FindClose(hFindFile);
		
				return	false;
			}
		}
	} while (FindNextFileA(hFindFile, &findData) != FALSE);
	
	FindClose(hFindFile);
		
	return	true;
}

bool File::deleteDirectory(const std::string& _strDirectory)
{
	if (0 == RemoveDirectoryA(_strDirectory.c_str()))
	{
		return	false;
	}

	return	true;
}

bool File::recursivelyDeleteDirectory(const std::string& _strDirectory)
{
	SHFILEOPSTRUCTA	fileOps	= {0};

	memset(&fileOps, 0, sizeof(SHFILEOPSTRUCTA));

	std::string	strTempDirectory;

	strTempDirectory	= _strDirectory;

	strTempDirectory.push_back(0x00);
	strTempDirectory.push_back(0x00);

	fileOps.wFunc	= FO_DELETE;
	fileOps.pFrom	= strTempDirectory.c_str();
	fileOps.fFlags	= FOF_NO_UI;

	return	0 == SHFileOperationA(&fileOps);
}

bool File::createDirectory(const std::string& _strFilename)
{
	if (0 == CreateDirectoryA(_strFilename.c_str(), NULL))
	{
		return	false;
	}

	return	true;
}

std::string File::getCurrentDirectory()
{
	char	szCurrentDirectory[FILENAME_MAX];

	memset(szCurrentDirectory, 0, FILENAME_MAX);

	GetCurrentDirectoryA(FILENAME_MAX, szCurrentDirectory);
	
	std::string	strDirectory	= szCurrentDirectory;

	addDirectorySeparator(strDirectory);

	return	strDirectory;
}

bool File::setCurrentDirectory(const std::string& _strDirectory)
{
	return	FALSE != SetCurrentDirectoryA(_strDirectory.c_str());
}

bool File::setWorkingDirectory()
{
	TCHAR	szFilename[FILENAME_MAX];
	TCHAR	szDrive[FILENAME_MAX];
	TCHAR	szDir[FILENAME_MAX];
	
	if (FALSE == GetModuleFileName(NULL, szFilename, FILENAME_MAX))
	{
		printf("Unable to get module filename\n");

		return	false;
	}
	
	_tsplitpath_s(szFilename, szDrive, FILENAME_MAX, szDir, FILENAME_MAX, NULL, 0, NULL, 0);
	
	std::basic_string<TCHAR>	strDirectory;
	
	strDirectory	= szDrive;
	strDirectory	+= szDir;

	if (FALSE == SetCurrentDirectory(strDirectory.c_str()))
	{
		printf("Unable to set working directory\n");

		return	false;
	}

	return	true;
}

std::string File::getProgramDirectory()
{
	char	szDirectory[FILENAME_MAX];

	GetModuleFileNameA(GetModuleHandle(NULL), szDirectory, FILENAME_MAX);

	return	getDirectoryFromPath(szDirectory);
}

std::string File::getFilenameFromPath(const std::string& _strPath)
{
	char	szFilename[FILENAME_MAX];

	_splitpath_s(_strPath.c_str(), NULL, 0, NULL, 0, szFilename, FILENAME_MAX, NULL, 0);

	return	szFilename;
}

std::string File::getExtensionFromPath(const std::string& _strPath)
{
	char	szExtension[FILENAME_MAX];

	_splitpath_s(_strPath.c_str(), NULL, 0, NULL, 0, NULL, 0, szExtension, FILENAME_MAX);

	return	szExtension;
}

std::string File::getFullFilenameFromPath(const std::string& _strPath)
{
	char	szFilename[FILENAME_MAX];
	char	szExtension[FILENAME_MAX];

	_splitpath_s(_strPath.c_str(), NULL, 0, NULL, 0, szFilename, FILENAME_MAX, szExtension, FILENAME_MAX);

	std::string	strFilename;

	strFilename	= szFilename;
	strFilename	+= szExtension;
	
	return	strFilename;
}

std::string File::getDirectoryFromPath(const std::string& _strPath)
{
	char	szDrive[FILENAME_MAX];
	char	szDir[FILENAME_MAX];

	_splitpath_s(_strPath.c_str(), szDrive, FILENAME_MAX, szDir, FILENAME_MAX, NULL, 0, NULL, 0);

	std::string	strDirectory;

	strDirectory	= szDrive;
	strDirectory	+= szDir;
	
	return	strDirectory;
}

bool File::findFiles(const std::string& _strPath, std::vector<std::string>& _vecFiles)
{
	_vecFiles.clear();

	WIN32_FIND_DATAA	findData;

	HANDLE	hFindFile	= FindFirstFileA(_strPath.c_str(), &findData);

	if (INVALID_HANDLE_VALUE == hFindFile)
	{
		return	false;
	}
		
	if (0 == (FILE_ATTRIBUTE_DIRECTORY & findData.dwFileAttributes))
	{
		std::string	strFound	= findData.cFileName;
		
		_vecFiles.push_back(strFound);
	}

	while (FindNextFileA(hFindFile, &findData) != FALSE)
	{
		if (0 == (FILE_ATTRIBUTE_DIRECTORY & findData.dwFileAttributes))
		{
			std::string	strFound	= findData.cFileName;
		
			_vecFiles.push_back(strFound);
		}
	}
	
	FindClose(hFindFile);

	return	true;
}

bool File::findDirectories(const std::string& _strPath, std::vector<std::string>& _vecDirectories)
{
	std::string	strSearch;

	strSearch	= _strPath;
	
	addDirectorySeparator(strSearch);

	strSearch	+= "*.*";
	
	WIN32_FIND_DATAA	findData;

	HANDLE	hFindFile	= FindFirstFileA(strSearch.c_str(), &findData);
	
	if (INVALID_HANDLE_VALUE == hFindFile)
	{
		return	false;
	}

	if ((FILE_ATTRIBUTE_DIRECTORY & findData.dwFileAttributes) != 0)
	{
		std::string	strFound	= findData.cFileName;
		
		if (strFound != "." && strFound != "..")
		{
			_vecDirectories.push_back(strFound);
		}
	}

	while (FindNextFileA(hFindFile, &findData) != FALSE)
	{
		if ((FILE_ATTRIBUTE_DIRECTORY & findData.dwFileAttributes) != 0)
		{
			std::string	strFound	= findData.cFileName;
		
			if (strFound != "." && strFound != "..")
			{
				_vecDirectories.push_back(strFound);
			}
		}
	}
	
	FindClose(hFindFile);

	return	true;
}

void File::addDirectorySeparator(std::string& _strPath)
{
	char	separator;

	if (_strPath.find('\\') != std::string::npos)
	{
		separator	= '\\';
	}

	else
	{
		separator	= '/';
	}

	int	iPos	= (int)_strPath.rfind(separator);

	if (-1 == iPos || iPos < (int)_strPath.length() - 1)
	{
		_strPath	+= separator;
	}
}
