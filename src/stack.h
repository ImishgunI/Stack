#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

typedef struct stack {
    int value;
    struct stack* next;
} stack;

stack* init();
void push(stack** root, int value);
stack* pop(stack** node);
int top(stack* node);
int size(stack* node);
void clean(stack** node);
bool is_empty(stack* node);
#endif