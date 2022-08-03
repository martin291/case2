def get_evenodd_list():
    import sys
    i = 0
    odd_list = []
    even_list = []
    while i != -1:
        n = sys.stdin.readline()
        s = int(n)
        if s % 2 != 0:
            if s != -1:
                odd_list.append(s)
        else:
            if s != -1:
                even_list.append(s)
        i = s
    return odd_list, even_list
