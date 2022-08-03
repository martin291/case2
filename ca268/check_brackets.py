class Stack:
    def __init__(self, capacity = 10):
        self.data = [0] * capacity
        self.top = 0

    def is_empty(self):
        if self.top == 0:
            return True
        else:
            return False

    def push(self, item):
        if self.top < len(self.data):
            self.data[self.top] = item
        else:
            raise Exception("The Stack is full!")
            self.top += 1

    def pop(self):
        if self.is_empty():
            return None
        else:
            self.top -= 1
            return self.data[self.top]

def check_brackets(line):
    #s = Stack()
    #for string in line:
    #    for token in string:
    #        if token in "{[(":
    #            s.push(token)
    #            print("debug1")
    #        elif token in "}])":
    #            print("DEBUG4")
    #            left = s.pop()
    #            if (token == "}" and left != "{") or \
    #            (token == "]" and left != "[") or \
    #            (token == ")" and left != "("):
    #                return False
    #return s.is_empty()
    l = ["[","{","("]
    r = ["]","}",")"]
    stack = [] 
    for i in line: 
        if i in l:
            stack.append(i)
        elif i in r:
            index = r.index(i)
            if ((len(stack) > 0) and (l[index] == stack[len(stack)-1])):
                stack.pop() 
            else: 
                return "False"
    if len(stack) == 0: 
        return "True"
    else:
        return "False" 

