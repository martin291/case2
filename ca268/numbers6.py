def get_counts(list):
    count_list = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    for i in list:
        length = len(i)
        count_list[length] += 1
    return count_list
