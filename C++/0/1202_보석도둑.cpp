#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//보석 무게, 가방 무게 정렬
//가방을 기준으로 하나씩 순차적으로 넘어가면서 넣을 수 있는 보석을 pque에 추가하고 가장 가치가 큰 보석을 pop 후 가치 더함
//다음 가방에서도 이어서 pque에 넣을 수 있으므로 시간 초과 X

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> jewels(n);
    vector<int> bags(k);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        jewels[i] = make_pair(a, b);
    }
    for (int i = 0; i < k; i++)
    {
        cin >> bags[i];
    }
    sort(jewels.begin(), jewels.end());
    sort(bags.begin(), bags.end());
    int in_idx = 0;    //이거 전까지 전부 pque에 들어간 보석 index
    long long sum = 0; // 결과 최대치 21억 넘어 가기에 주의
    priority_queue<int> pque;
    for (int i = 0; i < k; i++)
    {
        while (in_idx < n && jewels[in_idx].first <= bags[i])
        {
            pque.push(jewels[in_idx].second);
            in_idx++;
        }
        if (!pque.empty())
        {
            sum += pque.top();
            pque.pop();
        }
    }
    cout << sum << endl;
}