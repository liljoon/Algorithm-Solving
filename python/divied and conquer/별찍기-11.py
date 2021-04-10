import sys
import os

def solve(k, y, x):
    global arr
    if k == 3:
        arr[y][x] = arr[y + 1][x - 1] = arr[y + 1][x + 1] = arr[y + 2][x - 2] = arr[y + 2][x - 1] = arr[y + 2][x] = \
            arr[y + 2][x + 1] = arr[y + 2][x + 2] = '*'
    else:
        solve(k // 2, y, x)
        solve(k // 2, y + k // 2, x - k // 2)
        solve(k // 2, y + k // 2, x + k // 2)


n = int(sys.stdin.readline().rstrip())

arr = [[' ' for j in range(n // 3 * 5 + n // 3 - 1)] for i in range(n)]
solve(n, 0, (n // 3 * 5 + (n // 3) - 1) // 2)
s = ''
for i in range(len(arr)):
    s += ''.join(arr[i]) + '\n'

print(s, end='')
os.system("pause")
