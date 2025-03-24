# 각 라인별로 n보다 작은 수 계산
def count(n):
    cnt = 0
    for i in range(1, N + 1):
        cnt += min(n // i, N)
    return cnt

N = int(input())
k = int(input())

# mid 보다 작은 수의 개수를 구하여, 해당 개수가 k가 되는 경우 찾기
left, right = 1, N*N
mid = (left + right) // 2
answer = right

while left <= right:
    cnt = count(mid)

    if cnt >= k:
        right = mid - 1
        answer = min(answer, mid)
    elif cnt < k:
        left = mid + 1
    mid = (left + right) // 2
print(answer)