import sys
print("Enter a name and number, or a name and ? to query (!! to exit)")
i = 0
dict = {}
while i == 0:
    if i == 0:
        line = sys.stdin.readline().strip().split()
        if line[0] == "!!":
            print("Bye")
            i = 1
        elif line[1].isdigit():
            dict[line[0]] = line[1]
        elif line[1] == "?":
            if line[0] in dict:
                print(line[0], "has number", dict[line[0]])
            else:
                print("Sorry, there is no", line[0])
