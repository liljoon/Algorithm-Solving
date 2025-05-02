import heapq

n = int(input())

works = []

for _ in range(n):
    d, w = input().split()
    works.append((int(d), int(w)))


works.sort()
pque = []

answer = 0
day = works[-1][0]
# 맨 뒤 날짜부터 가능한 과제 중 가장 큰 값을 할당
while day > 0:
    while len(works) and works[-1][0] >= day:
        heapq.heappush(pque, (-works[-1][1], -works[-1][0]))
        works.pop()
    if len(pque):
        answer += -1 * heapq.heappop(pque)[0]

    day -= 1

print(answer)