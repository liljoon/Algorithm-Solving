n = int(input())
arr = [[0 for i in range(n)] for j in range(n)]

for i in range(n):
    arr[i] = list(map(int, input()))

arr2 = [[0 for i in range(n)] for j in range(n)]


def solve(y, x):
    if y >= n or x >= n or x < 0 or y < 0:
        return 0
    if arr2[y][x] == 1:
        return 0
    if arr[y][x] == 0:
        return 0
    arr2[y][x] = 1
    return solve(y + 1, x) + solve(y, x + 1) + solve(y - 1, x) + solve(y, x - 1) + 1


ans = []
for i in range(n):
    for j in range(n):
        temp = solve(i,j)
        if temp != 0:
            ans.append(temp)

ans.sort()
print(len(ans))
for i in ans:
    print(i)