#include "spisok.h"
#include <assert.h>
#include <stdio.h>

void test_insert_front()
{
    Node* list = list_create();
    insert_front(&list, 10);
    insert_front(&list, 20);
    
    int err;
    assert(get(list, 0, &err) == 20);
    assert(get(list, 1, &err) == 10);
    assert(list_size(list) == 2);
    
    list_destroy(&list);
}

void test_insert_back()
{
    Node* list = list_create();
    insert_back(&list, 10);
    insert_back(&list, 20);
    
    int err;
    assert(get(list, 0, &err) == 10);
    assert(get(list, 1, &err) == 20);
    assert(list_size(list) == 2);
    
    list_destroy(&list);
}

void test_insert_at()
{
    Node* list = list_create();
    insert_at(&list, 5, 30); // В пустой список
    insert_at(&list, 0, 10); // В начало
    insert_at(&list, 2, 20); // В конец
    insert_at(&list, 1, 15); // В середину
    
    int err;
    assert(get(list, 0, &err) == 10);
    assert(get(list, 1, &err) == 15);
    assert(get(list, 2, &err) == 30);
    assert(get(list, 3, &err) == 20);
    
    list_destroy(&list);
}

void test_delete()
{
    Node* list = list_create();
    insert_back(&list, 10);
    insert_back(&list, 20);
    insert_back(&list, 30);
    
    delete_at(&list, 1);
    assert(list_size(list) == 2);
    int err;
    assert(get(list, 1, &err) == 30);
    
    delete_at(&list, 0);
    assert(list_size(list) == 1);
    
    list_destroy(&list);
}

int main()
{
    test_insert_front();
    test_insert_back();
    test_insert_at();
    test_delete();
    printf("All tests passed!\n");
    return 0;
}
