#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void init(stack *stack, int size) {
    stack->top = 0;
    stack->size = size;
    stack->array = (int *)malloc(sizeof(int) * size);
}

int is_empty(stack *stack) {
    return stack->top == 0;
}

int is_full(stack *stack) {
    return stack->top == stack->size;
}

int push(stack *stack, int value) {
    if (is_full(stack)) {
        return -1;
    }
    stack->array[stack->top] = value;
    stack->top++;
    return 0;
}
int pop(stack *stack, int *value) {
    if (is_empty(stack)) {
        return -1;
    }
    stack->top--;
    *value = stack->array[stack->top];
    return 0;
}
int peek(stack *stack, int *value) {
    if (is_empty(stack)) {
        return -1;
    }
    *value = stack->array[stack->top - 1];
    return 0;
}
void freeStack(stack *stack) {
    free(stack->array);
}
