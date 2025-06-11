#ifndef LIST_H
#define LIST_H

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* list_create();
void list_destroy(Node** head);

int insert_front(Node** head, int data);
int insert_back(Node** head, int data);
int insert_at(Node** head, int index, int data);
int delete_at(Node** head, int index);
int get(Node* head, int index, int* error);
int list_size(Node* head);

#endif
