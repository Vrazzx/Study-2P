#include "list.h"
#include <assert.h>
#include <stdio.h>

void test_insert_front()
{
    Node* list = list_create();
    
    int result = insert_front(&list, 10);
    assert(result == 0);
    result = insert_front(&list, 20);
    assert(result == 0);
    
    int error;
    assert(get(list, 0, &error) == 20);
    assert(error == 0);
    assert(get(list, 1, &error) == 10);
    assert(error == 0);
    assert(list_size(list) == 2);
    
    list_destroy(&list);
}

void test_insert_back()
{
    Node* list = list_create();
    
    int result = insert_back(&list, 10);
    assert(result == 0);
    result = insert_back(&list, 20);
    assert(result == 0);
    
    int error;
    assert(get(list, 0, &error) == 10);
    assert(error == 0);
    assert(get(list, 1, &error) == 20);
    assert(error == 0);
    assert(list_size(list) == 2);
    
    list_destroy(&list);
}

void test_insert_at()
{
    Node* list = list_create();
    
    int result = insert_at(&list, 0, 10);
    assert(result == 0);
    result = insert_at(&list, 1, 30);
    assert(result == 0);
    result = insert_at(&list, 1, 20);
    assert(result == 0);
    
    int error;
    assert(get(list, 0, &error) == 10);
    assert(error == 0);
    assert(get(list, 1, &error) == 20);
    assert(error == 0);
    assert(get(list, 2, &error) == 30);
    assert(error == 0);
    
    list_destroy(&list);
}

void test_delete()
{
    Node* list = list_create();
    insert_back(&list, 10);
    insert_back(&list, 20);
    insert_back(&list, 30);
    
    int result = delete_at(&list, 1);
    assert(result == 0);
    assert(list_size(list) == 2);
    
    int error;
    assert(get(list, 0, &error) == 10);
    assert(error == 0);
    assert(get(list, 1, &error) == 30);
    assert(error == 0);

    result = delete_at(&list, 5);
    assert(result == -2);
    
    list_destroy(&list);
}

void test_errors()
{
    Node* list = list_create();

    int error;
    int value = get(list, 5, &error);
    assert(error == -2);
    assert(value == 0);

    int result = delete_at(&list, 0);
    assert(result == -2);
    
    list_destroy(&list);
}

int main()
{
    test_insert_front();
    test_insert_back();
    test_insert_at();
    test_delete();
    test_errors();
    printf("Everything is completed!\n");
    return 0;
}
