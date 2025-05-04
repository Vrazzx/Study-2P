#include <pool_allocator_func.h>

void pool_init(PoolAllocator *allocator, size_t block_size, size_t num_blocks) {
  assert(allocator != NULL);
  assert(block_size > 0);
  assert(num_blocks > 0);

  allocator->memory_pool = malloc(block_size * num_blocks);
  assert(allocator->memory_pool != NULL && "Memory allocation failed");

  allocator->block_size = block_size;
  allocator->num_blocks = num_blocks;

  allocator->free_list = allocator->memory_pool;

  char *current = (char *)allocator->memory_pool;
  for (size_t i = 0; i < num_blocks - 1; ++i) {
    void **next = (void **)(current);
    *next = (void *)(current + block_size);
    current += block_size;
  }
  void **last = (void **)(current);
  *last = NULL;
}

void *pool_alloc(PoolAllocator *allocator) {
  assert(allocator != NULL);

  if (allocator->free_list != NULL) {
    void *block = allocator->free_list;
    allocator->free_list = *(void **)block;
    return block;
  }

  return NULL;
}

void pool_free(PoolAllocator *allocator, void *ptr) {
  assert(allocator != NULL);
  assert(ptr != NULL);

  char *pool_start = (char *)allocator->memory_pool;
  char *pool_end = pool_start + allocator->block_size * allocator->num_blocks;
  char *block = (char *)ptr;

  assert(block >= pool_start && block < pool_end &&
         "Pointer does not belong to this pool");
  assert((block - pool_start) % allocator->block_size == 0 &&
         "Pointer is not aligned to block boundary");

  *(void **)ptr = allocator->free_list;
  allocator->free_list = ptr;
}

void pool_destroy(PoolAllocator *allocator) {
  assert(allocator != NULL);
  free(allocator->memory_pool);
  allocator->memory_pool = NULL;
  allocator->free_list = NULL;
  allocator->block_size = 0;
  allocator->num_blocks = 0;
}
