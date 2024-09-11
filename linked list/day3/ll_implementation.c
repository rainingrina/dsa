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
    struct node *new_node;
    int item;
    new_node = (struct node*)malloc(sizeof(struct node));  // Correct allocation
    if(new_node == NULL){
        printf("\nStack Overflow\n");
        return;
    }
    else{
        printf("\nEnter value: ");
        scanf("%d", &item);
        new_node->data = item;
        new_node->next = head;
        head = new_node;
        printf("\nNode inserted\n");
    }
}

void last_insert(){
    struct node *new_node, *temp;
    int item;
    new_node = (struct node*)malloc(sizeof(struct node));  
    if(new_node == NULL){
        printf("\nStack Overflow\n");
        return;
    }
    else{
        printf("\nEnter value: ");
        scanf("%d", &item);
        new_node->data = item;
        new_node->next = NULL;
        if(head == NULL){
            head = new_node;
            printf("\nNode inserted\n");
        }
        else{
            temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = new_node;
            printf("\nNode inserted\n");
        }
    }
}

void random_insert(){
    int i, loc, item;
    struct node *new_node, *temp;
    new_node = (struct node*)malloc(sizeof(struct node));  
    if(new_node == NULL){
        printf("\nStack Overflow\n");
        return;
    }
    else{
        printf("\nEnter element value: ");
        scanf("%d", &item);
        new_node->data = item;
        printf("\nEnter the location after which you want to insert: ");
        scanf("%d", &loc);
        temp = head;
        for(i = 0; i < loc; i++){
            temp = temp->next;
            if(temp == NULL){
                printf("\nCan't insert, location out of range\n");
                free(new_node);
                return;
            }
        }
        new_node->next = temp->next;
        temp->next = new_node;
        printf("\nNode inserted\n");
    }
}

void begin_delete(){
    struct node *new_node;
    if(head == NULL){
        printf("\nList is empty\n");
    }
    else{
        new_node = head;
        head = head->next;
        free(new_node);
        printf("\nNode deleted from the beginning\n");
    }
}

void last_delete() {
    struct node *prev, *temp;
    
    if (head == NULL) {
        printf("\nList is empty\n");
    } 
    else if (head->next == NULL) {
        // Case: Only one node in the list
        free(head);
        head = NULL;
        printf("\nOnly node of the list deleted\n");
    } 
    else {
        // Traverse to the last node
        temp = head;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        // Now 'temp' points to the last node, and 'prev' points to the second-to-last node
        prev->next = NULL;  // Disconnect the last node from the list
        free(temp);  // Free the memory of the last node
        printf("\nNode deleted from the last\n");
    }
}

void random_delete() {
    struct node *temp, *prev;
    int loc, i;
    printf("\nEnter the location of the node after which you want to perform deletion: ");
    scanf("%d", &loc);
    temp = head;
    for(i = 0; i < loc; i++) {
        prev = temp;
        temp = temp->next;
        if(temp == NULL) {
            printf("\nCan't delete, location out of range\n");
            return;
        }
    }
    prev->next = temp->next;
    free(temp);
    printf("\nDeleted node %d\n", loc + 1);
}

void search() {
    struct node *temp;
    int item, i = 0, flag = 0;
    temp = head;
    
    if(temp == NULL) {
        printf("\nEmpty List\n");
    } else {
        printf("\nEnter item which you want to search: ");
        scanf("%d", &item);
        
        while(temp != NULL) {
            if(temp->data == item) {
                printf("\nItem found at location %d\n", i + 1);
                flag = 1;
                break;
            }
            i++;
            temp = temp->next;
        }
        
        if(flag == 0) {
            printf("\nItem not found\n");
        }
    }
}

void display(){
    struct node *temp;
    temp = head;
    if(temp == NULL){
        printf("\nNothing to print\n");
    }
    else{
        printf("\nPrinting values:\n");
        while(temp != NULL){
            printf("%d ", temp ->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
