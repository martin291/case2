def get_sliced_lists(l):
    
    list_of_lists = []
    list_tails = l[:len(l) - 1]
    list_headtails = l[1:len(l) - 1]
    list_reversed = l[::-1]
    list_of_lists.append(list_tails)
    list_of_lists.append(list_headtails)
    list_of_lists.append(list_reversed)
    return list_of_lists
