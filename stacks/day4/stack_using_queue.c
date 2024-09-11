#include<stdio.h>
#include<stdlib.h>
#define MAX 100

struct Queue {
    int arr[MAX];
    int front;
    int rear;
};

void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue *q) {
    return (q->front == -1);
}

int isFull(struct Queue *q) {
    return (q->rear == MAX - 1);
}

void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->arr[q->rear] = value;
}

int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int item = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;  // Reset when queue becomes empty
    } else {
        q->front++;
    }
    return item;
}

int peek(struct Queue *q) {
    if (isEmpty(q)) {
        return -1;
    }
    return q->arr[q->front];
}

struct Stack {
    struct Queue q1;
    struct Queue q2;
};

void initStack(struct Stack *s) {
    initQueue(&s->q1);
    initQueue(&s->q2);
}

void push(struct Stack *s, int value) {
    enqueue(&s->q2, value);
    while (!isEmpty(&s->q1)) {
        enqueue(&s->q2, dequeue(&s->q1));
    }

    struct Queue temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;

    printf("Pushed %d to stack\n", value);
}

int pop(struct Stack *s) {
    if (isEmpty(&s->q1)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return dequeue(&s->q1);
}

int top(struct Stack *s) {
    if (isEmpty(&s->q1)) {
        printf("Stack is empty\n");
        return -1;
    }
    return peek(&s->q1);
}

int isStackEmpty(struct Stack *s) {
    return isEmpty(&s->q1);
}

void display(struct Stack *s) {
    if (isStackEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = s->q1.front; i <= s->q1.rear; i++) {
        printf("%d ", s->q1.arr[i]);
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    display(&stack);

    printf("Top element is: %d\n", top(&stack));
    printf("Popped element is: %d\n", pop(&stack));
    display(&stack);

    printf("Top element is: %d\n", top(&stack));

    return 0;
}
