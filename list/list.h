#ifndef LIST_H
#define LIST_H

typedef struct Node Node;

Node* list_create();
void list_destroy(Node** head);

void insert_front(Node** head, int data);
void insert_back(Node** head, int data);
void insert_at(Node** head, int index, int data);
void delete_at(Node** head, int index);
int get(Node* head, int index, int* error);
int list_size(Node* head);

#endif
