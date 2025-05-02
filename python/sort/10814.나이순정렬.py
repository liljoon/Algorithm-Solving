import sys

from functools import cmp_to_key

n =  int(input())

input = lambda : sys.stdin.readline().rstrip()

li = []
for i in range(n):
    a = input().split()
    li.append([int(a[0]), a[1], i])

def custom_cmp(a, b):
    if a[0] != b[0]:
        return a[0] - b[0]
    return a[2] - b[2]

li.sort(key=cmp_to_key(custom_cmp))

for a in li:
    sys.stdout.write(f'{a[0]} {a[1]}\n')