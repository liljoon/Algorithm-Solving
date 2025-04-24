import sys
sys.setrecursionlimit(10**9)

n = int(input())

trees = dict()

for _ in range(n):
    inp = list(map(int, (sys.stdin.readline().rstrip().split())))
    trees[inp[0]] = {'left':inp[1], 'right':inp[2]}

visited = [False for _ in range(n + 1)]
last_depth = 0

# 중위 순회하면서, 왔다갔다 숫자 계산 후, 최종 종료 시점의 깊이 만큼 제거
def dfs(idx, depth):
    global last_depth
    ret = 0
    if trees[idx]['left'] != -1 and visited[trees[idx]['left']] == False:
        visited[trees[idx]['left']] = True
        ret += dfs(trees[idx]['left'], depth+1) + 2

    last_depth = depth

    if trees[idx]['right'] != -1 and visited[trees[idx]['right']] == False:
        visited[trees[idx]['right']] = True
        ret += dfs(trees[idx]['right'], depth+1) + 2

    return ret

visited[1] = True
print(dfs(1, 0) - last_depth)
