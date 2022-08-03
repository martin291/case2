def get_counts_dict(list):
    dict = {}
    counter = []
    for word in list:
        counter.append(len(word))
        count = counter.count(len(word))
        dict[len(word)] = count
    return dict        
        
