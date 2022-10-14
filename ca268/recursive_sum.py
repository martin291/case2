def sumto(a, b):
    if (a == b - 1):
        return(a)
    elif (a == b):
        return(0)
    return(a + sumto(a + 1, b))
