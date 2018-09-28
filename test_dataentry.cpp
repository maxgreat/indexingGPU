#include "database/dataentry.h"
#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	cout << "Unit test of DataEntry" << endl;
	DataEntry dE {10u};
	cout << "Entry of size 10: " << dE << endl;

#ifdef with_cuda
	cout << "Test CUDA loading" << endl;
	DataEntryGPU d_dE {10u};
	cout << d_dE << endl;
#endif
	return 0;

}
