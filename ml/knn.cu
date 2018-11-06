#include "knn.h"

DataEntry& naive_knn(DataEntry& E, DataBase& dB){ 
	size_t closest = 0;
	float dist = E.distance(dB[0]);
	float new_dist;
	
	for(auto i=1; i < dB.getSize(); i++){
		if( (new_dist=E.distance(dB[i])) < dist){
			dist = new_dist;
			closest = i;
		}
	}
	return dB[closest];
}
