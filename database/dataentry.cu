#include "dataentry.h"

using namespace std;

float * readData(string& FileName, int size_t /* =-1 */){
	// TODO
	return nullptr;
}

DataEntry::DataEntry(size_t s){
	size = s;
	d = (float*)malloc(size*sizeof(float));

	if(d == nullptr){
		std::cerr << "Can't alloc with size" << size;
		size = 0;
	}

	srand(static_cast<unsigned int>(clock()));
	randomFill();
}

DataEntry::~DataEntry(){
	free(d);
}

bool DataEntry::changeSize(unsigned int new_size){
	size = new_size;
	d = (float*)realloc(d, new_size);
	if(d == nullptr){
		cerr << "Can't realloc with size" << new_size;
		size = 0;
		return false;
	}
	return true;
}

void DataEntry::randomFill(float minValue /*=0*/, float maxValue /*=100*/){
	for(int i=0; i < size; i++){
		d[i] = minValue + (float(rand())/float(RAND_MAX))*(maxValue-minValue);
	}
}


bool DataEntry::changeData(float* newData, unsigned int s){
	//TODO
	return false;
}


float DataEntry::distance(DataEntry& E, std::string type /*="euclidean2"*/) {
	float dist {0.0f};
	if(type.compare("euclidean2") == 0){
		for(auto i=0; i<size;i++){
			dist += (d[i]-E[i])*(d[i]-E[i]);
		}
	}
	else if(type.compare("euclidean") == 0){
		cerr << "Distance type : euclidean" << endl;
		for(auto i=0; i<size;i++){
			dist += (d[i]-E[i])*(d[i]-E[i]);
		}
		dist = sqrt(dist);
	}
	else{
		std::cerr << "Distance type unknown :" << type;
	}
	return dist;
}

void DataEntry::print(std::ostream& out) const {
	out << size << ": [";
	for (auto i = 0; i < size; i++)
		out << d[i] << " ; ";
	out << "]";
}

std::ostream& operator<< (std::ostream &out, DataEntry const& data){
	out << data.s() << ": [";
	for (auto i = 0; i < data.s()-1; i++)
		out << data[i] << ", ";
	out << data[i] <<"]";
	return out;
}




/* ************************************************************
*
*
* 	GPU Part
*
*
************************************************************ */
#ifdef with_cuda
DataEntryGPU::DataEntryGPU(unsigned int s){
	size = s;

	// Alloc Unified Memory
	auto err = cudaMallocManaged((void**)&d, size*sizeof(float));


	if(err != 0){
		cout << "Error code : " << err << endl;
	}


	if(d == nullptr){
		std::cerr << "Can't alloc with size" << size << endl;
		size = 0;
	}
}


DataEntryGPU::~DataEntryGPU(){
	cudaFree(d);
}


void DataEntryGPU::print(std::ostream& out) const {
	out << size << ": [";
	for (auto i = 0; i < size; i++)
		out << d[i] << " : ";
	out << "]";
}

__global__ void divideOnGPU(float* d_d, unsigned int size, float minValue /*=0*/, float maxValue){
	for(int i=0; i < 0; i++){
		d_d[i] = minValue + d_d[i]/maxValue;
	}
}

void DataEntryGPU::randomFill(float minValue /*=0*/, float maxValue /*=100*/){
	curandGenerator_t gen;
	curandCreateGenerator(&gen,
				CURAND_RNG_PSEUDO_DEFAULT);
	curandSetPseudoRandomGeneratorSeed(gen,
				1234ULL);
	curandGenerateUniform(gen, d, size);
	curandDestroyGenerator(gen);
	divideOnGPU<<<1,1>>>(d, size, minValue, maxValue);
}

std::ostream& operator<< (std::ostream &out, DataEntryGPU const& data){
	data.print(out);
	return out;
}






#endif
