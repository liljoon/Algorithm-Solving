import sys
from itertools import combinations
import copy

sys.setrecursionlimit(100000)


def spread(y, x, chk, tempque, arr2):
    if x < 0 or x >= n or y < 0 or y >= n:
        return
    if chk[y][x] == 1:
        return
    if arr2[y][x] == 1:
        return
    chk[y][x] = 1
    tempque.append([y, x])


def solve(arr2, viarr):
    que = []
    que.extend(viarr)
    i = 0
    chk = [[0 for i in range(n)] for j in range(n)]
    for t in que:
        chk[t[0]][t[1]] = 1
    while len(que) > 0:
        tempque = []
        while len(que) > 0:
            current = que[0]
            que.pop(0)
            spread(current[0] + 1, current[1], chk, tempque, arr2)
            spread(current[0], current[1] + 1, chk, tempque, arr2)
            spread(current[0] - 1, current[1], chk, tempque, arr2)
            spread(current[0], current[1] - 1, chk, tempque, arr2)
        que = tempque[:]
        i += 1
    err = False
    for j in range(n):
        for k in range(n):
            if chk[j][k] == 0 and arr2[j][k] != 1:
               err = True
    if err:
        return 99
    return i


n, m = map(int, input().split())

arr = []
for i in range(n):
    arr.append(list(map(int, sys.stdin.readline().split())))

viarr = []  # 바이러스 놓을 수 있는 공간
for i in range(n):
    for j in range(n):
        if arr[i][j] == 2:
            viarr.append([i, j])
ans = 100

for i in list(combinations(viarr, m)):  # 조합마다 계산
    arr2 = copy.deepcopy(arr)
    ans = min(ans, solve(arr2, i))

if ans == 99:
    print(-1)
else:
    print(ans-1)
