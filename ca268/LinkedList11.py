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
        
    def duplicates(self):
        if self.is_empty():  # if list is empty, we won't find any consecutive duplicates.
            return False
        
        curnode = self.head  # start at the beginning.
        nextnode = curnode.next
        return self.search_dup(curnode, nextnode)  # send current and next node through recursive function.
    
    
    def search_dup(self, curnode, nextnode):
        if nextnode is None:  # if the next node is empty, we have nothing to compare current node to.
            return False
        elif curnode.item == nextnode.item:  # if both nodes are the same
            return True
        elif curnode.item != nextnode.item:  # if nodes are not the same.
            return self.search_dup(curnode.next, nextnode.next)
