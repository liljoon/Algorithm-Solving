#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> map;
vector<int> vst1;
vector<int> vst2;

int solve(int y, int x)
{
    if (y == n)
        return 0;
    if (x >= n)
    {
        if ((x == n && n % 2) || (x == n + 1 && n % 2 == 0))
            return solve(y + 1, 0);
        else
            return solve(y + 1, 1);
    }
    int a = solve(y, x + 2);
    if (map[y][x] == 0 || vst1[n + y - x] || vst2[y + x])
        return a;
    vst1[n + y - x] = 1;
    vst2[y + x] = 1;
    int b = solve(y, x + 2);
    vst1[n + y - x] = 0;
    vst2[y + x] = 0;
    return max(a, b + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vst1.assign(2 * n, 0);
    vst2.assign(2 * n, 0);

    map = vector<vector<int>>(n, vector<int>(n, 1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
    cout << solve(0, 0) + solve(0, 1) << endl;
}