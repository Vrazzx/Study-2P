#ifndef SPISOK_H
#define SPISOK_H

typedef struct Node Node;

// Создание/удаление списка
Node* spisok_create();
void spisok_destroy(Node** head);

// Операции
void insert_front(Node** head, int data);
void insert_back(Node** head, int data);
void insert_at(Node** head, int index, int data);
void delete_at(Node** head, int index);
int get(Node* head, int index, int* error);
int spisok_size(Node* head);

#endif
