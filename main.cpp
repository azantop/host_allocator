#include <iostream>
#include <vector>
#include <cuda.h>
#include <cuda_runtime_api.h>

#include "cuda_host_allocator.hpp"

int main()
{
    std::vector< float, cuda_host_allocator< float >> numbers( 10 );

    float *some_cuda_array;
    cudaMalloc( (void**) &some_cuda_array, numbers.size() * sizeof( float ) );

    cudaMemcpy( some_cuda_array, numbers.data(), numbers.size() * sizeof( float ), cudaMemcpyHostToDevice );

    // do some calculations 
    
    cudaMemcpy( numbers.data(), some_cuda_array, numbers.size() * sizeof( float ), cudaMemcpyDeviceToHost );
}
