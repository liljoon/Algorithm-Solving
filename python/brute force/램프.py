import sys

inp = list(map(int, sys.stdin.readline().split()))
col, row = inp
arr = [[-1,'a'] for i in range(col)]
for i in range(col):
    s = input()
    for j in arr:
        if j[1] == s:
            j[0] += 1
            break
        elif j[1]=='a':
            j[1] = s
            j[0] = 1
            break
k = int(input())
arr.sort(reverse=True)


for i in range(col):
    if arr[i][1] =='a':
       break
    cnt = arr[i][1].count('0')
    if k%2 == cnt%2 and k >= cnt:
        print(arr[i][0])
        sys.exit()

print(0)