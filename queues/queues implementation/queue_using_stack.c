#include <stdio.h>
#define N 5

int stack1[N], stack2[N];
int top1 = -1, top2 = -1;
int count = 0;
int i;

void push1(int data) {
    if (top1 == N - 1) {
        printf("\nStack1 is overflow\n");
    } else {
        top1++;
        stack1[top1] = data;
    }
}

int pop1() {
    if (top1 == -1) {
        printf("\nStack1 is empty\n");
        return -1;  // Return -1 to indicate underflow
    } else {
        int a = stack1[top1];
        top1--;
        return a;
    }
}

void push2(int x) {
    if (top2 == N - 1) {
        printf("\nStack2 is overflow\n");
    } else {
        top2++;
        stack2[top2] = x;
    }
}

int pop2() {
    if (top2 == -1) {
        printf("\nStack2 is empty\n");
        return -1;  
    } else {
        int element = stack2[top2];
        top2--;
        return element;
    }
}

void enqueue(int x) {
    push1(x);
    count++;
}

void dequeue() {
    if ((top1 == -1) && (top2 == -1)) {
        printf("\nQueue is empty\n");
    } else {

        for (i = 0; i < count; i++) {
            int element = pop1();
            push2(element);
        }


        int b = pop2();
        if (b != -1) {
            printf("\nThe dequeued element is %d\n", b);
        }

        count--;

        for (i = 0; i < count; i++) {
            int a = pop2();
            push1(a);
        }
    }
}

void display() {
    if (top1 == -1) {
        printf("\nQueue is empty\n");
    } else {
        printf("\nQueue elements are: ");
        for (i = 0; i <= top1; i++) {
            printf("%d ", stack1[i]);
        }
        printf("\n");
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    enqueue(40);
    display();

    return 0;
}
