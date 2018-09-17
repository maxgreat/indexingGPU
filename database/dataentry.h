#ifndef dataentry
#define dataentry

#include <string>
#include <cstddef>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

std::byte* readData(std::string& FileName, int max_size=-1); // Read binary data from FileName

class DataEntry{
	/* General data entry, with attributes : size and data */

	public:
	DataEntry(unsigned int size);
	~DataEntry();
	bool changeSize(unsigned int new_size);
	bool changeData(std::byte* newData);
	
	std::byte* access(unsigned int offset = 0) const;

	private:	
	int size;
	std::byte* d; 
	
};


#ifdef with_cuda
class DataEntryGPU{
	/* General data entry, with attributes : size and data */

	public:
	DataEntryGPU(unsigned int size);
	~DataEntryGPU();

	private:
	int size;
	std::byte* d; 
	
};
#endif

#endif
