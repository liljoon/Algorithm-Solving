n, r, c = list(map(int, input().split()))
sum = 0


def solve(size, y, x):
    if size == 1:
        return
    global sum
    mid = size // 2
    if x < mid and y < mid:
        solve(mid, y, x)
    elif y < mid and x >= mid:
        sum += mid * mid
        solve(mid, y, x - mid)
    elif y >= mid and x < mid:
        sum += 2 * mid * mid
        solve(mid, y - mid, x)
    elif y >= mid and x >= mid:
        sum += 3 * mid * mid
        solve(mid, y - mid, x - mid)


solve(2 ** n, r, c)
print(sum)
