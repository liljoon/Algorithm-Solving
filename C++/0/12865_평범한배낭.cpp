#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, rst;
vector<vector<int>> cache, v;

int solve(int idx, int weight)
{
    if (idx == n)
    {
        return 0;
    }
    if (cache[idx][weight] != -1)
    {
        return cache[idx][weight];
    }
    int a = 0;
    if (weight - v[idx][0] >= 0)
    {
        a = v[idx][1] + solve(idx + 1, weight - v[idx][0]);
    }
    int b = solve(idx + 1, weight);
    cache[idx][weight] = max(a, b);
    return max(a, b);
}

int main()
{
    cin >> n >> k;
    v = vector<vector<int>>(n, vector<int>(2, 0));
    cache = vector<vector<int>>(n, vector<int>(k + 1, -1));
    for (int i = 0; i < n; i++)
    {
        cin >> v[i][0] >> v[i][1];
    }
    cout << solve(0, k) << endl;
}