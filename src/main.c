#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

void push_test();
void pop_test();
void size_test();
void clean_test();
void empty_test();
void top_test();

int main() {
#ifdef PUSH
    push_test();
#endif

#ifdef POP
    pop_test();
#endif

#ifdef SIZE
    size_test();
#endif

#ifdef CLEAN
    clean_test();
#endif

#ifdef EMPTY
    empty_test();
#endif

#ifdef TOP
    top_test();
#endif
}

void push_test() {
    stack* node = init();
    int value = 10;
    push(&node, value);
    if (node->value == value) {
        printf("Value: %d\n", value);
        printf("SUCCESS\n");
    } else {
        printf("Value: %d\n", value);
        printf("FAIL\n");
    }
}

void pop_test() {
    stack* node = init();
    int value = 10, value2 = 20, value3 = 30;
    push(&node, value);
    push(&node, value2);
    push(&node, value3);

    printf("Before pop: %d\n", node->value);
    stack* delete = pop(&node);
    if (delete != NULL) {
        printf("After pop: %d\n", node->value);
        printf("SUCCESS\n");
        free(delete);
    } else {
        printf("FAIL\n");
        free(delete);
    }
}

void size_test() {
    stack* node = init();
    int value = 10;
    push(&node, value);
    int len = size(node);
    if (len != 0) {
        printf("size is: %d\n", len);
        printf("SUCCESS");
    } else {
        printf("size is 0\n");
        printf("FAIL");
    }
}

void clean_test() {
    stack* node = init();
    int value = 10, value2 = 20, value3 = 30;
    push(&node, value);
    push(&node, value2);
    push(&node, value3);

    printf("Before clean size is: %d\n", size(node));
    clean(&node);
    int len = size(node);
    if (len == 0) {
        printf("After clean size is: %d\n", len);
        printf("SUCCESS");
    } else {
        printf("FAIL\n");
    }
}

void empty_test() {
    stack* node = init();
    if (is_empty(node)) {
        printf("stack is empty\n");
        printf("SUCCESS");
    } else {
        printf("FAIL");
    }
}

void top_test() {
    stack* node = init();
    int value = 10;
    push(&node, value);
    int number = top(node);
    if (node != NULL) {
        printf("value: %d\n", number);
        printf("SUCCESS");
    } else {
        printf("FAIL\n");
    }
}
