#include <iostream>
#include <vector>
using namespace std;

int t, w;
vector<int> v;
vector<vector<vector<int>>> cache;
int solve(int idx, int pos, int hp)
{
    if (idx >= t || hp < 0)
    {
        return 0;
    }
    if (cache[idx][pos][hp] != -1)
    {
        return cache[idx][pos][hp];
    }
    if (v[idx] == pos)
    {
        cache[idx][pos][hp] = 1 + solve(idx + 1, pos, hp);
        return cache[idx][pos][hp];
    }
    else
    {
        int a = 0;
        if (hp != 0) // 더 이상 못 움직일때
        {
            a = 1 + solve(idx + 1, (pos + 1) % 2, hp - 1);
        }
        cache[idx][pos][hp] = max(a, solve(idx + 1, pos, hp));
        return cache[idx][pos][hp];
    }
}

int main()
{
    cin >> t >> w;
    v = vector<int>(t, 0);
    cache = vector<vector<vector<int>>>(t, vector<vector<int>>(2, vector<int>(w + 1, -1)));
    for (int i = 0; i < t; i++)
    {
        cin >> v[i];
        v[i]--;
    }
    cout << solve(0, 0, w) << endl;
}