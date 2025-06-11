#include "linear_allocator.h"
#include <stdio.h>
#include <assert.h>

void init_test() {
    char startMem[1024];
    LinearAllocator allocator;
    linear_init(&allocator, startMem, 1024);
    assert(allocator.start_memory == startMem);
    assert(allocator.size == 1024);
    assert(allocator.offset == 0);
}
void alloc_test() {
    char startMem[1024];
    LinearAllocator allocator;
    linear_init(&allocator, startMem, 1024);
    int* ptr = (int*)linear_alloc(&allocator, sizeof(int));
    assert(int_ptr != NULL);
    *ptr = 20;
    assert(*ptr == 20);
    assert(allocator.offset == sizeof(int));
}
void reset_test() {
    char startMem[1024];
    LinearAllocator allocator;
    linear_init(&allocator, startMem, 1024);
    linear_reset(&allocator);
    assert(allocator.offset == 0);
}

int main() {
    init_test();
    alloc_test();
    reset_test();
    return 0;
}
