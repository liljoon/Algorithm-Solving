import sys
sys.setrecursionlimit(1000000)

def solve(y, x):
    if y < 0 or y >= n or x < 0 or x >= m:
        return 0
    if arr[y][x] == 1:
        arr[y][x] = -1
        solve(y+1,x)
        solve(y,x+1)
        solve(y-1,x)
        solve(y,x-1)
        return 1
    else:
        return 0


t = int(input())
for ti in range(t):
    m, n, k = map(int, input().split())
    arr = [[0 for i in range(m)] for j in range(n)]
    for i in range(k):
        x, y = map(int, input().split())
        arr[y][x] = 1
    ans = 0
    for i in range(n):
        for j in range(m):
            ans += solve(i, j)
    print(ans)
