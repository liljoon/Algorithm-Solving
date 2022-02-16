#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> cache;
vector<int> v;
int n;
int solve(int idx, int last)
{

    if (idx >= n)
    {
        return 0;
    }
    if (cache[idx][last] != -1)
    {
        return cache[idx][last];
    }
    if (v[last] >= v[idx]) //못 넣을때
    {
        cache[idx][last] = solve(idx + 1, last);
        return cache[idx][last];
    }
    int a = solve(idx + 1, idx) + 1; //넣을 때
    int b = solve(idx + 1, last);    // 안 넣을 때
    cache[idx][last] = max(a, b);
    return cache[idx][last];
}
int main()
{
    cin >> n;
    v = vector<int>(n, 0);
    cache = vector<vector<int>>(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = max(res, solve(i, i) + 1);
    }
    cout << res << endl;
}