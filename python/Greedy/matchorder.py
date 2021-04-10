t = int(input())

for ti in range(t):
    arr = []
    n = int(input())
    for i in range(2):
        arr.append(list(map(int, input().split())))
    arr[0].sort(reverse=True)
    arr[1].sort(reverse=True)
    i1 = 0
    i2 = 0
    win = 0
    while i1 < n and i2 < n:
        if arr[0][i1] <= arr[1][i2]:  # 승리시
            win += 1
            i1 += 1
            i2 += 1
        else:
            i1 += 1

    print(win)
