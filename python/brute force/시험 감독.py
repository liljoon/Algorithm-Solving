import math

n = int(input())
arr = list(map(int, input().split()))
li = list(map(int, input().split()))
b = li[0]
c = li[1]
for i in range(n):
    arr[i] -= b

sum = n
for i in range(n):
    if arr[i] > 0:
        sum += math.ceil(arr[i] / c)


print(sum)
