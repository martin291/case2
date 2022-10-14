#
#  Create a queue relying on a Stack. Actually Two Stacks.
#
#  The Stack ADT has three methods:
#     isempty(), push() and pop()
#
from Stack import Stack

class Queue:
    def __init__(self):
        self.stack_1 = Stack() #this stack takes the items first
        self.stack_2 = Stack()
        self.size = 0  #this keeps strack of the size of the stack_1 and therefore stack_2

    def isempty(self):
        return self.size == 0

    def enqueue(self, item):
        self.stack_1.push(item)
        self.size += 1

    def dequeue(self):
        self.size -= 1
        if not self.stack_2.isempty():
            return self.stack_2.pop()
        
        while not self.stack_1.isempty():
            self.stack_2.push(self.stack_1.pop()) #we make the top of stack_1 the bottom of stack_2
    
        return self.stack_2.pop()
