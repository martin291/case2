def set_intersection(set1, set2):
    intersection = []
    for c in set1:
        for k in set2:
            if c in set2 and k in set1:
                if c not in intersection:
                    intersection.append(c)
    return intersection
