#include <string>
#include <cstddef>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

byte* readData(string& FileName, int size_t=-1); 

class DataEntry{
	/* General data entry, with attributes : size and data */

	public:
	DataEntry( unsigned int size);
	~DataEntry();
	bool changeSize(unsigned int new_size);
	bool changeData(byte* newData);
	
	bool access(unsigned int offset=0) const;

	private:	
	int size_t;
	byte* d; 
	
};

