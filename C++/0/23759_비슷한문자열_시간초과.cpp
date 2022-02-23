#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<string> v;
vector<int> cache;

bool check_adj(int a, int b)
{
    if (a == -1)
    {
        return true;
    }
    for (int i = 0; i < K; i++)
    {
        if (v[a][i] == v[b][i])
        {
            return true;
        }
    }
    return false;
}

int solve(int idx)
{
    if (idx != -1 && cache[idx] != -1)
    {
        return cache[idx];
    }
    int mx = -1;
    for (int i = idx + 1; i < N; i++)
    {
        if (check_adj(idx, i))
        {
            mx = max(solve(i) + 1, mx);
        }
    }
    if (mx != -1)
    {
        if (idx != -1)
        {
            cache[idx] = mx;
        }
        return mx;
    }
    else
    {
        if (idx != -1)
        {
            cache[idx] = 0;
        }
        return 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    cache = vector<int>(N, -1);
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    int res = solve(-1);
    cout << N - res << endl;
}