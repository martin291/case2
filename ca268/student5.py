from sys import gettrace
from Node import Node

#
#   Function to add an item to a tree.
#
#   This is not good object oriented coding. It's not even very polite. It directly interferes with the tree's innards.
#
def add(tree, item):
    """ Add this item to its correct position on the tree """
    # This is a non recursive add method. A recursive method would be cleaner.
    if tree.root == None: # ... Empty tree ...
        tree.root = Node(item, None, None) # ... so, make this the root
    else:
        # Find where to put the item
        child_tree = tree.root
        while child_tree != None:
            parent = child_tree
            if item < child_tree.item: # If smaller ... 
                child_tree = child_tree.left # ... move to the left
            elif item > child_tree.item:
                child_tree = child_tree.right

        # child_tree should be pointing to the new node, but we've gone too far
        # we need to modify the parent nodes
        if item < parent.item:
            parent.left = Node(item, None, None)
        elif item > parent.item:
            parent.right = Node(item, None, None)
        # Ignore the case where the item is equal.

        child_tree = tree.root
        while child_tree.item != item:
            parent = child_tree
            if item < child_tree.item: # If smaller ... 
                child_tree = child_tree.left # ... move to the left
            elif item > child_tree.item:
                child_tree = child_tree.right
            if abs(tree.recurse_height(parent.left) - tree.recurse_height(parent.right)) > 1 and abs(tree.recurse_height(child_tree.left) - tree.recurse_height(child_tree.right)) <= 1:
                return parent.item

        return None
    #
    #   Note that you can get the height of a node by calling tree.recurse_height().
    #       For example, the height of the root is tree.recurse_height(tree.root)
    #
