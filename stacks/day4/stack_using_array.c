#include <stdio.h>

int stack[100], i, choice = 0, top = -1, n;
void push();
void pop();
void show();
int peek();

void main(){
    printf("Enter the number of elements in the stack: ");
    scanf("%d", &n);
    printf("--------Stack Operations using Array ----------\n");
    while(choice != 5){
        printf("Choose one from the below options...\n");  
        printf("\n1.Push\n2.Pop\n3.Show\n4.Peek\n5.Exit\n");  
        printf("\nEnter your choice: ");   
        scanf("%d", &choice);
        switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                show();
                break;
            case 4:
                if(top != -1)
                    printf("Top element is %d\n", peek());
                break;
            case 5:
                printf("Exiting\n");
                break;
            default:
                printf("Enter a valid choice\n");
        }
    }
}

void push(){
    int val;
    if(top == n - 1){
        printf("\nOverflow\n");
    }
    else{
        printf("Enter the value: ");
        scanf("%d", &val);
        top = top + 1;
        stack[top] = val;
    }
}

void pop(){
    if(top == -1){
        printf("Stack Underflow\n");
        
    }
    else{
        int val;
        val = top;
        top = top - 1;
        printf("Popped element is: %d", stack[val]);
    }
}

void show(){
    if(top == -1){
        printf("Stack is empty\n");
    }
    else{
        for(i = top; i >= 0; i--){
            printf("%d\n", stack[i]);
        }
    }
}

int peek(){
    if(top == -1){
        printf("Stack Underflow\n");
        return -1;
    }
    else{
        return stack[top];
    }
}
