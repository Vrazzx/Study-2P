#include <assert.h>
#include "stack.h"
#include <stdio.h>

void push_test() { 
    stack my_stack;
    init(&my_stack, 5);
    push(&my_stack, 10);
    assert(peek(&my_stack, 10) == 10); 
}

void pop_test() {
    stack my_stack;
    init(&my_stack, 5);
    push(&my_stack, 10);
    push(&my_stack, 20);
    pop(&my_stack, 20);
    assert(peek(&my_stack, 10) == 10);
}

void is_empty_test() {
    stack my_stack;
    init(&my_stack, 5);
    assert(is_empty(&my_stack));
    push(&my_stack, 10);
    assert(!is_empty(&my_stack));
}

int main() {
    push_test();
    pop_test();
    is_empty_test();
    return 0;
}
