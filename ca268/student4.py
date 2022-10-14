def rotation_type(bst):
    root = bst.root
    
    left = bst.r_height(root.left)
    if left == 2:
        if root.left != None:
            left_left = bst.r_height(root.left.left)
            if left_left == 1:
                return 'll'
            left_right = bst.r_height(root.left.right)
            if left_right == 1:
                return 'lr'
    
    right = bst.r_height(root.right)
    if right == 2:
        if root.right != None:
            right_right = bst.r_height(root.right.right)
            if right_right == 1:
                return 'rr'
            right_left = bst.r_height(root.right.left)
            if right_left == 1:
                return 'rl'
