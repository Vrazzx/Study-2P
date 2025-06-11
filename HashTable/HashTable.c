#include "HashTable.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

static size_t hash_func(const char* key, size_t capacity)
{
    size_t hash = 5381;
    int c;
    while ((c = *key++))
    {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % capacity;
}

void hashtable_init(HashTable* table, size_t capacity, PoolAllocator* allocator)
{
    table->capacity = capacity;
    table->allocator = allocator;
    table->buckets = calloc(capacity, sizeof(HashTableEntry*));
    assert(table->buckets != NULL && "Bucket allocation failed");

    table->value_size = table->allocator->block_size - sizeof(HashTableEntry);
}

void hashtable_insert(HashTable* table, const char* key, void* value)
{
    size_t index = hash_func(key, table->capacity);
    size_t value_size = table->value_size;

    HashTableEntry* current = table->buckets[index];
    while (current)
    {
        if (strcmp(current->key, key) == 0)
        {
            memcpy(current->value, value, value_size);
            return;
        }
        current = current->next;
    }

    HashTableEntry* new_entry = pool_alloc(table->allocator);
    assert(new_entry != NULL && "Allocation failed");

    new_entry->key = strdup(key);
    new_entry->value = (char*)new_entry + sizeof(HashTableEntry);
    memcpy(new_entry->value, value, value_size);

    new_entry->next = table->buckets[index];
    table->buckets[index] = new_entry;
}

void* hashtable_get(HashTable* table, const char* key)
{
    size_t index = hash_func(key, table->capacity);
    HashTableEntry* current = table->buckets[index];
    
    while (current)
    {
        if (strcmp(current->key, key) == 0)
        {
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}

void hashtable_del(HashTable* table, const char* key)
{
    size_t index = hash_func(key, table->capacity);
    HashTableEntry* current = table->buckets[index];
    HashTableEntry* prev = NULL;
    
    while (current)
    {
        if (strcmp(current->key, key) == 0)
        {
            if (prev)
            {
                prev->next = current->next;
            }
            else
            {
                table->buckets[index] = current->next;
            }
            
            free(current->key);
            pool_free(table->allocator, current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void hashtable_free(HashTable* table)
{
    for (size_t i = 0; i < table->capacity; i++)
    {
        HashTableEntry* current = table->buckets[i];
        while (current)
        {
            HashTableEntry* next = current->next;
            free(current->key);
            pool_free(table->allocator, current);
            current = next;
        }
    }
    free(table->buckets);
    table->buckets = NULL;
    table->capacity = 0;
    table->allocator = NULL;
}
