def calto2(a):
    global n
    a = bin(a)
    a = str(a)
    a = a[2:]
    a = list(a)
    a = list(0 for i in range(n - len(a))) + a
    return a


def calgap(li):
    sour = 1
    bitter = 0
    global arr
    for i in range(len(li)):
        if li[i] == '1':
            sour *= arr[i][0]
            bitter += arr[i][1]
    return abs(sour - bitter)


n = int(input())
arr = [[0 for col in range(2)] for row in range(n)]
for i in range(n):
    arr[i] = list(map(int, input().split()))

mini = calgap(calto2(1))

for i in range(2, 2 ** n):
    mini = min(mini, calgap(calto2(i)))

print(mini)
