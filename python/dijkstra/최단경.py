import sys
import heapq

v, e = map(int, input().split())
k = int(input())


def dijkstra(k):
    dist = [987654321 for i in range(v)]
    dist[k] = 0
    heap = []

    heapq.heappush(heap, [0, k])
    while len(heap) != 0:
        temp = heapq.heappop(heap)
        cost = temp[0]
        here = temp[1]
        if dist[here] < cost:
            continue
        for i in range(len(adj[here])):
            there = adj[here][i][0]
            nextdist = cost + adj[here][i][1]
            if dist[there] > nextdist:
                dist[there] = nextdist
                heapq.heappush(heap, (nextdist, there))

    return dist


adj = [[] for i in range(v)]

for i in range(e):
    a, b, c = map(int, sys.stdin.readline().split())
    adj[a - 1].append((b - 1, c))
ans = dijkstra(k - 1)

for i in ans:
    if i == 987654321:
        print('INF')
    else:
        print(i)
