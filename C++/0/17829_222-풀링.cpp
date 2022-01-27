#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;

int solve(int n, int y, int x)
{
    if (n == 1)
    {
        return v[y][x];
    }
    int temp[4] = {0};
    temp[0] = solve(n / 2, y, x);
    temp[1] = solve(n / 2, y, x + n / 2);
    temp[2] = solve(n / 2, y + n / 2, x);
    temp[3] = solve(n / 2, y + n / 2, x + n / 2);
    sort(temp, temp + 4);
    return temp[2];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    v = vector<vector<int>>(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    cout << solve(n, 0, 0) << endl;
}