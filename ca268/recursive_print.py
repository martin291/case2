def rprint(a, b):
    if a == b:
        return b
    print(a)
    return rprint(a + 1, b)
