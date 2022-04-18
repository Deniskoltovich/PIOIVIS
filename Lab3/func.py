from itertools import combinations

import re


def set_creation():
    print('Enter number of elements:')
    n = int(input())
    print('Enter elements:')
    my_set = set()
    for i in range(0, n):
        input1(my_set)
    unordered_set = []
    for item in my_set:
        unordered_set.append(item)
    print('Your set is', end=' {')
    print_set(unordered_set)
    print('}')
    return unordered_set


def permutations(iterable):
    if len(iterable) == 1:
        yield (iterable[0], )
    else:
        for perm in permutations(iterable[1:]):
            for i in range(len(iterable)): 
                yield perm[:i] + (iterable[0], ) + perm[i:]


def unique_permutations(iterable):
    return list(permutations(iterable))
    


def correct_input(inp):
    pattern = r'[a-zA-Z0-9<>,]'
    for char in inp:
        if re.search(pattern, char):
            res = True
        else:
            return False
    return res


def input1(my_set):
    inp = str(input())
    if inp[0] == "{":
        tmp_list = check(inp)
        s = '{'
        for item in tmp_list:
            if item != tmp_list[len(tmp_list) - 1]:
                s += str(item) + ', '
            else:
                s += str(item)
        s+='}'
        my_set.add(s)
    elif correct_input(inp):
        my_set.add(inp)
        return
    else:
        print('Enter correct data:')
        input1(my_set)


def print_set(my_set):
    for item in my_set:
        if item != my_set[len(my_set) - 1]:
            print(item, end=', ')
        else:
            print(item, end='')


def check(inp):
    pattern = r'[0-9]'
    tmp_list = []
    for char in inp:
        if re.search(pattern, char):
            tmp_list.append(int(char))
    return sorted(tmp_list)
    
        