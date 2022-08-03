#def sum_to_k(lst, k):
#our first solution    
def sum_to_k_1(lst, k):
    seen = dict()
    for num in lst:
        diff = k - num
        if diff in seen:
            return True
        else:
            seen[num] = True
    return False
#after reading discussion website
def sum_to_k(lst, k):
    low = 0
    high = len(lst) - 1
    while low < high:
        sum = lst[low] + lst[high]
        if sum < k:
            low += 1
        elif sum > k:
            high -= 1
        else:
            return True
    return False
