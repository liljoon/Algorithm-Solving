import sys

n = int(input())
sys.setrecursionlimit(100000)


def solve(n):
    global cache
    if cache[n] != -1:
        return cache[n]
    if n == 1:
        return 1
    if n == 2:
        return 3

    cache[n] = (solve(n - 1) + solve(n - 2) * 2) % 10007
    return cache[n]


cache = [-1 for i in range(n + 1)]
print(solve(n))
