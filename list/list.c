#include "list.h"
#include <stdlib.h>
#include <stdio.h>

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

int insert_front(Node** head, int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node)
    {
        return -1;
    }
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
    return 0;
}

int insert_back(Node** head, int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node)
    {
        return -1;
    }
    new_node->data = data;
    new_node->next = NULL;

    if (!*head)
    {
        *head = new_node;
        return 0;
    }

    Node* current = *head;
    while (current->next)
    {
        current = current->next;
    }
    current->next = new_node;
    return 0;
}

int insert_at(Node** head, int index, int data)
{
    if (index <= 0)
    {
        return insert_front(head, data);
    }

    Node* current = *head;
    for (int i = 0; current && i < index-1; ++i)
    {
        current = current->next;
    }

    if (!current)
    {
        return insert_back(head, data);
    }

    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node)
    {
        return -1;
    }
    new_node->data = data;
    new_node->next = current->next;
    current->next = new_node;
    return 0;
}

int delete_at(Node** head, int index)
{
    if (!*head || index < 0)
    {
        return -2;
    }

    if (index == 0)
    {
        Node* victim = *head;
        *head = (*head)->next;
        free(victim);
        return 0;
    }

    Node* current = *head;
    for (int i = 0; current && i < index-1; ++i)
    {
        current = current->next;
    }

    if (!current || !current->next)
    {
        return -2;
    }

    Node* victim = current->next;
    current->next = victim->next;
    free(victim);
    return 0;
}

int get(Node* head, int index, int* error)
{
    *error = 0;
    if (index < 0)
    {
        *error = -2;
        return 0;
    }

    Node* current = head;
    for (int i = 0; current && i < index; ++i)
    {
        current = current->next;
    }

    if (!current)
    {
        *error = -2;
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
