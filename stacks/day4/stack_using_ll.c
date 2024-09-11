#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Stack {
    struct Node* head;
} Stack;

struct Node* createNode(int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (!new_node) {
        printf("\nMemory allocation failed\n");
        exit(1);
    }
    new_node->data = new_data;
    new_node->next = NULL;
    return new_node;
}

void initializeStack(Stack* stack) {
    stack->head = NULL;
}

int isEmpty(Stack* stack) {
    return stack->head == NULL;
}

void push(Stack* stack, int new_data) {
    struct Node* new_node = createNode(new_data);
    new_node->next = stack->head;
    stack->head = new_node;
}

void pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("\nStack Underflow\n");
        return;
    }
    struct Node* temp = stack->head;
    stack->head = stack->head->next;
    free(temp);
}

int peek(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->head->data;
    } else {
        printf("\nStack is empty\n");
        return INT_MIN;
    }
}

int main() {
    Stack stack;
    initializeStack(&stack);
    
    push(&stack, 11);
    push(&stack, 22);
    push(&stack, 33);
    push(&stack, 44);

    printf("Top element is %d\n", peek(&stack));
  
    printf("Removing two elements...\n");
    pop(&stack);
    pop(&stack);

    printf("Top element is %d\n", peek(&stack));

    return 0;
}
