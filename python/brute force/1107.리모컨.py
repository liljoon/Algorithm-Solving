n = int(input())
m = int(input())
arr = []
if m != 0:
    arr = list(map(int, input().split()))

temp1 = n
while True:
    if temp1 > 1000000:
        temp1 = 999999999999
        break
    correct = True
    for i in arr:
        if i in list(map(int, str(temp1))):
            correct = False
            break
    if correct:
        break
    temp1 += 1

temp2 = n
while True:
    if temp2 < 0:
        temp2 = 99999999
        break
    correct = True
    for i in arr:
        if i in list(map(int, str(temp2))):
            correct = False
            break
    if correct:
        break
    temp2 -= 1

temp3 = n

ans1 = abs(n - temp1) + len(str(temp1))
ans2 = abs(n - temp2) + len(str(temp2))

ans = min(ans1, ans2, abs(temp3 - 100))
print(ans)
