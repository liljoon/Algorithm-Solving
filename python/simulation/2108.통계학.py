import sys

input = sys.stdin.readline

n = int(input().rstrip())

li = []

for _ in range(n):
    li.append(int(input().rstrip()))

li.sort()
print(round(sum(li) / len(li)))
print(li[len(li) // 2])

d = dict()
for a in li:
    d[a] = d.get(a, 0) + 1
mx = li[0]
for k in d:
    if d[mx] < d[k]:
        mx = k

li2 = []
for k in d:
    if d[k] == d[mx]:
        li2.append(k)
li2.sort()

if len(li2) >= 2:
    print(li2[1])
else:
    print(li2[0])
print(li[-1] - li[0])