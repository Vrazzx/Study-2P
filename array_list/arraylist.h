#include <stddef.h>
#include <string.h>

typedef struct chunk {
  struct chunk *next;
  char data[];
} chunk;

typedef struct {
  chunk *free_chunk;
  void *chunks;
  size_t chunks_num;
} pool_allocator;

pool_allocator *pool_init(size_t chunks_num, size_t chunk_size);
void *pool_alloc(pool_allocator *allocator);
void pool_free(pool_allocator *allocator, chunk *ptr);
void destruct_allocator(pool_allocator *allocator);
#define NULL_SIZE NULL
#define NOT_ENOUGH_MEMORY NULL

typedef struct {
  void *head;
  size_t element_size;
  size_t capacity;
  size_t size;
  pool_allocator *allocator;
} ArrayList;

#define INITIAL_CAPACITY 4
#define SUCCESS 0
#define ALLOC_ERROR 1
#define OUTSIDE_LIST 2
#define SIZE_ERROR 3

int arraylist_init(ArrayList *list, pool_allocator *allocator,
                   size_t element_size);
int arraylist_add(ArrayList *list, void *data, size_t index);
void *arraylist_get(ArrayList *list, size_t index);
int arraylist_del(ArrayList *list, size_t index);
int arraylist_free(ArrayList *list);
int expand(ArrayList *list);
