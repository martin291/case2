#
#   Arrange a list so that when added to a tree will cause the tree to be completely balanced
#
def make_list(lst):
    if lst is None:
        return None
    tmp = lst
    new_lst = []
    
    list_mid = [len(tmp)//2]
    new_lst.append(sorted_list[list_mid])
    new_lst.remove(sorted_list[list_mid])
    
    i = 0
    while i < len(sorted_lst):
        before_mid = list_mid - 1
        after_mid = list_mid + 1
        
        new_lst.append(sorted_list[len(sorted_list)//2])
        sorted_list.remove(sorted_list[len(sorted_list)//2])
        
        new_lst.append(sorted_list[len(sorted_list)//2])
        sorted_list.remove(sorted_list[len(sorted_list)//2])
        i += 1
    return new_lst
    
    
from copy import deepcopy

def make_list(lst):
    tmp = deepcopy(lst)
    tmp.sort()
    newlist = []
    mid = 0
    left = 0
    right = len(tmp) - 1
    build(tmp, left, right, newlist)
    return newlist

def build(list1, left, right, newlist):
    if left > right:
        return None
    mid = (left + right) // 2
    newlist.append(list1[mid])
    build(list1, left, (mid - 1), newlist)
    build(list1, (mid + 1), right, newlist)
    return newlist
