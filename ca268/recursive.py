def is_palindrome(word):
    word = word.replace(' ', '', 1)
    half = len(word) // 2
    if len(word) == 1:
        return True
    if len(word) % 2 == 0:
        if (word[half - 1] == word[half]) and (word[0] == word[-1]):
            return True
    else:
        if word[half + 1] == word[half - 1] and (word[0] == word[-1]):
            return True
    return False
