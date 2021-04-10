import sys

sys.setrecursionlimit(1000000)


def drink(start, cnt):
    global n, arr
    if start == n:
        return 0
    if cache[start][cnt] != -1:
        return cache[start][cnt]
    a = 0
    if cnt != 2:
        a = drink(start + 1, cnt + 1) + arr[start]
    b = drink(start + 1, 0)
    cache[start][cnt] = max(a, b)
    return cache[start][cnt]


n = int(sys.stdin.readline().rstrip())
arr = []
cache = [[-1, -1, -1] for i in range(n)]
for _ in range(n):
    arr.append(int(sys.stdin.readline().rstrip()))
print(drink(0, 0))
