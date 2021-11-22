#pragma once

#include <string>
#include <vector>

using namespace std;

class disk
{
protected:
	vector<unsigned char> _raw;
	vector<unsigned char*> _sectorOffsets;

	int _trackCount;
	int _sectorsPerTrack;
	int _bytesPerSector;

	void setRawSectorPtr(int track, int sector, unsigned char* ptr);

public:
	disk() { }
	virtual ~disk() { }

	static vector<unsigned char> loadBytes(string filePath);
	static bool saveBytes(string filePath, vector<unsigned char> bytes);

	int size();
	int totalSectorCount();

	virtual void init(int tracks, int sectors, int bytesPerSector);

	virtual bool load(string fileName);
	virtual bool save(string fileName);

	vector<unsigned char> readSectors(int startSector, int sectorCount);
	void writeSectors(int startSector, int sectorCount, unsigned char* sectorData);
	void writeSectors(int startSector, int sectorCount, vector<unsigned char> sectors);
};
