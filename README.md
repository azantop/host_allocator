# host_allocator
A minimal C++ allocator based on cudaMallocHost(), for usage in std::vector or similar.
For faster memory transfers between the GPU and the host, CUDA offers page locked/pinned
memory allocation via cudaMallocHost(). 
To benefit from this when using a std::vector, use 
```
  std::vector< float, cuda_host_allocator< float >> numbers( 10 );
```
to define your std::vector. The memory of the std::vector will then be allocated with cudaMallocHost.
Both the .allocate() and .deallocate() member functions of the cuda_host_allocator class throw 
a std::bad_alloc when the allocation fails.
 
