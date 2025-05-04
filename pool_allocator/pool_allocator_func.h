#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PoolAllocator {
  size_t block_size;
  size_t num_blocks;
  void *memory_pool;
  void *free_list;
} PoolAllocator;

void pool_init(PoolAllocator *allocator, size_t block_size, size_t num_blocks);
void *pool_alloc(PoolAllocator *allocator);
void pool_free(PoolAllocator *allocator, void *ptr);
void pool_destroy(PoolAllocator *allocator);
