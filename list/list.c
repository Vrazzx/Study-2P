#include "list.h" 
#include <stdlib.h> 
#include <stdio.h> 

struct Node
{
    int data;
    Node* next;
};

Node* list_create()
{
    return NULL;
}

void list_destroy(Node** head)
{
    Node* code = *head;
    while (code)
    {
        Node* unit = code;
        code = code->next;
        free(unit);
    }
    *head = NULL;
}

void insert_front(Node** head, int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node)
    {
        perror("ERROR.");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void insert_back(Node** head, int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node)
    {
        perror("ERROR.");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    
    if (!*head)
    {
        *head = new_node;
        return;
    }
    Node* code = *head;
    while (code->next)
    {
        code = code->next;
    }
    code->next = new_node;
}

void insert_at(Node** head, int index, int data)
{
    if (index <= 0)
    {
        insert_front(head, data);
        return;
    }
    Node* code = *head;
    for (int i = 0; code && i < index-1; ++i)
    {
        code = code->next;
    }
    if (!code)
    {
        insert_back(head, data);
        return;
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node)
    {
        perror("ERROR.");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = code->next;
    code->next = new_node;
}

void delete_at(Node** head, int index)
{
    if (!*head || index < 0) return;
    
    if (index == 0)
    {
        Node* unit = *head;
        *head = (*head)->next;
        free(unit);
        return;
    }
    Node* code = *head;
    for (int i = 0; code && i < index-1; ++i)
    {
        code = code->next;
    }

    if (!code || !code->next) return;
    
    Node* unit = code->next;
    code->next = unit->next;
    free(unit);
}

int get(Node* head, int index, int* error)
{
    *error = 0;
    Node* code = head;
    for (int i = 0; code && i < index; ++i)
    {
        code = code->next;
    }
    if (!code)
    {
        *error = -1;
        return 0;
    }
    return code->data;
}

int list_size(Node* head)
{
    int count = 0;
    Node* code = head;
    while (code)
    {
        ++count;
        code = code->next;
    }
    return count;
}
