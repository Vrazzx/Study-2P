#include "spisok.h"  // Подключение заголовочного файла с объявлениями списка
#include <stdlib.h>  // Для работы с динамической памятью и exit()
#include <stdio.h>   // Для функции perror()

// Объявление структуры узла списка
struct Node
{
    int data;     // Поле для хранения данных узла
    Node* next;   // Указатель на следующий узел в списке
};

// Создание пустого списка
Node* spisok_create()
{
    return NULL;  // Пустой список представлен нулевым указателем
}

// Полное удаление списка
void spisok_destroy(Node** head)
{
    Node* code = *head;  // Начинаем с головы списка
    while (code)         // Пока не дойдем до конца списка
    {
        Node* unit = code;  // Запоминаем текущий узел для удаления
        code = code->next; // Переходим к следующему узлу
        free(unit);            // Освобождаем память текущего узла
    }
    *head = NULL; // Обнуляем указатель на голову после удаления
}

// Вставка элемента в начало списка
void insert_front(Node** head, int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node)); // Выделяем память под новый узел
    if (!new_node) // Проверяем успешность выделения памяти
    {
        perror("Ошибка."); // Выводим сообщение об ошибке
        exit(EXIT_FAILURE);     // Аварийно завершаем программу
    }
    new_node->data = data;  // Записываем данные в новый узел
    new_node->next = *head; // Новый узел указывает на старую голову
    *head = new_node;       // Новый узел становится новой головой
}

// Вставка элемента в конец списка
void insert_back(Node** head, int data)
{
    Node* new_node = (Node*)malloc(sizeof(Node)); // Выделяем память под новый узел
    if (!new_node) // Проверка ошибки выделения памяти
    {
        perror("Ошибка.");
        exit(EXIT_FAILURE);
    }
    new_node->data = data; // Инициализация данных нового узла
    new_node->next = NULL; // Новый узел будет последним (next = NULL)
    
    if (!*head) // Если список пустой
    {
        *head = new_node; // Новый узел становится головой
        return;
    }
    Node* code = *head;          // Начинаем с головы списка
    while (code->next)           // Идем до последнего узла
    {
        code = code->next;    // Переход к следующему узлу
    }
    code->next = new_node;       // Добавляем новый узел в конец
}

// Вставка элемента по указанному индексу
void insert_at(Node** head, int index, int data)
{
    if (index <= 0) // Если индекс 0 или отрицательный
    {
        insert_front(head, data); // Вставляем в начало
        return;
    }
    Node* code = *head; // Начинаем с головы
    // Ищем узел ПЕРЕД нужной позицией (index-1)
    for (int i = 0; code && i < index-1; ++i)
    {
        code = code->next; // Перемещаемся к следующему узлу
    }
    if (!code) // Если вышли за пределы списка
    {
        insert_back(head, data); // Вставляем в конец
        return;
    }
    Node* new_node = (Node*)malloc(sizeof(Node)); // Создаем новый узел
    if (!new_node) // Проверка выделения памяти
    {
        perror("Ошибка.");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;       // Заполняем данные
    new_node->next = code->next; // Новый узел указывает на следующий у code
    code->next = new_node;    // code теперь указывает на новый узел
}

// Удаление элемента по индексу
void delete_at(Node** head, int index)
{
    if (!*head || index < 0) return; // Если список пуст или индекс невалидный
    
    if (index == 0) // Удаление головы списка
    {
        Node* unit = *head;   // Запоминаем текущую голову
        *head = (*head)->next;  // Новая голова - следующий элемент
        free(unit);           // Удаляем старую голову
        return;
    }
    Node* code = *head; // Начинаем с головы
    // Ищем узел ПЕРЕД удаляемым (index-1)
    for (int i = 0; code && i < index-1; ++i)
    {
        code = code->next; // Переход к следующему узлу
    }

    if (!code || !code->next) return; // Проверка валидности индекса
    
    Node* unit = code->next;     // Запоминаем удаляемый узел
    code->next = unit->next;    // "Перепрыгиваем" через удаляемый узел
    free(unit);                    // Освобождаем память
}

// Получение элемента по индексу
int get(Node* head, int index, int* error)
{
    *error = 0;           // По умолчанию ошибки нет
    Node* code = head; // Начинаем с головы
    // Перемещаемся до нужного индекса
    for (int i = 0; code && i < index; ++i)
    {
        code = code->next; // Переход к следующему узлу
    }
    if (!code) // Если индекс вне диапазона
    {
        *error = -1; // Устанавливаем флаг ошибки
        return 0;    // Возвращаем 0 как значение по умолчанию
    }
    return code->data; // Возвращаем данные найденного узла
}

// Подсчет количества элементов в списке
int spisok_size(Node* head)
{
    int count = 0;        // Инициализация счетчика
    Node* code = head; // Начинаем с головы
    while (code)       // Пока не дойдем до конца
    {
        ++count;                // Увеличиваем счетчик
        code = code->next; // Переход к следующему узлу
    }
    return count; // Возвращаем итоговое количество
}
