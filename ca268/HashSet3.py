from LinkedList import LinkedList

class HashSet:
    def __init__(self, capacity=10):
        # Create a list to use as the hash table
        self.table = [None] * capacity
        self.capacity = capacity

    def add(self, item):
        # Find the hash code
        h = hash(item)
        index = h % len(self.table)

        # Check is it empty
        if self.table[index] == None:
            self.table[index] = LinkedList() # Need a new linked list for this entry

        if item not in self.table[index]:
            # Only add it if not already there (this is a set)
            self.table[index].add(item)

    def min_max_bucket_length(self):
        min = len(self.table[0])
        max = len(self.table[0])
        for i in range(self.capacity):
            if self.table[i] != None:
                if min > len(self.table[i]):
                    min = len(self.table[i])
                if max < len(self.table[i]):
                    max = len(self.table[i])
        return (min, max)
