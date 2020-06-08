#include <cstdlib>
#include <iostream>
#include <new>

#include <cuda.h>
#include <cuda_runtime_api.h>

void* cuda_malloc_host( size_t n )
{
    void* p = nullptr;
    cudaMallocHost( (void**) &p, n ); 

    cudaError_t error = cudaGetLastError();
    
    if ( error != 0 )
        throw std::bad_alloc();
    
    return p;
}

void cuda_free( void* p ) 
{ 
    cudaFreeHost( p ); 
        
    cudaError_t error = cudaGetLastError();

    if ( error != 0 )
        throw std::bad_alloc();
}

