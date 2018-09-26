#include "database.h"

DataBase::DataBase(){
	onGPU = false;		
	nb_entries=0;
	size = 0;
	tabData = nullptr;
}

DataBase::~DataBase(){
	free(tabData);
#ifdef with_cuda
	if(onGPU){ cudaFree(tabDataGPU); }
#endif
}

bool DataBase::AddEntry(DataEntry* E){
	if (nb_entries < size){
		tabData[nb_entries] = E;
		nb_entries++;
		return true;
	}
	return false;
}

unsigned int DataBase::FindClosest(DataEntry* E){
	//TODO
	return 0;
}

#ifdef with_cuda
DataBase::FindClosestGPU(DataEntryGPU* E);
DataBase::toCuda();
#endif	