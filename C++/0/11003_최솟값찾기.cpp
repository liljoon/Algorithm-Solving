#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// pque에 계속 저장하면서 index와 함께 저장
// 하나씩 top 확인하면서 최소값 출력
// 만약 범위를 지난 값이 최소로 나오면 pop하고 다시 그 구간 반복

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, l;
    cin >> n >> l;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
    pque.push(make_pair(v[0], 0)); //첫 값 삽입, 값/인덱스
    for (int i = 0; i < n; i++)
    {
        int low = pque.top().first;
        int idx = pque.top().second;
        if (idx < i - l + 1) //방금 확인한 값의 인덱스가 범위를 지났다면 pop하고 다시 반복
        {
            pque.pop();
            i--;
            continue;
        }
        cout << low << " "; //범위 안이라면 출력 후 다음 값 push
        if (i < n - 1)
        {
            pque.push(make_pair(v[i + 1], i + 1));
        }
    }
}