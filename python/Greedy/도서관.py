def solve(arr):
    global m
    i = len(arr) - 1
    ret = 0
    while i >= 0:
        ret += arr[i] * 2
        i -= m
    return ret - arr[-1]


n, m = list(map(int, input().split()))
arr = list(map(int, input().split()))
arr.sort()
i = 0
while i < n:
    if arr[i] > 0:
        break
    i += 1

arr1 = arr[:i]
arr2 = arr[i:]
for i in range(len(arr1)):
    arr1[i] = abs(arr1[i])
arr1.reverse()
a = b = c = d = 0
if len(arr1) > 0:
    a = solve(arr1)
    c = arr1[-1]
if len(arr2) > 0:
    b = solve(arr2)
    d = arr2[-1]

print(a + b + min(c, d))
