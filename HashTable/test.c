#include "HashTable.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

void test_hashtable_basic()
{
    PoolAllocator allocator;
    size_t total_size = sizeof(HashTableEntry) + sizeof(int);
    pool_init(&allocator, total_size, 10);
    
    HashTable table;
    hashtable_init(&table, 5, &allocator);
    
    int value1 = 42;
    hashtable_insert(&table, "key1", &value1);
    int* found = hashtable_get(&table, "key1");
    assert(found != NULL && *found == 42);
    
    int value2 = 100;
    hashtable_insert(&table, "key1", &value2);
    found = hashtable_get(&table, "key1");
    assert(*found == 100);
    
    hashtable_del(&table, "key1");
    assert(hashtable_get(&table, "key1") == NULL);
    
    char* keys[] = {"apple", "banana", "cherry"};
    int values[] = {1, 2, 3};
    for (int i = 0; i < 3; i++)
    {
        hashtable_insert(&table, keys[i], &values[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        int* v = hashtable_get(&table, keys[i]);
        assert(*v == values[i]);
    }
    
    hashtable_free(&table);
    pool_destroy(&allocator);
}

void test_hashtable_collisions()
{
    PoolAllocator allocator;
    size_t total_size = sizeof(HashTableEntry) + sizeof(int);
    pool_init(&allocator, total_size, 5);
    
    HashTable table;
    hashtable_init(&table, 2, &allocator);
    
    int v1 = 1, v2 = 2, v3 = 3;
    hashtable_insert(&table, "a", &v1);
    hashtable_insert(&table, "b", &v2);
    hashtable_insert(&table, "c", &v3);
    
    int* val = hashtable_get(&table, "a");
    assert(val != NULL && *val == v1);
    
    val = hashtable_get(&table, "b");
    assert(val != NULL && *val == v2);
    
    val = hashtable_get(&table, "c");
    assert(val != NULL && *val == v3);
    
    hashtable_free(&table);
    pool_destroy(&allocator);
}

void test_hashtable_allocator()
{
    PoolAllocator allocator;
    size_t total_size = sizeof(HashTableEntry) + sizeof(int);
    pool_init(&allocator, total_size, 3);
    
    HashTable table;
    hashtable_init(&table, 5, &allocator);
    
    int v1 = 1, v2 = 2, v3 = 3;
    hashtable_insert(&table, "one", &v1);
    hashtable_insert(&table, "two", &v2);
    hashtable_insert(&table, "three", &v3);
    
    int v4 = 4;
    hashtable_insert(&table, "four", &v4);
    
    hashtable_del(&table, "two");
    
    hashtable_insert(&table, "four", &v4);
    int* val = hashtable_get(&table, "four");
    assert(val != NULL && *val == v4);
    
    hashtable_free(&table);
    pool_destroy(&allocator);
}

int main()
{
    test_hashtable_basic();
    test_hashtable_collisions();
    test_hashtable_allocator();
    printf("All tests passed!\n");
    return 0;
}
