#include <stdio.h>
#include <ctype.h>
#include <fstream>
#include <sstream>

#include "dsk.h"

typedef unsigned char BYTE;
typedef unsigned short WORD;

typedef struct
{
	char headerString[34];
	char creatorName[14];
	BYTE nTracks;
	BYTE nSides;
	BYTE unused[2];
	BYTE trackSizeTable[256 - 52];
}
DISK_INFORMATION_BLOCK;

typedef struct
{
	char headerString[13];
	BYTE unused[3];
	BYTE trackNumber;
	BYTE sideNumber;
	BYTE unused2[2];
	BYTE sectorSize;
	BYTE nSectors;
	BYTE GAPHASH3Length;
	BYTE filler;
}
TRACK_INFORMATION_BLOCK;
//24

typedef struct
{
	BYTE track;
	BYTE side;
	BYTE sectorID;
	BYTE sectorSize;
	BYTE FDCStatusRegister1;
	BYTE FDCStatusRegister2;
	WORD dataLength;
}
SECTOR_INFORMATION_BLOCK;
// 8


void dsk::init(int tracks, int sectors, int bytesPerSector)
{
	disk::init(tracks, sectors, bytesPerSector);

	auto totalSize =
		sizeof(DISK_INFORMATION_BLOCK) +
		sizeof(TRACK_INFORMATION_BLOCK) * _trackCount +
		sizeof(SECTOR_INFORMATION_BLOCK) * _sectorsPerTrack +
		_trackCount * _sectorsPerTrack * _bytesPerSector;

	_raw.resize(totalSize);

	unsigned char* p = _raw.data();
	DISK_INFORMATION_BLOCK dib = *(DISK_INFORMATION_BLOCK*)p;
	strcpy(dib.headerString, "EXTENDED CPC DSK File\r\nDisk-Info\r\n");
	strcpy(dib.creatorName, "dsktool");
	dib.nTracks = _trackCount;
	dib.nSides = 1;

	auto trackStoreSize = 256 + (_sectorsPerTrack * _bytesPerSector);
	memset(dib.trackSizeTable, trackStoreSize >> 8, _trackCount);

	p += 256;

	for (auto track = 0; track < _trackCount; ++track)
	{
		TRACK_INFORMATION_BLOCK tib = *(TRACK_INFORMATION_BLOCK*)p;
		strcpy(tib.headerString, "Track-Info\r\n");
		tib.trackNumber = track;
		tib.sideNumber = 0;
		tib.sectorSize = _bytesPerSector >> 8;
		tib.nSectors = _sectorsPerTrack;

		SECTOR_INFORMATION_BLOCK* sib = (SECTOR_INFORMATION_BLOCK*)(p + sizeof(TRACK_INFORMATION_BLOCK));

		p += 256;

		for (auto sector = 0; sector < _sectorsPerTrack; ++sector) {
			sib->track = track;
			sib->side = 0;
			sib->sectorID = sector; // no interleaving. may hurt performance if written to physical disk.
			sib->sectorSize = _bytesPerSector >> 8;
			sib->dataLength = _bytesPerSector;
			++sib;

			_sectorOffsets[track * _sectorsPerTrack + sector] = p;
			memset(p, 0xe5, _bytesPerSector);
			p += _bytesPerSector;
		}
	}
}

bool dsk::cloneSectorsFrom(dsk& other)
{
	if (_trackCount != other._trackCount || _sectorsPerTrack != other._sectorsPerTrack || _bytesPerSector != other._bytesPerSector)
		return false;

	auto rawSectors = other.readSectors(0, _trackCount * _sectorsPerTrack);
	writeSectors(0, _trackCount * _sectorsPerTrack, rawSectors);

	return true;
}

bool dsk::parse()
{
	BYTE* fptr = (BYTE*)_raw.data();

	DISK_INFORMATION_BLOCK* dib = (DISK_INFORMATION_BLOCK*)fptr;
	fptr += sizeof(DISK_INFORMATION_BLOCK);

	if (memcmp(dib, "EXTENDED", 8) != 0)
		return false;

	if (dib->nSides == 2)
		return false;

	disk::init(dib->nTracks, 10, 512);

	for (auto track = 0; track < _trackCount; ++track)
		if (dib->trackSizeTable[track] != 0x15)
			return false;

	for (auto track = 0; track < _trackCount; ++track)
	{
		TRACK_INFORMATION_BLOCK* tib = (TRACK_INFORMATION_BLOCK*)fptr;
		SECTOR_INFORMATION_BLOCK* sib = (SECTOR_INFORMATION_BLOCK*)(fptr + sizeof(TRACK_INFORMATION_BLOCK));

		fptr += 256;
		BYTE* sectorBase = fptr;

		for (auto sector = 0; sector < 10; ++sector) {

			setRawSectorPtr(track, sib->sectorID, fptr);
			fptr += 512;
			++sib;
		}
	}

	return true;
}

bool dsk::load(string fileName)
{
	_raw = loadBytes(fileName);
	if (_raw.size() < 215296 || memcmp(_raw.data(), "EXTENDED CPC DSK", 16) != 0)
		return false;

	return parse();
}

bool dsk::save(string fileName)
{
	ofstream outfile(fileName, ios::out | ios::binary);
	if (outfile.good())
		outfile.write((const char*)_raw.data(), 215296);
	return outfile.good();
}

void dsk::diag(void(*logger)(string))
{
	BYTE* fptr = (BYTE*)_raw.data();

	DISK_INFORMATION_BLOCK* dib = (DISK_INFORMATION_BLOCK*)fptr;
	fptr += sizeof(DISK_INFORMATION_BLOCK);

	if (memcmp(dib, "EXTENDED", 8) != 0)
		return logger("No extended dsk tag found in DIB");

	if (dib->nSides == 2)
		return logger("Image has more than 1 side");

	for (auto track = 0; track < dib->nTracks; ++track)
	{
		TRACK_INFORMATION_BLOCK* tib;
		SECTOR_INFORMATION_BLOCK* sib;
		tib = (TRACK_INFORMATION_BLOCK*)fptr;
		sib = (SECTOR_INFORMATION_BLOCK*)(fptr + sizeof(TRACK_INFORMATION_BLOCK));

		fptr += 256;
		BYTE* sectorBase = fptr;

		logger("Track: " + to_string(track) + " size code: " + to_string(dib->trackSizeTable[track]));

		for (auto sector = 0; sector < 10; ++sector)
		{
			logger("  Sector " + to_string(sib->sectorID) + ", size: " + to_string(sib->sectorSize));

			fptr += 512;
			++sib;
		}
	}
}
