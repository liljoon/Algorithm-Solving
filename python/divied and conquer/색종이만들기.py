import sys


def solve(y, x, size, color):
    global arr
    if size == 1:
        if arr[y][x] == color:
            return 1
        else:
            return 0
    else:
        lefttop = solve(y, x, size // 2, color)
        righttop = solve(y, x + size // 2, size // 2, color)
        leftbot = solve(y + size // 2, x, size // 2, color)
        rightbot = solve(y + size // 2, x + size // 2, size // 2, color)
        if lefttop == righttop == leftbot == rightbot == 1:
            return 1
        else:
            return lefttop + righttop + leftbot + rightbot + 0.00000001


n = int(sys.stdin.readline().rstrip())
arr = []
for i in range(n):
    arr.append(list(map(str, sys.stdin.readline().split())))

print(int(solve(0, 0, n, '0')))
print(int(solve(0, 0, n, '1')))
