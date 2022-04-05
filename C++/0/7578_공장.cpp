#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

// 기계 번호를 인덱스로 배열에 순서를 집어 넣어
// 하단 기계번호를 입력받아 위의 기계번호의 순서를 지금 순서로 넣어 match배열 작성
// 처음부터 순차적으로 선을 잇고 도착지점에 오른쪽에 이미 방문한 기계가 있다면 그 전에서 이미 이어 진 것으로 무조건 교차함 -> 방문한 개수만큼 더함
// 매번 방문하면서 세면 시간초과이므로 세그먼트 트리를 이용하여 업데이트와 쿼리 수행
// n이 500000이므로 전부 교차하면 정수 범위 벗어남 주의

vector<long long> tree;
vector<int> visited;

void update(int start, int end, int node, int idx)
{
    if (idx < start || idx > end)
    {
        return;
    }
    else if (start == end)
    {
        visited[idx] = 1;
        tree[node] = 1;
    }
    else
    {
        int mid = (start + end) / 2;
        update(start, mid, node * 2, idx);
        update(mid + 1, end, node * 2 + 1, idx);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

long long query(int start, int end, int left, int right, int node)
{
    if (right < start || left > end)
    {
        return 0;
    }
    else if (left <= start && right >= end)
    {
        return tree[node];
    }
    else
    {
        int mid = (start + end) / 2;
        long long a = query(start, mid, left, right, node * 2);
        long long b = query(mid + 1, end, left, right, node * 2 + 1);
        return a + b;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> where(1000001);
    vector<int> match(n + 1);
    visited.resize(n, 0);
    tree.resize(4 * n, 0);
    for (int i = 0; i < n; i++) // 인덱스를 번호로 위치 저장
    {
        int a;
        cin >> a;
        where[a] = i;
    }
    for (int i = 0; i < n; i++) // 저장한 위치를 이용하여 match 배열 작성
    {
        int a;
        cin >> a;
        match[where[a]] = i;
    }
    long long sum = 0; // long long 주의
    for (int i = 0; i < n; i++)
    {
        int dest = match[i];
        update(0, n - 1, 1, dest);                  // 도착지 방문하고 업데이트
        sum += query(0, n - 1, dest + 1, n - 1, 1); // 도착지 오른쪽 전부 이미 방문한 개수 더함
    }
    cout << sum << endl;
}