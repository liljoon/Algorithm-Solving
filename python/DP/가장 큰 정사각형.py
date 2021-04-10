import sys


def solve(y, x, size):
    global n, m, arr, cache
    if y >= n or x >= m:
        return 0
    if cache[y][x] != -1:
        return cache[y][x]
    if arr[y][x] == 0:
        return 0
    a = solve(y, x + 1, size + 1)
    b = solve(y + 1, x + 1, size + 1)
    c = solve(y + 1, x, size + 1)
    cache[y][x] = min(a, b, c)+1
    return cache[y][x]


sys.setrecursionlimit(1000000)
n, m = list(map(int, sys.stdin.readline().split()))
arr = []
cache = [[-1 for i in range(m)] for j in range(n)]
for i in range(n):
    arr.append(list(map(int, sys.stdin.readline().rstrip().format())))

ans = 0
for i in range(n):
    for j in range(m):
        ans = max(solve(i, j, 0), ans)
print(ans*ans)
