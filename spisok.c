#include "spisok.h"
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
    Node* current = *head;
    while (current)
    {
        Node* victim = current;
        current = current->next;
        free(victim);
    }
    *head = NULL;
}

void insert_front(Node** head, int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node)
    {
        perror("Memory error");
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
        perror("Memory error");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    if (!*head)
    {
        *head = new_node;
        return;
    }
    Node* current = *head;
    while (current->next)
    {
        current = current->next;
    }
    current->next = new_node;
}

void insert_at(Node** head, int index, int data)
{
    if (index <= 0)
    {
        insert_front(head, data);
        return;
    }
    Node* current = *head;
    for (int i = 0; current && i < index-1; ++i)
    {
        current = current->next;
    }
    if (!current)
    {
        insert_back(head, data);
        return;
    }
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node)
    {
        perror("Memory error");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = current->next;
    current->next = new_node;
}

void delete_at(Node** head, int index)
{
    if (!*head || index < 0) return;
    if (index == 0)
    {
        Node* victim = *head;
        *head = (*head)->next;
        free(victim);
        return;
    }
    Node* current = *head;
    for (int i = 0; current && i < index-1; ++i)
    {
        current = current->next;
    }

    if (!current || !current->next) return;
    Node* victim = current->next;
    current->next = victim->next;
    free(victim);
}

int get(Node* head, int index, int* error)
{
    *error = 0;
    Node* current = head;
    for (int i = 0; current && i < index; ++i)
    {
        current = current->next;
    }
    if (!current)
    {
        *error = -1;
        return 0;
    }
    return current->data;
}

int list_size(Node* head)
{
    int count = 0;
    Node* current = head;
    while (current)
    {
        ++count;
        current = current->next;
    }
    return count;
}
