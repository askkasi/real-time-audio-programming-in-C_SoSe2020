
#ifndef vas_memory_c
#define vas_memory_c

#include "vas_mem.h"

void *vas_mem_alloc(long size)
{
    
#ifdef MAXMSPSDK
    
    return sysmem_newptrclear(size);

#elif defined(PUREDATA)
    
    return malloc(size);
    
#else
    
    return malloc(size);
    
#endif
    
}

void *vas_mem_resize(void *ptr, long size)
{
    
#ifdef MAXMSPSDK
    
    return sysmem_resizeptrclear(ptr, size);
    
#elif defined(PUREDATA)

    void *tmp = realloc(ptr, size);
    memset(tmp, 0, size);
    return tmp;

    
#else

    void *tmp = realloc(ptr, size);
    memset(tmp, 0, size);
    return tmp;
 
#endif
    
}

void vas_mem_free(void *ptr)
{
    
#ifdef MAXMSPSDK
    if(ptr)
        sysmem_freeptr(ptr);
    
#elif defined(PUREDATA)
    if(ptr)
        free(ptr);
    
#else
    if(ptr)
        free(ptr);
    
#endif
    
}

#endif
