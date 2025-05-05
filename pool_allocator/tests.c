#include "pool_allocator_func.h"

void test_init() {
  PoolAllocator allocator;
  const size_t block_size = 64;
  const size_t num_blocks = 10;

  pool_init(&allocator, block_size, num_blocks);

  assert(allocator.memory_pool != NULL);
  assert(allocator.block_size == block_size);
  assert(allocator.num_blocks == num_blocks);
  assert(allocator.free_list != NULL);

  pool_destroy(&allocator);
}

void test_alloc_all() {
  PoolAllocator allocator;
  const size_t block_size = 64;
  const size_t num_blocks = 5;

  pool_init(&allocator, block_size, num_blocks);

  void *blocks[num_blocks];

  for (size_t i = 0; i < num_blocks; i++) {
    blocks[i] = pool_alloc(&allocator);
    assert(blocks[i] != NULL);
  }

  assert(pool_alloc(&allocator) == NULL);

  pool_destroy(&allocator);
}

void test_reuse() {
  PoolAllocator allocator;
  const size_t block_size = 64;
  const size_t num_block = 3;

  pool_init(&allocator, block_size, num_block);
  void *block1 = pool_alloc(&allocator);
  void *block2 = pool_alloc(&allocator);
  void *block3 = pool_alloc(&allocator);

  memset(block1, 0xAA, block_size);
  memset(block2, 0xBB, block_size);
  memset(block3, 0xCC, block_size);

  pool_free(&allocator, block2);

  void *reused_block = pool_alloc(&allocator);
  assert(reused_block != NULL);

  assert(reused_block == block2);

  // unsigned char *bytes = (unsigned char *)reused_block;
  // assert(bytes[0] == 0xBB);

  pool_destroy(&allocator);
}

void test_free_all() {
  PoolAllocator allocator;
  const size_t block_size = 64;
  const size_t num_blocks = 4;

  pool_init(&allocator, block_size, num_blocks);

  void *blocks[num_blocks];

  for (size_t i = 0; i < num_blocks; i++) {
    blocks[i] = pool_alloc(&allocator);
  }
  for (size_t i = 0; i < num_blocks; i++) {
    pool_free(&allocator, blocks[i]);
  }
  for (size_t i = 0; i < num_blocks; i++) {
    assert(pool_alloc(&allocator) != NULL);
  }

  pool_destroy(&allocator);
}

void test_memory_boundaries() {
  PoolAllocator allocator;
  const size_t block_size = 32;
  const size_t num_blocks = 2;

  pool_init(&allocator, block_size, num_blocks);

  void *block1 = pool_alloc(&allocator);
  void *block2 = pool_alloc(&allocator);

  char *b1 = (char *)block1;
  char *b2 = (char *)block2;
  assert((b2 - b1) >= (ptrdiff_t)block_size);

  pool_destroy(&allocator);
}

void test_double_destroy() {
  PoolAllocator allocator;
  const size_t block_size = 16;
  const size_t num_blocks = 1;

  pool_init(&allocator, block_size, num_blocks);
  pool_destroy(&allocator);
  pool_destroy(&allocator);
}

int main() {
  test_init();
  test_alloc_all();
  test_reuse();
  test_free_all();
  test_memory_boundaries();
  test_double_destroy();

  printf("All tests success");
  return 0;
}