def sum_to_k(list, k):
    i = 0
    while i < len(list) - 1:
        j = i
        while j < len(list):
            if list[i] + list[j] == k:
                print(list[i], list[j])
            j += 1
        i += 1
