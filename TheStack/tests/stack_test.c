#include <assert.h>
#include "stack.h"
#include <stdio.h>

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


int main() {
    push_test();
    pop_test();
    is_empty_test();
    return 0;
}
