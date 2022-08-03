def is_avl(bst):
    # Determine whether this bst is AVL balanced or not.
    root = bst.root
    return rec_is_avl(bst, root)

def rec_is_avl(bst, root):
    if root is None:
        return True
    
    lheight = r_height(bst, root.left)
    rheight = r_height(bst, root.right)
    
    if (abs(lheight - rheight) > 1):
        return False
    
    lcheck = rec_is_avl(bst, root.left)
    rcheck = rec_is_avl(bst, root.right)
    
    if lcheck is True and rcheck is True:
        return True

def r_height(self, ptr):
        if ptr == None:
            return 0
        else:
            return 1 + max(self.r_height(ptr.left), self.r_height(ptr.right))
