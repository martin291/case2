def detect_loop(lst):
    if lst.is_empty():
        return False
    else:
        current = lst.head
        while current.next is not None and current.next != lst.head:
            current = current.next
        return current.next == lst.head
