import sys
inp_list = list(map(str, sys.stdin.readline().split()))
a = inp_list[0]
b = inp_list[1]
gap = b.__len__()-a.__len__()
ans = 99999
print(inp_list)

for j in range(gap+1):
    sum = 0
    for i in range(a.__len__()):
        if a[i] != b[i+j]:
            sum += 1
    ans = min(ans,sum)

print(ans)