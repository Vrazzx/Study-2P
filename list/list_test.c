#include "list.h"
#include <assert.h>
#include <stdio.h>

void test_insert_front()
{
    Node* spisok = list_create();
    insert_front(&spisok, 10);
    insert_front(&spisok, 20);
    
    int err;
    assert(get(spisok, 0, &err) == 20);
    assert(get(spisok, 1, &err) == 10);
    assert(list_size(spisok) == 2);
    
    list_destroy(&spisok);
}

void test_insert_back()
{
    Node* spisok = list_create();
    insert_back(&spisok, 10);
    insert_back(&spisok, 20);
    
    int err;
    assert(get(spisok, 0, &err) == 10);
    assert(get(spisok, 1, &err) == 20);
    assert(list_size(spisok) == 2);
    
    list_destroy(&spisok);
}

void test_insert_at()
{
    Node* spisok = list_create();
    insert_at(&spisok, 5, 30);
    insert_at(&spisok, 0, 10);
    insert_at(&spisok, 2, 20);
    insert_at(&spisok, 1, 15);
    
    int err;
    assert(get(spisok, 0, &err) == 10);
    assert(get(spisok, 1, &err) == 15);
    assert(get(spisok, 2, &err) == 30);
    assert(get(spisok, 3, &err) == 20);
    
    list_destroy(&spisok);
}

void test_delete()
{
    Node* spisok = list_create();
    insert_back(&spisok, 10);
    insert_back(&spisok, 20);
    insert_back(&spisok, 30);
    
    delete_at(&spisok, 1);
    assert(list_size(spisok) == 2);
    int err;
    assert(get(spisok, 1, &err) == 30);
    
    delete_at(&spisok, 0);
    assert(list_size(spisok) == 1);
    
    list_destroy(&spisok);
}

int main()
{
    test_insert_front();
    test_insert_back();
    test_insert_at();
    test_delete();
    printf("Everything is completed!\n");
    return 0;
}
