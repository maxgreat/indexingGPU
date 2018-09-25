#include <string>
#include <cstddef>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

std::byte* readData(std::string& FileName, int size_t=-1); 

class DataEntry{
	/* General data entry, with attributes : size and data */

	public:
	DataEntry(unsigned int size);
	~DataEntry();
	bool changeSize(unsigned int new_size);
	bool changeData(std::byte* newData);
	
	std::byte* access(unsigned int offset = 0) const;

	private:	
	int size_t;
	std::byte* d; 
	
};

