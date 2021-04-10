def solve(starty, startx):
    cnt1 = 0
    cnt2 = 0
    for i in range(starty, starty + 8):
        for j in range(startx, startx + 8):
            if (i % 2 == 0 and j % 2 == 0) or (i % 2 == 1 and j % 2 == 1):
                if arr[i][j] == 1:
                    cnt1 += 1
                else:
                    cnt2 += 1
            else:
                if arr[i][j] == 1:
                    cnt2 += 1
                else:
                    cnt1 += 1

    return min(cnt1, cnt2)


m, n = map(int, input().split())
arr = [[0 for i in range(n)] for i in range(m)]

for i in range(m):
    s = input()
    for j in range(n):
        if s[j] == 'B':
            arr[i][j] = 0
        else:
            arr[i][j] = 1

ans = 987654321

for i in range(m - 7):
    for j in range(n - 7):
        ans = min(solve(i, j), ans)

print(ans)
