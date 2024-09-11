#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100

struct Stack{
    int top;
    char arr[MAX];
};

void initializeStack(struct Stack* stack){
    stack->top = -1;
}

int isEmpty(struct Stack* stack){
    return stack->top == -1;
}

int isFull(struct Stack* stack){
    return stack->top == MAX - 1;
}

void push(struct Stack* stack, char c){
    if(isFull(stack)){
        printf("Stack Overflow/n");
        return;
    }
    stack->top += 1;
    stack->arr[stack->top] = c;
}

char pop(struct Stack* stack){
    if(isEmpty(stack)){
        printf("Stack Underflow\n");
        return '\0';
    }
    stack->top -= 1;
    return stack->arr[stack->top];
}

char peek(struct Stack* stack){
    if(!isEmpty(stack)){
        return stack->arr[stack->top];
    }
    return '\0';
}

int precedence(char c){
    if(c == '^')
        return 3;
    else if(c == '/' || c == '*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(char * exp){
    struct Stack st;
    initializeStack(&st);

    char result[MAX];
    int k = 0;
    int i;
    for(i = 0; exp[i] != '\0'; i++){
        char c = exp[i];
    }
    if(isalnum(c)){
        result[k++] = c;
    }
    else if(c == '('){
        push(&st, '(');
    }
    else if(c == ')'){
        while(!isEmpty(&st) && peek(&st) != '('){
            
        }
    }
}
