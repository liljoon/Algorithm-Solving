import  sys
sys.setrecursionlimit(1000000)

def solve(start, last):
    global arr, n, cache
    if start >= n:
        return 0
    b = 0

    a = solve(start + 1, last)

    if start == 0 or (start != 0 and arr[start] > last):
        if cache[start] != -1:
            b = cache[start]
        else:
            cache[start] = b = solve(start + 1, arr[start]) + 1
    return max(a, b)


n = int(input())
cache = [-1 for j in range(n)]
arr = list(map(int, input().split()))
print(solve(0, 0))
