#ifndef dataentry
#define dataentry

#include <string>
#include <cstddef>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

float* readData(std::string& FileName, int max_size=-1); // Read binary data from FileName


class DataEntry{
	/* General data entry, with attributes : size and data */

	public:
	DataEntry(unsigned int size);
	~DataEntry();
	bool changeSize(unsigned int new_size);
	bool changeData(float* newData, unsigned int size);
	
	float* access(unsigned int offset = 0) const;


	void print(std::ostream& out) const;

	private:	
	int size;
	float* d; //array of data 
	
};


std::ostream& operator<< (std::ostream &out, DataEntry const& data);


#ifdef with_cuda
class DataEntryGPU{
	/* General data entry, with attributes : size and data */

	public:
	DataEntryGPU(unsigned int size);
	~DataEntryGPU();

	private:
	int size;
	float * d; //data array on GPU 
	
};
#endif

#endif
