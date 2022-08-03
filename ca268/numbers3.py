def get_odd_list():
    import sys
    i = 0
    odd_list = []
    while i != -1:
        n = sys.stdin.readline()
        s = int(n)
        if s % 2 != 0:
            if s != -1:
                odd_list.append(s)
        i = s
    return odd_list
