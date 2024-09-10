#include <iostream>

class DoublyLinkedList{
    class Node{
        public:
            int val;
            Node * next;
            Node(int val){
                this->val = val;
                this->next = nullptr;
            }
    };
    
    private:
        Node* front;
        Node* rear;
    
    public:
        DoublyLinkedList(){
            this->front = nullptr;
            this->rear = nullptr;
        }

        void pushAtRear(int val){
            Node* newNode = new Node(val);
            if(this->front == nullptr){
                this->front = newNode;
                this->rear = newNode;
            }
            else{
                this->rear->next = newNode;
                this->rear = newNode;
            }
        }

        int frontVal(){
            if(this->front == nullptr){
                return -1;
            }
            else{
                return this->front->val;
            }
        }

        void popAtFront(){
            if(this->front != nullptr){
                Node* temp = this->front;
                this->front = this->front->next;
                delete temp;
                if(this->front == nullptr){
                    this->rear = nullptr;
                }
            }
        }

        bool isEmpty(){
            return this->front == nullptr;
        }
};

class Queue{
    private: 
        DoublyLinkedList* q;
    
    public:
        Queue(){
            this->q = new DoublyLinkedList();
        }

        ~Queue(){
            delete this->q;
        }

        void enqueue(int val){
            this->q->pushAtRear(val);
        }

        int front(){
            if(this->q->isEmpty()) return -1;
            else return this->q->frontVal();
        }

        void dequeue(){
            this->q->popAtFront();
        }

        bool isEmpty(){
            return this->q->isEmpty();
        }
};

int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << q.front() << std::endl;
    q.dequeue();
    std::cout << q.front() << std::endl;

    return 0;
}
