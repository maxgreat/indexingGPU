#include "dataentry.h"

using namespace std;

byte* readData(string& FileName, int size_t /* =-1 */){
	// TODO
	return nullptr;
}

DataEntry::DataEntry(unsigned int size){
	size_t = size;
	
	d = (byte*)malloc(size);

	if(d == nullptr){
		std::cerr << "Can't alloc with size" << size; 
		this->size_t = 0;
	}
}

DataEntry::~DataEntry(){
	free(d);
}

bool DataEntry::changeSize(unsigned int new_size){
	size_t = new_size;
	d = (byte*)realloc(d, new_size);
	if(d == nullptr){
		cerr << "Can't realloc with size" << new_size;
		this->size_t = 0;
		return false;
	}
	return true;
}

bool DataEntry::changeData(byte* newData){
	//TODO
	return false;
}
	
byte* DataEntry::access(unsigned int offset /* =0 */) const {
	return d + (offset%this->size_t);
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
	size_t = size;
	
	d = (byte*)malloc(size);

	if(d == nullptr){
		std::cerr << "Can't alloc with size" << size; 
		this->size_t = 0;
	}
}
#endif



