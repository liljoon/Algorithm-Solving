import heapq
import sys

input = sys.stdin.readline

T = int(input())

for _ in range(T):
    n = int(input())
    pq = list(map(int, input().split()))

    heapq.heapify(pq)

    answer = 0
    while len(pq) != 1:
        a = heapq.heappop(pq)
        b = heapq.heappop(pq)
        answer += a+b

        heapq.heappush(pq, a+b)

    print(answer)
