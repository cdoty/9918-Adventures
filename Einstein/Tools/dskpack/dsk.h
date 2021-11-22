#pragma once

#include<string>
#include<vector>

#include "disk.h"

using namespace std;

class dsk : public disk
{
	std::vector<unsigned char> _raw;

	bool parse();

public:
	dsk() { }
	virtual ~dsk() { }

	virtual bool load(string fileName);
	virtual bool save(string fileName);

	virtual void init(int tracks, int sectors, int bytesPerSector);
	
	bool cloneSectorsFrom(dsk& other);

	void diag(void(*logger)(string));
};
