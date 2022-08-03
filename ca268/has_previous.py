import sys

print("Enter numbers (-1 to end): ", end="")
list1 = []
list2 = []
i = 0
while i != -1:
    n = sys.stdin.readline()
    num = int(n)    
    if num != -1:
        if num not in list1:
            list1.append(num)
        else:
            list2.append(num)
    i = num
for number in list2:
    print(str(number) + " ", end="")
print()
    
