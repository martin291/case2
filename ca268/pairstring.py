import sys

word = sys.argv[1]

i = 0
while i < len(word) - 1:
    print(word[i] + word[i + 1])
    i += 1
