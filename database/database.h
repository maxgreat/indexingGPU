#ifndef database
#define database

#include "dataentry.h"



class DataBase{

	public:
	DataBase();
	~DataBase();

	bool AddEntry(DataEntry* E);

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
