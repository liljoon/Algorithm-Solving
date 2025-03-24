import sys

def isPossible(n):
    now = homes[0]
    cnt = 1
    for i in range(1, len(homes)):
        if homes[i] >= now + n:
            now = homes[i]
            cnt += 1
    if cnt < C:
        return False
    else:
        return True


N, C = input().split()
N = int(N)
C = int(C)

homes = []
for _ in range(N):
    homes.append(int(sys.stdin.readline().rstrip()))

homes.sort()

left, right = 1, homes[-1] - homes[0]
mid = (left + right) // 2

answer = 0

while left <= right:
    if isPossible(mid):
        answer = max(answer, mid)
        left = mid + 1
    else:
        right = mid - 1

    mid = (left + right) // 2

print(answer)