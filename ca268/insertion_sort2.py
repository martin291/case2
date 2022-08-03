def insertion_sort(lst):
    # No swap version
    comp = 0
    moves = 0
    for todo in range(1, len(lst)):
        tobeinserted = lst[todo]
        i = todo
        while i > 0 and tobeinserted < lst[i-1]:
            lst[i] = lst[i-1] # Make space for the item
            comp += 1
            moves += 1
            i -= 1
        if i > 0:
            comp += 1
        moves += 2
        lst[i] = tobeinserted  # Found the place for this item, plonk it in
    return comp, moves
