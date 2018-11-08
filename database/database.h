#ifndef database
#define database

#ifdef with_cuda
	#include <cuda.h>
	#include <cuda_runtime_api.h>
#endif

#include <string>
#include "dataentry.h"

class DataBase{

	public:
	DataBase();
	~DataBase();

	bool AddEntry(DataEntry& E);
	unsigned int createNEntries(unsigned int N);

	DataEntry& operator[](size_t offset) const{
		return tabData[offset%nb_entries];
	}

	size_t getSize() const {return sizeElement;}
	size_t getNbEntries() const {return nb_entries;}

	//TO DELETE
	std::string check();

#ifdef with_cuda
	unsigned int FindClosestGPU(DataEntryGPU* E);
	bool toCuda();
#endif

	private:
	size_t nb_entries;
	size_t sizeElement=5;
	DataEntry* tabData;
	bool onGPU;
#ifdef with_cuda
	DataEntryGPU* tabDataGPU;
#endif

};




#endif
