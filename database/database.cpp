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

bool DataBase::AddEntry(DataEntry& E){
	if (nb_entries < size){
		tabData[nb_entries] = E;
		nb_entries++;
		return true;
	}
	return false;
}

unsigned int DataBase::createNEntries(unsigned int N){
	nb_entries += N;

	for(auto i = 0; i < N; i++){
		DataEntry E{size};
		AddEntry(E);
	}

}

unsigned int DataBase::FindClosest(DataEntry& E){
	//TODO
	return 0;
}



/*
	CUDA PART
*/
#ifdef with_cuda
unsigned int DataBase::FindClosestGPU(DataEntryGPU* E){
	//TODO
	return 0;
}

bool DataBase::toCuda(){
	//TODO
	return false;
}
#endif
