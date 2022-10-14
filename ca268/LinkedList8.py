#
#  Just a class to store the item and the next pointer
#
class Node:
    def __init__(self, item, next):
        self.item = item
        self.next = next

#
#   LinkedList class
#
class LinkedList:
    def __init__(self):
        self.head = None

    def add(self, item):
        self.head = Node(item, self.head)

    def remove(self):
        if self.is_empty():
            return None
        else:
            item = self.head.item
            self.head = self.head.next    # remove the item by moving the head pointer
            return item

    def is_empty(self):
        return self.head == None
    
    def count_even(self):
        count = 0
        node = self.head
        return self.rec_count_even(node, count)
    
    def rec_count_even(self, node, count):
        if node == None:  # If it's pointing to nothing.
            return count
        elif (node.item % 2 == 0):
            return self.rec_count_even(node.next, count + 1)
        else:
            return self.rec_count_even(node.next, count)
