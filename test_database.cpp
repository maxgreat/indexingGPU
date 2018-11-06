#include "database/database.h"
#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	cout << "Unit test of DataBase" << endl;
	DataBase db;
	db.createNEntries(10);
	cout << "DataBase of :" << db.getNbEntries() << "entries";
	cout << "of size " << db.getSize() << endl;
	return 0;

}
