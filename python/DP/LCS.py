import sys

sys.setrecursionlimit(1000000)
s1 = input()
s2 = input()
cache = [[-1 for i in range(len(s2))] for j in range(len(s1))]


def solve(start1, start2):
    global s1, s2, cache
    if start1 >= len(s1) or start2 >= len(s2):
        return 0
    if cache[start1][start2] != -1:
        return cache[start1][start2]
    a = b = c = 0
    if s1[start1] == s2[start2]:
        a = 1 + solve(start1 + 1, start2 + 1)
    else:
        b = solve(start1 + 1, start2)
        c = solve(start1, start2 + 1)
    cache[start1][start2] = max(a, b, c)
    return cache[start1][start2]


print(solve(0, 0))
