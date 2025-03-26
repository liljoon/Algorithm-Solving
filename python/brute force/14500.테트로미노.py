import sys

N, M = input().split()
N = int(N)
M = int(M)

board = []

for _ in range(N):
    line = list(map(int, sys.stdin.readline().rstrip().split()))
    board.append(line)



blocks = [
    # -
    {
        "dy" : [0,0,0,0],
        "dx" : [0,1,2,3]
    },
    # |
    {
        "dy" : [0,1,2,3],
        "dx" : [0,0,0,0]
    },
    # ㅁ
    {
        "dy" : [0,1,1,0],
        "dx" : [0,0,1,1]
    },
    # L
    {
        "dy" : [0,1,2,2],
        "dx" : [0,0,0,1]
    },
    #
    {
        "dy" : [0,0,0,1],
        "dx" : [0,1,2,0]
    },
    #
    {
        "dy" : [0,0,1,2],
        "dx" : [0,1,1,1]
    },
    {
        "dy": [0,1,1,1],
        "dx": [2,0,1,2]
    },
    # L 대칭
    {
        "dy" : [0,1,2,2],
        "dx" : [1,1,0,1]
    },
    #
    {
        "dy": [0,1,1,1],
        "dx": [0,0,1,2]
    },
    #
    {
        "dy": [0,0,1,2],
        "dx": [0,1,0,0]
    },
    #
    {
        "dy": [0,0,0,1],
        "dx": [0,1,2,2]
    },

    # 지그재그
    {
        "dy": [0,1,1,2],
        "dx": [0,0,1,1]
    },
    {
        "dy": [0,0,1,1],
        "dx": [1,2,0,1]
    },
    {
        "dy": [0,1,1,2],
        "dx": [1,1,0,0]
    },
    {
        "dy": [0,0,1,1],
        "dx": [1,0,2,1]
    },

    # ㅗ
    {
        "dy": [0,0,0,1],
        "dx": [0,1,2,1]
    },
    {
        "dy": [0,1,1,2],
        "dx": [1,0,1,1]
    },
    {
        "dy": [0,1,1,1],
        "dx": [1,0,1,2]
    },
    {
        "dy": [0, 1, 1, 2],
        "dx": [0, 0, 1, 0]
    },
]

def sum_all(block, i,j):
    ret = 0
    for k in range(4):
        y = i + block["dy"][k]
        x = j + block["dx"][k]
        if  0 <= y < N and 0 <= x < M:
            ret += board[y][x]

    return ret

answer = -1

for block in blocks:

    for i in range(N):
        for j in range(M):
            cnt = sum_all(block, i, j)
            answer = max(answer, cnt)

print(answer)