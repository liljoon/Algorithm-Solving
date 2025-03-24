import sys

sys.setrecursionlimit(10 ** 6)

str1 = input()
str2 = input()

cache = [[-1 for i in range(1000)] for j in range(1000)]

def solve(idx1, idx2):
    if idx1 >= len(str1) or idx2 >= len(str2):
        return 0

    if cache[idx1][idx2] != -1:
        return cache[idx1][idx2]
    if str1[idx1] == str2[idx2]:
        cache[idx1][idx2] = solve(idx1 + 1, idx2 + 1) + 1
        return cache[idx1][idx2]

    a = solve(idx1 + 1, idx2)
    b = solve(idx1, idx2 + 1)
    cache[idx1][idx2] = max(a, b)
    return cache[idx1][idx2]

print(solve(0,0))