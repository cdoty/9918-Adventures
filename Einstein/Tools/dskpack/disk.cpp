#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <vector>
#include <fstream>

#include "disk.h"


void disk::init(int tracks, int sectors, int bytesPerSector)
{
	_trackCount = tracks;
	_sectorsPerTrack = sectors;
	_bytesPerSector = bytesPerSector;
	_sectorOffsets.resize(_trackCount * _sectorsPerTrack);
}

int disk::size()
{
	return _trackCount * _sectorsPerTrack * _bytesPerSector;
}

int disk::totalSectorCount()
{
	return _trackCount * _sectorsPerTrack;
}

vector<unsigned char> disk::loadBytes(string filePath)
{
	vector<unsigned char> data;
	ifstream input(filePath, ios::binary | ios::ate);

	if (input.good()) {
		auto size = (size_t)input.tellg();
		data.resize(size);
		input.seekg(0, ios::beg);
		input.read((char*)data.data(), size);
	}

	return data;
}

bool disk::saveBytes(string filePath, vector<unsigned char> bytes)
{
	ofstream outfile(filePath, ios::out | ios::binary);
	outfile.write((const char*)bytes.data(), bytes.size());
	return outfile.good();
}

// base implementation is a raw disk image dump, contiguous sectors
//
bool disk::load(string fileName)
{
	init(40, 10, 512);

	_raw = loadBytes(fileName);
	for (auto i = 0; i < totalSectorCount(); ++i) {
		_sectorOffsets[i] = _raw.data() + i * _bytesPerSector;
	}

	return _raw.size() == size();
}

bool disk::save(string fileName)
{
	ofstream outfile(fileName, ios::out | ios::binary);

	for (auto i = 0; i < totalSectorCount(); ++i) {
		outfile.write((const char*)_sectorOffsets[i], _bytesPerSector);
	}

	return outfile.good();
}

void disk::setRawSectorPtr(int track, int sector, unsigned char* ptr)
{
	_sectorOffsets[track * 10 + sector] = ptr;
}

vector<unsigned char> disk::readSectors(int startSector, int sectorCount)
{
	vector<unsigned char> sectors;
	sectors.resize(sectorCount * _bytesPerSector);
	for (auto i = 0; i < sectorCount; ++i) {
		memcpy(sectors.data() + i * _bytesPerSector, _sectorOffsets[startSector + i], _bytesPerSector);
	}

	return sectors;
}

void disk::writeSectors(int startSector, int sectorCount, unsigned char* sectors)
{
	for (auto i = 0; i < sectorCount; ++i) {
		memcpy(_sectorOffsets[startSector + i], sectors + i * _bytesPerSector, _bytesPerSector);
	}
}

void disk::writeSectors(int startSector, int sectorCount, vector<unsigned char> sectors)
{
	writeSectors(startSector, sectorCount, sectors.data());
}
