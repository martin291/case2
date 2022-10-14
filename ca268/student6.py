def radixsort(lst, number_of_passes):
    """ this function will sort lst using radixsort up to the required number of passes.
    Note that the first pass we will sort on the least significant bit.
    """
    # for each power of two (starting at lowest) sort based on that power
    for p in range(32):  # Assume 32 bit integers
        # Split list in two
        lo = [x for x in lst if x & (1 << p) == 0] # only where that bit is zero
        hi = [x for x in lst if x & (1 << p) != 0] # only where that bit is 1
        
        lst = lo + hi # combine the two lists (now sorted by that bit).
        if p == number_of_passes - 1:
            return lst
    
    # You need to work out when to stop and also you have to return the lst.
