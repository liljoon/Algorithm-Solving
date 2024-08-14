line = input()

cnt = 0

for i in range(len(line) - 1):
    if line[i] != line[i + 1]:
        cnt += 1

print((cnt + 1) // 2)