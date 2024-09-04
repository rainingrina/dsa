class Stack:
    def __init__(self):
        self.stk = []
    
    def push(self, x):
        self.stk.append(x)
    
    def pop(self):
        self.stk.pop()

    def size(self):
        return len(self.stk)
    
    def isEmpty(self):
        return len(self.stk) == 0
    
    def top(self):
        if self.isEmpty():
            return None
        else:
            return self.stk[-1]
        

stk = Stack()
stk.push(10)
stk.push(20)
stk.pop()
print(stk.top())
print(stk.isEmpty())
stk.pop()
print(stk.isEmpty())