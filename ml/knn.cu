#include "knn.h"

#include <iostream>

DataEntry& naive_1nn(DataEntry& E, DataBase& dB){
	std::cout << "Entering naive_knn" << std::endl;
	size_t closest = 0;
	float dist = E.distance(dB[0]);

	float new_dist;

	for(auto i=1; i < dB.getSize(); i++){
		new_dist=E.distance(dB[i]);
		if( new_dist < dist){
			dist = new_dist;
			closest = i;
		}
	}
	return dB[closest];
}
