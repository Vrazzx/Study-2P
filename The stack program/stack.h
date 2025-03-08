#define StackLength 100
#include <stdbool.h>

/*инициализируем самму структуру стека (т.е что-то вроде класса в С#) */

typedef struct {
    int array[StackLength];
    int count;
    
    // сам стек состоит из главного массива и count
    // count обозначает сколько в данный момент элементов в стеке и при этом является индексом верхушки

} stack;

void init(stack *stack);
void push(stack *stack, int value);
int pop(stack *stack);
int peek(stack *stack);
bool is_empty(stack *stack); 

void pop_test();
void push_test();
void is_empty_test();