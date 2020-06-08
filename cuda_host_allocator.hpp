#ifndef __CUDA_HOST_ALLOCATOR_HPP
#define __CUDA_HOST_ALLOCATOR_HPP

void* cuda_malloc_host( size_t );
void  cuda_free( void* );

template< class T >
struct cuda_host_allocator 
{
    typedef T value_type;
   
    cuda_host_allocator() = default;
    template< class U > constexpr 
    cuda_host_allocator( cuda_host_allocator< U > const& ) noexcept {}

    T* allocate( std::size_t n ) const 
    {
        return static_cast< T* >( cuda_malloc_host( n * sizeof( T ) ) );
    }

    void deallocate( T* p, std::size_t ) const
    { 
        cuda_free( p ); 
    }
};

template< class T, class U >
bool operator==( const cuda_host_allocator< T >&, const cuda_host_allocator< U >& ) { return true; }
template< class T, class U >
bool operator!=( const cuda_host_allocator< T >&, const cuda_host_allocator< U >& ) { return false; }

#endif // __CUDA_HOST_ALLOCATOR_HPP
