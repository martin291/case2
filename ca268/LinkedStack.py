from LinkedList import LinkedList

class Node:
    def __init__(self, item, next):
        self.item = item
        self.next = next

class LinkedStack:
    def __init__(self):
        self.ll = LinkedList()
        self.head = None
        
    def push(self, item):
        self.head = Node(item, self.head)
        
    def pop(self):
        if self.is_empty():
            return None
        else:
            item = self.head.item
            self.head = self.head.next
            return item

    def is_empty(self):
        return self.head == None
