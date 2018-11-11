#include "database/database.h"
#include "ml/knn.h"
#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	cout << "Unit test of DataBase" << endl;
	DataBase db;
	db.createNEntries(10);
	cout << "DataBase of : " << db.getNbEntries() << " entries " << endl;
	cout << "of size : " << db.getSize() << endl;

	cout << "Print database :" << endl;
	for(auto i=0; i < db.getNbEntries(); i++){
		cout << db[i] << endl;
	}


	DataEntry nEntry = DataEntry(5);
	cout << "The closest to :" << nEntry << endl;
	DataEntry& E = naive_1nn(nEntry, db);
	cout << "is : " << E << endl;

	return 0;

}
