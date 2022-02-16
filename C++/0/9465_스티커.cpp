#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> v;
vector<vector<int>> cache;

int solve(int idx, int state) // state : 0 위아래 1 : 위x 2: 아래x
{
    if (idx >= n)
    {
        return 0;
    }
    if (cache[idx][state] != -1)
    {
        return cache[idx][state];
    }
    int a = solve(idx + 1, 0);             // 아무것도 안골랐을때
    int b = solve(idx + 1, 1) + v[0][idx]; // 위 골랐을때
    int c = solve(idx + 1, 2) + v[1][idx]; // 아래 골랐을 때
    if (state == 0)
    {
        cache[idx][state] = max(a, max(b, c));
        return cache[idx][state];
    }
    else if (state == 1)
    {
        cache[idx][state] = max(a, c);
        return cache[idx][state];
    }
    else
    {
        cache[idx][state] = max(a, b);
        return cache[idx][state];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ti++)
    {
        cin >> n;
        v = vector<vector<int>>(2, vector<int>(n, 0));
        cache = vector<vector<int>>(n, vector<int>(3, -1));
        for (int i = 0; i < n; i++)
        {
            cin >> v[0][i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> v[1][i];
        }
        cout << solve(0, 0) << endl;
    }
}