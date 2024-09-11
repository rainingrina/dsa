typedef struct Node{
    int data;
    struct Node* next;
} Node;

Node* createNode(int new_data){
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data
    new_node->next = NULL;
    return new_node;
}

typedef struct Stack{
    Node *head;
}Stack;

void initializeStack(Stack* stack){
    stack->head = NULL;
}

int isEmpty(Stack* stack){
    return stack->head == NULL;
}

void push(Stack* stack, int new_data){
    Node* new_node = createNode(new_data);
    if(!new_node){
        printf("\nStack Overflow");
        return;
    }
    new_node -> next = stack -> head;
    stack -> head = new_node;
}

void pop(Stack* stack){
    if(isEmpty(stack)){
        
    }
}