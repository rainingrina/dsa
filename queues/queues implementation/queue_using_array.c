#include <stdio.h>
#include <stdlib.h>
#define maxsize 5

int front = -1;
int rear = -1;
int queue[maxsize];

void insert();
void delete();
void display();

void main(){
    int choice;
    while (choice != 4){
        printf("\n*************************Main Menu*****************************\n");  
        printf("\n=================================================================\n");  
        printf("\n1.Insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");  
        printf("\nEnter your choice: ");  
        scanf("%d", &choice);
        switch(choice){
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting\n");
                exit(0);
                break;
            default:
                printf("\nEnter a valid choice:\n");
        }
    }
}

void insert(){
    int item;
    printf("\nEnter the element: ");
    scanf("%d", &item);
    if(rear == maxsize - 1){
        printf("\nQueue Overflow\n");
        return;
    }
    if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
    }
    else{
        rear = rear + 1;
    }
    queue[rear] = item;
    printf("\nValue Inserted\n");
}

void delete(){
    int item;
    if(front == -1 || front > rear){
        printf("\nQueue Underflow\n");
        return; // Fixed missing semicolon
    }
    else{
        item = queue[front];
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else{
            front = front + 1;
        }
        printf("\nDeleted Element: %d\n", item);
    }
}

void display(){
    int i;
    if(rear == -1){
        printf("\nEmpty queue\n");
    }
    else{
        printf("\nQueue elements are:\n");
        for(i = front; i <= rear; i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
