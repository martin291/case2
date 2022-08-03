import sys
input = sys.stdin.readline().split()
numlist = []
for c in input:
    numlist.append(int(c))

def average(list):
    summation = sum(list)
    return(summation / len(list))

print(average(numlist))
