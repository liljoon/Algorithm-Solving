import sys

def solve(day, sum):
    global n
    if day > n+1:
        return 0
    elif day == n+1:
        return sum
    else:
        return max(solve(day+arr[day-1][0], sum+arr[day-1][1]), solve(day+1, sum))


n = int(input())
arr = [[0, 0] for i in range(n)]

for i in range(n):
    li = list(map(int,sys.stdin.readline().split()))
    arr[i][0] = li[0]
    arr[i][1] = li[1]

print(solve(1,0))