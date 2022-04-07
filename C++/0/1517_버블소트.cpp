#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 좌표 압축 후 방문한 숫자를 visited에 저장
// 뒤에서 부터 하나 씩 넣어 현재 자신 보다 작은 수 중에 들어간 수들을 전부 더함
// 더하는 과정을 세그먼트 트리로 계속 업데이트하여 시간초과 해결

vector<int> idx;        //좌표 압축한 배열
vector<int> v;          //입력 배열
vector<int> visited;    // 방문한 숫자 기록 (압축한 배열을 기준으로 인덱싱)
vector<long long> tree; // visited를 기준으로 범위의 합 기록, 정수범위 초과 주의

int getidx(int x) //압축한 배열에서 몇번째인지 알려주는 함수
{
    return lower_bound(idx.begin(), idx.end(), x) - idx.begin();
}

long long query(int start, int end, int node, int left, int right)
{
    if (left > end || right < start)
    {
        return 0;
    }
    else if (left <= start && end <= right)
    {
        return tree[node];
    }
    else
    {
        int mid = (start + end) / 2;
        int a = query(start, mid, node * 2, left, right);
        int b = query(mid + 1, end, node * 2 + 1, left, right);
        return a + b;
    }
}

void update(int start, int end, int node, int idx) // idx 는 압축한 배열의 인덱스
{
    if (start > idx || idx > end)
    {
        return;
    }
    else if (start == end)
    {
        tree[node]++;
        visited[idx]++;
    }
    else
    {
        int mid = (start + end) / 2;
        update(start, mid, node * 2, idx);
        update(mid + 1, end, node * 2 + 1, idx);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    idx.resize(n);
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        idx[i] = a;
        v[i] = a;
    }
    sort(idx.begin(), idx.end());
    idx.erase(unique(idx.begin(), idx.end()), idx.end()); //윗줄과 함께 좌표 압축하기
    visited.resize(n, 0);
    tree.resize(4 * n);
    long long sum = 0; //정수 범위 초과 주의
    for (int i = n - 1; i >= 0; i--)
    {
        sum += query(0, n - 1, 1, 0, getidx(v[i]) - 1);
        update(0, n - 1, 1, getidx(v[i]));
    }
    cout << sum << endl;
}