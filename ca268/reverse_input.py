from Stack import Stack

def reverse_input(stack):
    import sys
    rev_stack = Stack()
    i = 0
    j = 0
    inputs = sys.stdin.readlines()
    #print(inputs, "debug1")
    while i < len(inputs):
        s = inputs[i].strip()
        #print(s)
        rev_stack.push(s)
        i += 1
    i = 0
    while i < len(inputs):
        print(rev_stack.pop())
        i += 1
