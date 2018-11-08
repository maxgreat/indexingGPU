#include "database.h"

#include <iostream>
using namespace std;


DataBase::DataBase(){
	onGPU = false;
	nb_entries=0;
	tabData = nullptr;
}

DataBase::~DataBase(){
	free(tabData);
#ifdef with_cuda
	if(onGPU){ cudaFree(tabDataGPU); }
#endif
}

bool DataBase::AddEntry(DataEntry& E){
	//TODO Verify size of E
	if (nb_entries == 0){
		#ifdef with_cuda
			tabData = (DataEntryGPU*)malloc(sizeof(DataEntryGPU));
		#else
			tabData = (DataEntry*)malloc(sizeof(DataEntry));
		#endif
		if (tabData == nullptr)
			return false;
		tabData[0] = E;
		nb_entries++;
	}
	else{
		#ifdef with_cuda
			tabData = (DataEntryGPU*)realloc(tabData, (nb_entries+1)*sizeof(DataEntryGPU));
		#else
			tabData = (DataEntry*)realloc(tabData, (nb_entries+1)*sizeof(DataEntry));
		#endif
		tabData[nb_entries] = E;
		nb_entries++;
	}
}

unsigned int DataBase::createNEntries(unsigned int N){
	for(auto i = 0; i < N; i++){
		DataEntry* E = new DataEntry(sizeElement);
		AddEntry(*E);
	}
}

std::string DataBase::check(){
	string s = "";
	for(auto i = 0; i < nb_entries; i++){
	 	s += std::to_string(tabData[i].s());
		s += "  ";
 	}
	return s;
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
