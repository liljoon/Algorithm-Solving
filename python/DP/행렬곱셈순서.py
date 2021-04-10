import sys

sys.setrecursionlimit(100000)


def solve(start, end):
    global arr
    if cache[start][end] != -1:
        return cache[start][end]
    if start == end:
        return 0
    ans = 987654321
    for i in range(start, end):
        ans = min(ans, solve(start, i) + solve(i + 1, end) + arr[start][0] * arr[i][1] * arr[end][1])
    cache[start][end] = ans
    return cache[start][end]


n = int(sys.stdin.readline().rstrip())
cache = [[-1 for i in range(n)] for j in range(n)]
arr = []
for i in range(n):
    arr.append(list(map(int, sys.stdin.readline().split())))
print(solve(0, n - 1))
