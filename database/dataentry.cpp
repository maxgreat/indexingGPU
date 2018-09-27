#include "dataentry.h"
#include <cuda.h>
#include <cuda_runtime_api.h>

using namespace std;

float * readData(string& FileName, int size_t /* =-1 */){
	// TODO
	return nullptr;
}

DataEntry::DataEntry(unsigned int size){
	this->size = size;
	
	d = (float*)malloc(size);


	if(d == nullptr){
		std::cerr << "Can't alloc with size" << size; 
		this->size = 0;
	}
}

DataEntry::~DataEntry(){
	free(d);
}

bool DataEntry::changeSize(unsigned int new_size){
	this->size = new_size;
	d = (float*)realloc(d, new_size);
	if(d == nullptr){
		cerr << "Can't realloc with size" << new_size;
		this->size = 0;
		return false;
	}
	return true;
}

bool DataEntry::changeData(float* newData, unsigned int size){
	//TODO
	return false;
}
	
float* DataEntry::access(unsigned int offset /* =0 */) const {
	return d + (offset%this->size);
}

void DataEntry::print(std::ostream& out) const {
	out << size << ': [';
	for (auto i = 0; i < size; i++)
		out << d[i] << " : ";
	out << "]";
}

std::ostream& operator<< (std::ostream &out, DataEntry const& data){
	data.print(out);
	return out;
}




/* ************************************************************
*
*
* 	GPU Part
*
*
************************************************************ */
#ifdef with_cuda
DataEntryGPU::DataEntryGPU(unsigned int size){
	this->size = size;
	
	// Alloc Unified Memory
	cudaMallocManaged((void**)&d, size);

	if(d == nullptr){
		std::cerr << "Can't alloc with size" << size; 
		this->size = 0;
	}
}



DataEntry::~DataEntry(){
	cudaFree(d);
}








#endif




