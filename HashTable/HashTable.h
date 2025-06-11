#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stddef.h>

typedef struct PoolAllocator
{
    void* memory_pool;
    void* free_list;
    size_t block_size;
    size_t num_blocks;
} PoolAllocator;

typedef struct HashTableEntry
{
    char* key; 
    void* value;
    struct HashTableEntry* next;
} HashTableEntry;

typedef struct
{
    size_t capacity;
    HashTableEntry** buckets;
    PoolAllocator* allocator;
    size_t value_size;
} HashTable;

void hashtable_init(HashTable* table, size_t capacity, PoolAllocator* allocator);
void hashtable_insert(HashTable* table, const char* key, void* value);
void* hashtable_get(HashTable* table, const char* key);
void hashtable_del(HashTable* table, const char* key);
void hashtable_free(HashTable* table);

void pool_init(PoolAllocator *allocator, size_t block_size, size_t num_blocks);
void *pool_alloc(PoolAllocator *allocator);
void pool_free(PoolAllocator *allocator, void *ptr);
void pool_destroy(PoolAllocator *allocator);

#endif
