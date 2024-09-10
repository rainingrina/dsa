class Node:
    def __init__(self, val) -> None:
        self.val = val
        self.next = None

class DoublyEndedList:
    def __init__(self) -> None:
        self.front = None
        self.rear = None

    def pushAtRear(self, val):
        node = Node(val)
        if self.isEmpty():
            self.front = node
            self.rear = node
        self.rear.next = node
        self.rear = self.rear.next

    def popAtFront(self):
        if self.isEmpty():
            return
        self.front = self.front.next
        if self.front is None:
            self.rear = None
        
    def isEmpty(self):
        return self.front is None
    
class Queue:
    def __init__(self) -> None:
        self.q = DoublyEndedList()

    def enqueue(self, val):
        self.q.pushAtRear(val)

    def dequeue(self):
        self.q.popAtFront()
    
    def front(self):
        if self.isEmpty(): return None
        return self.q.front.val
    
    def isEmpty(self):
        return self.q.isEmpty()
    

q = Queue()
q.enqueue(10)
q.enqueue(20)
q.enqueue(30)
print(q.front())
q.dequeue()
print(q.front())