#include <stddef.h>
#include <assert.h>
#include <stdio.h>
#include "linear_allocator.h"

void linear_init(LinearAllocator* allocator, void* start_memory, size_t size) {
    assert(allocator != NULL);
    assert(start_memory != NULL);
    assert(size > 0);
    allocator->start_memory = start_memory;
    allocator->size = size;
    allocator->offset = 0;
}

void* linear_alloc(LinearAllocator* allocator, size_t size) {
    assert(allocator != NULL);
    
    if (size == 0) {
        return NULL;
    }

    if (allocator->offset + size > allocator->size) {
        return NULL;
    }
    void* ptr = (char*)allocator->start_memory + allocator->offset;
    allocator->offset += size;

    return ptr;
}

void linear_reset(LinearAllocator* allocator) {
    assert(allocator != NULL);
    allocator->offset = 0;
}
