import sys
n = int(input())
states = input()
target = input()

states = list(states)
target = list(target)

def toggle(ch):
    if ch == '0':
        return '1'
    else:
        return '0'

def press(idx):
    for i in range(idx - 1, idx + 2):
        if i < 0 or i >= n:
            continue
        states[i] = toggle(states[i])

states_origin = states[:]
cnt = 0
for i in range(1, n):
    if states[i - 1] != target[i - 1]:
        press(i)
        cnt += 1

if states == target:
    print(cnt)
    sys.exit()

states = states_origin[:]

cnt = 1
press(0)
for i in range(1, n):
    if states[i - 1] != target[i - 1]:
        press(i)
        cnt += 1

if states == target:
    print(cnt)
else:
    print(-1)
