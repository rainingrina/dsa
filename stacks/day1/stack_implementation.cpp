#include<vector>
#include<iostream>

class Stack{
    private:
        std::vector<int> stk;
    public:
        Stack(){

        }

        void push(int x){
            stk.push_back(x);
        }

        int top(){
            if(this->isEmpty()) return -1;
            return stk[stk.size() - 1];
        }

        bool isEmpty(){
            return stk.size() == 0;
        }

        int pop(){
            if(this->isEmpty()) return -1;
            int answer = stk[stk.size() - 1];
            stk.pop_back();
            return answer;
        }


};
int main(){
    Stack stk = Stack();
    stk.push(10);
    stk.push(20);
    stk.pop();
    std::cout << stk.top() << std::endl;
    std::cout << stk.isEmpty() << std::endl;
    stk.pop();
    std::cout << stk.isEmpty() << std::endl;
    
}