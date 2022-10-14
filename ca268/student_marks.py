def make_map():
    import sys
    dict = {}
    s = sys.stdin.read().strip().split('\n')
    for student in s:
        info = student.split()
        mark = info[0]
        name = info[1]
        dict[mark] = name
    return dict
        
