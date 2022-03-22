#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int people, n;
vector<pair<int, int>> v;
vector<vector<int>> dp;

int solve(int idx, int now_people)
{

    if (now_people >= people)
    {
        return 0;
    }
    if (idx >= n)
    {
        return 987654321;
    }
    if (dp[idx][now_people] != -1)
    {
        return dp[idx][now_people];
    }
    int a = solve(idx, now_people + v[idx].second) + v[idx].first;
    int b = solve(idx + 1, now_people);
    dp[idx][now_people] = min(a, b);
    return min(a, b);
}

int main()
{
    cin >> people >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    dp = vector<vector<int>>(n, vector<int>(people + 101, -1));
    cout << solve(0, 0) << endl;
}