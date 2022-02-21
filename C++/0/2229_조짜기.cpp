#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
vector<int> cache;
int n;
int solve(int idx)
{
    if (idx != -1 && cache[idx] != -1)
    {
        return cache[idx];
    }
    int mx = v[idx + 1];
    int mn = v[idx + 1];
    int ret = 0;
    for (int i = idx + 1; i < n; i++)
    {
        mx = max(mx, v[i]);
        mn = min(mn, v[i]);
        int temp = solve(i) + mx - mn;
        ret = max(ret, temp);
    }
    if (idx != -1)
    {
        cache[idx] = ret;
    }
    return ret;
}

int main()
{

    cin >> n;
    v = vector<int>(n);
    cache = vector<int>(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << solve(-1) << endl;
}