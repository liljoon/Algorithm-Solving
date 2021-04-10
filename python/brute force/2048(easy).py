import sys


def left(arr):
    global n

    li = [[0 for i in range(n)] for i in range(n)]
    for i in range(n):
        for j in range(n):
            li[i][j] = arr[i][j]

    for i in range(n):
        for j in range(n):
            if li[i][j] != 0:
                for k in range(j + 1, n):
                    if li[i][j] == li[i][k]:
                        li[i][j] *= 2
                        li[i][k] = 0
                        break
                    elif li[i][k] != 0:
                        break

    for i in range(n):
        for j in range(n):
            if li[i][j] == 0:
                for k in range(j + 1, n):
                    if li[i][k] != 0:
                        li[i][j], li[i][k] = li[i][k], li[i][j]
                        break

    return li


def right(arr):
    global n
    li = [[0 for i in range(n)] for i in range(n)]
    for i in range(n):
        for j in range(n):
            li[i][j] = arr[i][j]

    for i in range(n):
        for j in reversed(range(n)):
            if li[i][j] != 0:
                for k in reversed(range(0, j)):
                    if li[i][j] == li[i][k]:
                        li[i][j] *= 2
                        li[i][k] = 0
                        break
                    elif li[i][k] != 0:
                        break

    for i in range(n):
        for j in reversed(range(n)):
            if li[i][j] == 0:
                for k in reversed(range(0, j)):
                    if li[i][k] != 0:
                        li[i][j], li[i][k] = li[i][k], li[i][j]
                        break

    return li


def down(arr):
    global n

    li = [[0 for i in range(n)] for i in range(n)]
    for i in range(n):
        for j in range(n):
            li[i][j] = arr[i][j]
    for i in range(n):
        for j in reversed(range(n)):
            if li[j][i] != 0:
                for k in reversed(range(0, j)):
                    if li[j][i] == li[k][i]:
                        li[j][i] *= 2
                        li[k][i] = 0
                        break
                    elif li[k][i] != 0:
                        break

    for i in range(n):
        for j in reversed(range(n)):
            if li[j][i] == 0:
                for k in reversed(range(0, j)):
                    if li[k][i] != 0:
                        li[j][i], li[k][i] = li[k][i], li[j][i]
                        break

    return li


def up(arr):
    global n

    li = [[0 for i in range(n)] for i in range(n)]
    for i in range(n):
        for j in range(n):
            li[i][j] = arr[i][j]

    for i in range(n):
        for j in range(n):
            if li[j][i] != 0:
                for k in range(j + 1, n):
                    if li[j][i] == li[k][i]:
                        li[j][i] *= 2
                        li[k][i] = 0
                        break
                    elif li[k][i] != 0:
                        break

    for i in range(n):
        for j in range(n):
            if li[j][i] == 0:
                for k in range(j + 1, n):
                    if li[k][i] != 0:
                        li[j][i], li[k][i] = li[k][i], li[j][i]
                        break

    return li


def findmax(arr):
    ret = 0
    for i in range(n):
        for j in range(n):
            ret = max(ret, arr[i][j])
    return ret


def solve(arr, index):
    if index >= 5:
        return findmax(arr)
    else:
        li_up = up(arr)
        li_down = down(arr)
        li_left = left(arr)
        li_right = right(arr)
        return max(solve(li_up, index + 1), solve(li_down, index + 1), solve(li_left, index + 1),
                   solve(li_right, index + 1))


n = int(input())
arr = [[] for i in range(n)]
for i in range(n):
    arr[i] = list(map(int, sys.stdin.readline().split()))

print(solve(arr, 0))
