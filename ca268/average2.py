def above_average(l):
    summation = sum(l)
    avrg = (summation / len(l))
    abv_avrg = []
    for num in l:
        if num > avrg:
            abv_avrg.append(num)
    return(abv_avrg)
