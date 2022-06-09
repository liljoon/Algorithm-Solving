#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> dp;
vector<int> trace;
int n;

int solve(int idx)
{
    int m = 0;
    int m_idx = 0;
    if (dp[idx] != -1)
        return dp[idx];
    for (int i = idx + 1; i <= n; i++)
    {
        if (v[i] > v[idx])
        {
            if (m < solve(i) + 1)
            {
                m = solve(i) + 1;
                m_idx = i;
            }
        }
    }
    trace[idx] = m_idx;
    dp[idx] = m;
    return m;
}

int main()
{
    cin >> n;
    v.assign(n + 1, 0);
    dp.assign(n + 1, -1);
    trace.assign(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i + 1];
    }
    cout << solve(0) << endl;
    int start = trace[0];
    while (trace[start] != 0)
    {
        cout << v[start] << " ";
        start = trace[start];
    }
    cout << v[start];
}