#include <stddef.h>

typedef struct {
    void* start_memory;
    size_t size;
    size_t offset;
} LinearAllocator;

void linear_init(LinearAllocator* allocator, void* start_memory, size_t size);
void* linear_alloc(LinearAllocator* allocator, size_t size);
void linear_reset(LinearAllocator* allocator);

void init_test();
void alloc_test();
void reset_test();
