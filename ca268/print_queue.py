def print_queue(data, front, back):
    #while front <= back:
    #    print(data[front])
    #    front = front + 1
    #print(data[back])
    while front < back:
        return data[front:back]
    return data[front:] + data[:back]
