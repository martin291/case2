import sys

word = sys.argv[1]

half = len(word) // 2

if len(word) % 2 == 0:
        print(word[-half:])
else:
    print(word[0] + word[len(word) - 1])
