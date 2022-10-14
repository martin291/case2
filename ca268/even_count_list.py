def even_count(lst):
    evens = 0
    if lst.is_empty():
        return evens
    current = lst.head
    while current is not None:
        if current.item % 2 == 0:
            evens += 1
        current = current.next
    return evens
    
