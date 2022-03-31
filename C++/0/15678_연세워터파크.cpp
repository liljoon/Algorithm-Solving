#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// dp[i]는 해당 인덱스를 마지막으로 끝날 경우 최대값
//  dp[i-d]~dp[i-1] 과 현재 위치 값을 더한 것과 기존의 dp[i]와의 최댓값을 구해 저장
//항상 왼쪽부터 출발해서 현재 dp[i]로 도착하는 것으로 순서를 강제
//  자신의 왼쪽에서 가져오는 최대 값을 매번 구하면 시간초과이므로 세그먼트 트리를 이용하거나 우선순위 큐(사용)로 인덱스를 저장하여 해결
// 더해진 거리는 long long 될 수 있음에 주의

int n, d;
vector<long long> v;
vector<long long> dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> d;
    v = vector<long long>(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    dp = v;
    priority_queue<pair<long long, int>> pque;
    for (int i = 0; i < n; i++)
    {
        long long data, idx;
        data = 0;
        while (!pque.empty())
        {
            data = pque.top().first;
            idx = pque.top().second;
            if (idx >= i - d)
            {
                break;
            }
            else
            {
                pque.pop();
            }
        }
        dp[i] = max(dp[i], v[i] + data);
        pque.push(make_pair(dp[i], i));
    }
    long long res = -987654321987654321;
    for (int i = 0; i < n; i++)
    {
        res = max(res, dp[i]);
    }
    cout << res << endl;
}