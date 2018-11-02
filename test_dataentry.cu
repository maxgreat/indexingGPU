#include "database/dataentry.h"
#include <iostream>
#include <cstdio>
#include <ctime>

#include <cuda.h>
#include <cuda_runtime_api.h>

using namespace std;

int main(){
	
	
	cout << "Unit test of DataEntry" << endl;
	DataEntry dE {10u};
	cout << "Entry of size 10: " << dE << endl;
	
	unsigned int size {200000000u};
	cout << "Test random fill on " << size*sizeof(float) << "bytes" << endl;
	DataEntry dE2 {size};
	auto c0 = clock();
	dE2.randomFill(1,10);  
	auto c1 = clock();
	cout << "randomFill in " << c1 - c0 << " clocks." << endl;

#ifdef with_cuda
	cout << "Test CUDA loading" << endl;
	DataEntryGPU d_dE {size};
	c0 = clock();
	d_dE.randomFill();  
	c1 = clock();
	cout << "randomFill in " << c1 - c0 << " clocks." << endl;
	//cout << d_dE << endl;
#endif
	return 0;

}

/*
#include <iostream>
#include <math.h>


#include <cuda.h>
#include <cuda_runtime_api.h>
// Kernel function to add the elements of two arrays
__global__
void add(int n, float *x, float *y)
{
  for (int i = 0; i < n; i++)
    y[i] = x[i] + y[i];
}

int main(void)
{
  int N = 1<<20;
  float *x, *y;

  // Allocate Unified Memory – accessible from CPU or GPU
  cudaMallocManaged((void**)&x, N*sizeof(float));
  cudaMallocManaged((void**)&y, N*sizeof(float));

  // initialize x and y arrays on the host
  for (int i = 0; i < N; i++) {
    x[i] = 1.0f;
    y[i] = 2.0f;
  }

  // Run kernel on 1M elements on the GPU
  add<<<1, 1>>>(N, x, y);

  // Wait for GPU to finish before accessing on host
  cudaDeviceSynchronize();

  // Check for errors (all values should be 3.0f)
  float maxError = 0.0f;
  for (int i = 0; i < N; i++)
    maxError = fmax(maxError, fabs(y[i]-3.0f));
  std::cout << "Max error: " << maxError << std::endl;

  // Free memory
  cudaFree(x);
  cudaFree(y);
  
  return 0;
}
*/