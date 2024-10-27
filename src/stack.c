#include "stack.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

stack* init() {
    stack* root = NULL;
    return root;
}

void push(stack** root, int value) {
    stack* node = malloc(sizeof(stack));
    if (node == NULL) {
        printf("node is NULL");
        return;
    }

    node->next = *root;
    node->value = value;

    *root = node;
}

stack* pop(stack** node) {
    stack* after_delete;
    if (*node == NULL) {
        printf("stack is empty");
        return NULL;
    }
    after_delete = *node;
    *node = (*node)->next;
    return after_delete;
}

int top(stack* node) {
    if (node == NULL) {
        printf("empty stack");
        return 1;
    }
    return node->value;
}

int size(stack* node) {
    int length = 0;
    while (node != NULL) {
        node = node->next;
        length++;
    }
    return length;
}

void clean(stack** node) {
    stack* delete;
    if (*node == NULL) {
        printf("stack is empty");
        return;
    }
    while (*node != NULL) {
        delete = pop(node);
        free(delete);
    }
}

bool is_empty(stack* node) { return (node == NULL) ? true : false; }
