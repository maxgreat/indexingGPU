#ifndef database
#define database

#ifdef with_cuda

#include <cuda.h>
#include <cuda_runtime_api.h>

#endif


#include "dataentry.h"



class DataBase{

	public:
	DataBase();
	~DataBase();

	bool AddEntry(DataEntry& E);
	unsigned int createNEntries(unsigned int N);

	unsigned int FindClosest(DataEntry& E);

	DataEntry& operator[](size_t offset) const{
		return tabData[offset%size];
	}

	size_t getSize() const {return size;}
	size_t getNbEntries() const {return nb_entries;}

#ifdef with_cuda
	unsigned int FindClosestGPU(DataEntryGPU* E);
	bool toCuda();
#endif

	private:
	size_t nb_entries;
	size_t size=10;
	DataEntry* tabData;
	bool onGPU;
#ifdef with_cuda
	DataEntryGPU* tabDataGPU;
#endif

};




#endif
