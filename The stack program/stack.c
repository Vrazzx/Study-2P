#include <stdio.h>
#include "stack.h"
#include <stdlib.h> // нужно для exit(1)
#include <stdbool.h> // возможность использовать bool
#include <assert.h>
#define StackLength 100 

// сделал каунт равный 0 т.к нормальный счёт идёт с нуля

void init(stack *stack) {
    stack->count = 0;
}

bool is_empty(stack *stack) {
    if (stack->count == 0) { // тут и так понятно, что это просто проверка на отсутствие элементов
        return true;
    }
    return false;
}

// вообще говоря, здесь вполне могла быть функци is_full, которая бы проверяла стек на заполненность, но уже стало лень её писать
// ограничимся условием if (stack->count == StackLenght)

void push(stack *stack, int value) {
    if (stack->count == StackLength) { // проверка стека на полное заполнение, т.е кол-во элементов в нём равно максимуму
       printf("\nСтек переполнен, закрытие программы\n");
       exit(1);
    }
    stack->array[stack->count] = value;
    stack->count++;

    // кидаем аргумент в стек и увеличиваем количество элементов в стэке с индексом верхушки
}

int pop(stack *stack) {

    if (is_empty(stack) == true) {
        printf("\nСтек пуст, нечего вытаскивать, закрытие программы\n");
        exit(1);
    }
    stack->count--;
    return stack->array[stack->count]; 

    // уменьшаем количество элементов в стеке с индексом верхушки
}

int peek(stack *stack) { // peek используется просто для тестов (возвращает, но не удаляет)
    if (is_empty(stack) == true) {
        printf("\nСтек пуст, нечего возвращать, закрытие программы\n");
        exit(1);
    }
    return stack->array[stack->count - 1]; // возвращаем последний элемент (-1 нужно, т.к счёт элементов идёт с нуля)
}

// часть кода с тестами

void push_test() { 
    stack my_stack;
    init(&my_stack);
    push(&my_stack, 10);

    // пушим десятку на верх стека и проверяем её пиком

    assert(peek(&my_stack) == 10); 
}

void pop_test() {
    stack my_stack;
    init(&my_stack);
    push(&my_stack, 10);
    push(&my_stack, 20);
    pop(&my_stack);

    // добавляем 2 элемента, а затем испытываем функцию pop

    assert(peek(&my_stack) == 10);
}

void is_empty_test() {
    stack my_stack;
    init(&my_stack);

    // проверка стека на пустоту и на наличие в нём хотя бы 1 элемента

    assert(is_empty(&my_stack) == true);
    push(&my_stack, 10);
    assert(is_empty(&my_stack) == false);
}


void main() {
    push_test();
    pop_test();
    is_empty_test();
}
