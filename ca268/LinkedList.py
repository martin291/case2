#
#  Just a class to store the item and the next pointer
#
class Node:
    def __init__(self, item, next):
        self.item = item
        self.next = next

# Note, these are methods "A method is a function that is stored as a class attribute"
class LinkedList:
    def __init__(self):
        self.head = None
        self.counter = 0

    def add(self, item):
        self.head = Node(item, self.head)
        self.counter += 1

    def remove(self):
        if self.is_empty():
            return None
        else:
            item = self.head.item
            self.head = self.head.next    # remove the item by moving the head pointer
            self.counter -= 1
            return item

    def is_empty(self):
        return self.head == None
    
    def count(self):
        if self.is_empty():
            return 0;
        else:
            return self.counter
            
