#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<pair<int, int>> things;
vector<vector<int>> dp;

int solve(int idx, int now_weight)
{
    if (now_weight > m)
    {
        return -987654321;
    }
    if (idx >= things.size())
    {
        return 0;
    }
    if (dp[idx][now_weight] != -1)
    {
        return dp[idx][now_weight];
    }
    int a = solve(idx + 1, now_weight);
    int b = -987654321;
    b = solve(idx + 1, now_weight + things[idx].first) + things[idx].second;
    dp[idx][now_weight] = max(a, b);
    return dp[idx][now_weight];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        while (c > 0) //  반으로 계속 쪼개면서 세트상품으로 만들어 물건 개수 조건 제거
        {
            int temp = c - c / 2;
            c = c / 2;
            things.push_back(make_pair(temp * a, temp * b)); //무게, 만족도
        }
    }
    dp = vector<vector<int>>(things.size() + 1, vector<int>(10001, -1));
    cout << solve(0, 0) << endl;
}