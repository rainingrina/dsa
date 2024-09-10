#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head;
void begin_insert();
void last_insert();
void random_insert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();

void main(){
    int choice = 0;
    while (choice != 9){
        printf("\n**************Main Menu*************\n");
        printf("\nChoose one option from the following list....\n");
        printf("\n--------------------------------------------------\n");
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning5.Delete from last\n6.Delete node after specified location\n7.Search for an element\n8.Show\n9.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch(choice){
            case 1:
                begin_insert();
                break;
            case 2:
                last_insert();
                break;
            case 3:
                random_insert();
                break;
            case 4:
                begin_delete();
                break;
            case 5:
                last_delete();
                break;
            case 6:
                random_delete();
                break;
            case 7:
                search();
                break;
            case 8:
                display();
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("Please enter valid choice.");
        }
    }
}

void begin_insert(){
    struct node *ptr;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node*));
    if(ptr == NULL){
        printf("\n Stack Overflow")
    }
    else{
        printf("\nEnter value\n");
        scanf("%d", &item);
        ptr -> data = item;
        ptr -> next = head;
        head = ptr;
        printf("\nNode inserted");
    }
}

void last_insert(){
    struct node *ptr, *temp;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("\n Stack overflow");

    }
    else{
        printf("\nEnter value\n");
        scanf("%d", &item);
        if(head == NULL){
            ptr -> next = NULL;
            head = ptr;
            printf("\n Node inserted");
        }
        else{
            temp = head;
            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = ptr;
            ptr -> next = NULL;
            printf("\n Node inserted");
        }
    }
}

void random_insert(){
    int i, loc, item;
    struct node *ptr, *temp;
    ptr = (struct node*) malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("\n Stack Overflow");
    }
    else{
        printf("\nEnter element value");
        scanf("%d", &item);
        ptr -> data = item;
        printf("\n Enter the locaiton after which you want to insert");
        scanf("\n%d", &loc);
        temp = head;
        for(i = 0; i < loc; i++){
            temp = temp-> next;
            if(temp == NULL){
                printf("\nCan't insert");
                return;
            }
        }
        ptr -> next = temp -> next;
        temp -> next = ptr;
        printf("\nNode inserted");
    }
}

void begin_delete(){
    struct node *ptr;
    if(head == NULL){
        printf("\nList is empty\n");
    }
    else{
        ptr = head;
        head = ptr -> nextl
        free(ptr);
        printf("\n Node deleted from the beginning\n");

    }
}

void last_delete(){
    struct node *ptr, *ptr1;
    if(head == NULL){
        printf("\nList is empty");
    }
    else if(head -> next == NULL){
        head = NULL;
        free(head);
        printf("\n Only node for the list deleted\n");

    }
    else{
        ptr = head;
        while(ptr->next != NULL){
            ptr1 = ptr;
            ptr = ptr1 ->next;
        }
        ptr1 -> next = NULL;
        free(ptr);
        printf("\nDeleted node from the last\n");
    }
}