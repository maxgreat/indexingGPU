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

	bool AddEntry(DataEntry* E);
	unsigned int createNEntries(unsigned int N);

	unsigned int FindClosest(DataEntry* E);

#ifdef with_cuda
	unsigned int FindClosestGPU(DataEntryGPU* E);
	bool toCuda();
#endif	

	private:
	
	unsigned int nb_entries;
	unsigned int size;
	DataEntry** tabData;
	bool onGPU;
#ifdef with_cuda
	DataEntryGPU* tabDataGPU;
#endif

};




#endif
