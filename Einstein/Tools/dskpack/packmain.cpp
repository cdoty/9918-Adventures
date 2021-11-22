#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

#include "disk.h"
#include "dsk.h"

#include "argcrack.h"

// todo - 
//   parameter parsing
//   check for duplicate names in the directory?
//   work on restrictions of tracks/sectors count in DSK parsing
//   default DOS in byte array? On disk alongside program??
//   creation of DSK format without donor
//   error handling

const int SCT_MAX = 512;			// bytes per sector

const int DOS_MAX = SCT_MAX*10*2;	// size of DOS on disk, 2 tracks of 10 sectors of 512 bytes
const int DOS_SECT = DOS_MAX / SCT_MAX;

const int DIR_MAX = 64*32;			// 64 entries at 32 bytes per entry
const int DIR_SECT = DIR_MAX / SCT_MAX;

const int DSK_MAX = 40*10*SCT_MAX;	// 40 tracks of 10 sectors of 512 bytes

const int BLK_MAX = 2048;			// bytes per disk allocation block


enum
{
	ERR_NONE,

	ERR_OPEN_DISK_IMG,
	ERR_OPEN_TARGET,
	ERR_OPEN_LIST,

	ERR_LAST
};


typedef struct
{
	uint8_t user;
	char fileName[8];
	char extension[3];
	uint8_t extent;
	uint8_t reserved1, reserved2;
	uint8_t recordCount;
	uint16_t alloc[8];
}
DIRENT;


bool diskFactory(const char* filename, disk*& image)
{
	image = NULL;

	uint8_t temp[16];
	FILE* srcFile;

	int srcResult = fopen_s(&srcFile, filename, "rb");
	if (0 == srcResult)
	{
		fseek(srcFile, 0, SEEK_END);
		size_t fileLen = ftell(srcFile);
		rewind(srcFile);
		fread_s(temp, 16, 1, 16, srcFile);
		fclose(srcFile);

		if (memcmp(temp, "EXTENDED CPC DSK", 16) == 0 && fileLen == 215296)
		{
			// it's a DSK formatted file
			image = new dsk();
		}
		else if (fileLen == 204800)
		{
			// it's raw
			image = new disk();
		}
	}

	// returns true if image was created
	//
	return image != NULL;
}


// copy up to, but excluding, a period, end of string or character count limit
//
char* copyFilenamePart(char*dst, char* src, int limit)
{
	while(*src && *src != '.' && limit)
	{
		*dst = toupper(*src);
		++dst;
		++src;

		--limit;
	}

	return src;
}


int main(int argc, char**argv)
{
	int ret;
	disk* target;

	std::string dosImageName = "dos205.dsk";
	std::string donorImageName = "dos205.dsk";
	std::string targetImageName = "floppy.dsk";

	std::string listFileName = "list.txt";

	argcrack args(argc, argv);

	args.getstring("/dos:", dosImageName);
	args.getstring("/donor:", donorImageName);
	args.getstring("/target:", targetImageName);

	args.getstring("/list:", listFileName);

	// load DOS donor disk
	// format without a DOS source will leave the DOS tracks intact
	//
	target = new dsk();

	// create a container for the dos image
	disk* dosImage;
	diskFactory(dosImageName.c_str(), dosImage);

	dosImage->load(dosImageName.c_str());

	//target->format(dosImage);
	target->load(dosImageName.c_str());

	// scrape the text file which lists the source files
	//
	FILE* listFile;
	ret = fopen_s(&listFile, listFileName.c_str(), "r");
	if (ret)
	{
		puts("Couldn't open source file list.");
		return ERR_OPEN_LIST;
	}
	else
	{
		int block = 1;

		int sector = DOS_SECT + DIR_SECT;

		int freeExtents = 64;
		int freeBlocks = (DSK_MAX - DOS_MAX - DIR_MAX) / BLK_MAX;

		uint8_t blockBuffer[BLK_MAX];

		DIRENT directory[64];
		DIRENT* directoryEntry = directory;
		memset(directory, 0xe5, sizeof(directory));

		while(1)
		{
			// pull a filename from the file
			//
			char fnBuff[256];
			char* srcFileName = fgets(fnBuff, 255, listFile);
			if (!srcFileName)
			{
				break;
			}

			// trim whitespace off the filename
			//
			while (*srcFileName && *srcFileName <= 32){ ++srcFileName; }
			char* src = srcFileName;
			while (*src > 32){ ++src; }
			*src = 0;

			FILE* srcFile;
			int srcResult = fopen_s(&srcFile, srcFileName, "rb");
			if (srcResult)
			{
				printf("Could not open '%s': ignoring\n", srcFileName);
			}
			else
			{
				fseek(srcFile, 0, SEEK_END);
				size_t fileLen = ftell(srcFile);
				rewind(srcFile);

				int recordCount = (fileLen + 127) / 128;		// a record is 128 bytes. all files are a multiple of this size.
				int blockCount = (recordCount + 15) / 16;		// all files are allocated in 2k blocks on disk.
				int extentCount = ( blockCount + 7) / 8;		// an extent holds up to 128 records in 8 blocks.

				if (freeExtents < extentCount)
				{
					printf("Not enough free extents for '%s': ignoring\n", srcFileName);
				}
				else if (freeBlocks < blockCount)
				{
					printf("Not enough free blocks for '%s': ignoring\n", srcFileName);
				}
				else
				{
					printf("Adding '%s'\n", srcFileName);

					memset(directoryEntry, 0, sizeof(DIRENT) * extentCount);

					for (int extent = 0; extent < extentCount; ++extent)
					{
						directoryEntry->extent = extent;

						directoryEntry->recordCount = recordCount < 128 ? recordCount : 128;
						recordCount -= directoryEntry->recordCount;

						int blocks = blockCount < 8 ? blockCount : 8;
						blockCount -= blocks;

						memset(&directoryEntry->fileName[0], 32, 11);

						src = copyFilenamePart(&directoryEntry->fileName[0], srcFileName, 8);
						if (*src == '.')
						{
							++src;
							copyFilenamePart(&directoryEntry->extension[0], src, 3);
						}

						for (int i = 0; i < blocks; ++i)
						{
							directoryEntry->alloc[i] = block;

							memset(blockBuffer, 0, BLK_MAX);
							fread(blockBuffer, 1, BLK_MAX, srcFile);
							target->writeSectors(sector, 4, blockBuffer);

							--freeBlocks;
							sector += 4;
							++block;
						}

						++directoryEntry;
						--freeExtents;
					}
				}

				fclose(srcFile);
			}
		}

		// write the directory after the DOS tracks
		//
		target->writeSectors(DOS_SECT, DIR_SECT, (unsigned char*)directory);

		fclose(listFile);
	}

	target->save(targetImageName.c_str());
}
