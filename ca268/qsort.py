#
#   qsort code and a partition function.
#
#   Modify the code so that it returns the number of compares and the number of moves.
#
comp = 0
moves = 0

def partition(lst, lo, hi):
    part = lo
    global comp
    global moves
    while lo < hi:
        while lst[lo] <= lst[part] and lo < hi:
            comp += 1
            lo += 1
        comp += 1
        while lst[hi] > lst[part]: # Don't have to check for hi >= 0 cos part is there as a sentinel.
            comp += 1
            hi -= 1
        comp += 1

        if lo < hi:
            # Swap the two entries
            lst[hi], lst[lo] = lst[lo], lst[hi]
            moves += 3

    # Swap part into position
    if lst[part] > lst[hi]: # (this may happen of the array is small (size 2))
        lst[part], lst[hi] = lst[hi], lst[part]
        moves += 3
    comp += 1

    return hi

def rec_qsort(lst, lo, hi):
    if lo < hi:
        pivot = partition(lst, lo, hi)
        rec_qsort(lst, lo, pivot - 1)
        rec_qsort(lst, pivot + 1, hi)

def qsort(lst):
    rec_qsort(lst, 0, len(lst) - 1)
    return comp, moves
