#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

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
        printf("\n1.Insert in beginning\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete node after specified location\n7.Search for an element\n8.Show\n9.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
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
                printf("Please enter a valid choice.");
        }
    }
}

void begin_insert(){
    struct node *ptr;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node));  // Correct allocation
    if(ptr == NULL){
        printf("\nStack Overflow\n");
        return;
    }
    else{
        printf("\nEnter value: ");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        printf("\nNode inserted\n");
    }
}

void last_insert(){
    struct node *ptr, *temp;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node));  
    if(ptr == NULL){
        printf("\nStack Overflow\n");
        return;
    }
    else{
        printf("\nEnter value: ");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = NULL;
        if(head == NULL){
            head = ptr;
            printf("\nNode inserted\n");
        }
        else{
            temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = ptr;
            printf("\nNode inserted\n");
        }
    }
}

void random_insert(){
    int i, loc, item;
    struct node *ptr, *temp;
    ptr = (struct node*)malloc(sizeof(struct node));  
    if(ptr == NULL){
        printf("\nStack Overflow\n");
        return;
    }
    else{
        printf("\nEnter element value: ");
        scanf("%d", &item);
        ptr->data = item;
        printf("\nEnter the location after which you want to insert: ");
        scanf("%d", &loc);
        temp = head;
        for(i = 0; i < loc; i++){
            temp = temp->next;
            if(temp == NULL){
                printf("\nCan't insert, location out of range\n");
                free(ptr);
                return;
            }
        }
        ptr->next = temp->next;
        temp->next = ptr;
        printf("\nNode inserted\n");
    }
}

void begin_delete(){
    struct node *ptr;
    if(head == NULL){
        printf("\nList is empty\n");
    }
    else{
        ptr = head;
        head = head->next;
        free(ptr);
        printf("\nNode deleted from the beginning\n");
    }
}

void last_delete(){
    struct node *ptr, *ptr1;
    if(head == NULL){
        printf("\nList is empty\n");
    }
    else if(head->next == NULL){
        free(head);
        head = NULL;
        printf("\nOnly node of the list deleted\n");
    }
    else{
        ptr = head;
        while(ptr->next != NULL){
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = NULL;
        free(ptr);
        printf("\nNode deleted from the last\n");
    }
}

void random_delete(){
    struct node *ptr, *ptr1;
    int loc, i;
    printf("\nEnter the location of the node after which you want to perform deletion: ");
    scanf("%d", &loc);
    ptr = head;
    for(i = 0; i < loc; i++){
        ptr1 = ptr;
        ptr = ptr->next;
        if(ptr == NULL){
            printf("\nCan't delete, location out of range\n");
            return;
        }
    }
    ptr1->next = ptr->next;
    free(ptr);
    printf("\nDeleted node %d\n", loc + 1);
}

void search(){
    struct node *ptr;
    int item, i = 0, flag = 0;
    ptr = head;
    if(ptr == NULL){
        printf("\nEmpty List\n");
    }
    else{
        printf("\nEnter item which you want to search: ");
        scanf("%d", &item);
        while(ptr != NULL){
            if(ptr->data == item){
                printf("Item found at location %d\n", i + 1);
                flag = 1;
                break;
            }
            i++;
            ptr = ptr->next;
        }
        if(flag == 0){
            printf("Item not found\n");
        }
    }
}

void display(){
    struct node *ptr;
    ptr = head;
    if(ptr == NULL){
        printf("\nNothing to print\n");
    }
    else{
        printf("\nPrinting values:\n");
        while(ptr != NULL){
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}
