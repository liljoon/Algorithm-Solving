def solve(n):
    if n % 2 == 1:
        return 0
    if n == 2:
        return 3
    if cache[n] != -1:
        return cache[n]
    a = 0
    i = n - 4
    while i >= 2:
        a += solve(i)
        i -= 2
    a += 1
    cache[n] = solve(n - 2) * 3 + 2 * a
    return cache[n]


n = int(input())

arr = [[0 for i in range(n)] for j in range(3)]
cache = [-1 for _ in range(32)]

print(solve(n))
