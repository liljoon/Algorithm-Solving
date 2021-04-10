def fivo(n):
    a = 0
    b = 1
    c = 0
    for i in range(n):
        c = (a + b) % 1000000000
        a, b = b, a
        a = c
    return c

n = int(input())
if n < 0:
    if abs(n) % 2 == 1:
        print(1)
    else:
        print(-1)
elif n == 0:
    print(0)
else:
    print(1)
print(fivo(abs(n)))