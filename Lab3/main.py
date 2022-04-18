from func import *

my_set = []
my_set = set_creation()
print('Enter n:')   
n = int(input())
i = 1
for y in list(combinations(my_set, n)):
    for x in unique_permutations(y):
        print(i, end=') <')
        print_set(x)
        print('>')
        i = i + 1

