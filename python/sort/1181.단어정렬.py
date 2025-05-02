import sys
from functools import cmp_to_key

n = int(input())

li = []

for i in range(n):
    li.append(sys.stdin.readline().rstrip())

li = list(set(li))

def customSort(a, b):
    if len(a) < len(b):
        return -1
    elif len(a) > len(b):
        return 1
    else:
        if a < b:
            return -1
        elif a > b:
            return 1
        else:
            return 0


li.sort(key=cmp_to_key(customSort))

for w in li:
    print(w)