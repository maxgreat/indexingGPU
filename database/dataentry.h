#ifndef dataentry
#define dataentry

#include <string>
#include <cstddef>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <stdexcept>


#ifdef with_cuda
	#include <cuda.h>
	#include <cuda_runtime_api.h>
	#include <curand.h>
#endif

/*
	We use float[] to have the same structure and cuda
*/

float* readData(std::string& FileName, int max_size=-1); // Read binary data from FileName


class DataEntry{
	/* General data entry, with attributes : size and data */


	public:
	DataEntry(size_t s);
	~DataEntry();
	bool changeSize(unsigned int new_size);
	void randomFill(float minValue=0, float maxValue=100);
	bool changeData(float* newData, unsigned int s);

	float& operator[](size_t offset) const{
		if(offset < size)
			return d[offset];
		else
			throw std::invalid_argument("Invalide offset for operator []");
	}

	float distance(DataEntry& E, std::string type="euclidean2");

	size_t s() const { return size;}

	private:
	size_t size;
	float * d; //array of data
	void print(std::ostream& out) const;


};


std::ostream& operator<< (std::ostream &out, DataEntry const& data);


#ifdef with_cuda
class DataEntryGPU{
	/* General data entry, with attributes : size and data */

	public:
	DataEntryGPU(unsigned int s);
	~DataEntryGPU();
	void print(std::ostream& out) const;

	void randomFill(float minValue=0, float maxValue=100);

	private:
	int size;
	float* d; //data array on GPU

};

std::ostream& operator<< (std::ostream &out, DataEntryGPU const& data);

#endif

#endif
