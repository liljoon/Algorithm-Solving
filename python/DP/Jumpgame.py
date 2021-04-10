import sys


def solve(y, x):
    global cache
    global n
    if x >= n or y >= n:
        return 0
    if cache[y][x] != -1:
        return cache[y][x]
    if y == n - 1 and x == n - 1:
        return 1

    jump = arr[y][x]
    a = solve(y + jump, x)
    b = solve(y, x + jump)
    cache[y][x] = a or b
    return cache[y][x]


t = int(input())
for _ in range(t):

    n = int(sys.stdin.readline())
    cache = [[-1 for j in range(n)] for i in range(n)]
    arr = [[] for i in range(n)]
    for i in range(n):
        arr[i] = list(map(int, sys.stdin.readline().split()))
    if solve(0, 0) == 1:
        print("YES")
    else:
        print("NO")