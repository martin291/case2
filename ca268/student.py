#def enqueue(self, item):
#      if self.head == None:
#         self.head = Node(item, None)
#      else:
#         add_to_queue(self.head, item);

from Node import Node

def add_to_queue(head, item):
    newNode = Node(item, None)
        
    if (head is None):
        head = newNode
        return
    else:
        temp = head
        while(temp.next is not None):
            temp = temp.next
        temp.next = newNode
    
