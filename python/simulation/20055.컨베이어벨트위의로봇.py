from collections import deque

N, K = list(map(int,input().split()))

belt = list(map(int,input().split()))

belt = deque(belt)

def process_1():
    belt.appendleft(belt.pop())
    for i in range(len(robot_pos)):
        robot_pos[i] += 1


    if len(robot_pos) and robot_pos[len(robot_pos) - 1] == N - 1:
        robot_pos.pop()


def process_2():
    global cnt
    for i in range(len(robot_pos) - 1, -1, -1):
        if belt[robot_pos[i] + 1] >= 1 and (i == len(robot_pos) - 1 or robot_pos[i] + 1 != robot_pos[i + 1]):
            robot_pos[i] += 1
            belt[robot_pos[i]] -= 1
            if belt[robot_pos[i]] == 0:
                cnt += 1
    if len(robot_pos) and robot_pos[len(robot_pos) - 1] == N - 1:
        robot_pos.pop()

def process_3():
    global cnt
    if belt[0] != 0:
        belt[0] -= 1
        if belt[0] == 0:
            cnt += 1
        robot_pos.appendleft(0)

cnt = 0
level = 1
robot_pos = deque()
while True:

    process_1()
    process_2()
    process_3()
    if cnt >= K:
        break
    level += 1

print(level)