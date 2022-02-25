#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> map;
vector<int> v(3, 0);
void solve(int y, int x, int size)
{
    bool same = true;
    if (size != 1)
    {
        for (int i = y; i < y + size; i++)
        {
            for (int j = x; j < x + size; j++)
            {
                if (map[i][j] != map[y][x])
                {
                    same = false;
                    break;
                }
            }
            if (same == false)
            {
                break;
            }
        }
    }
    if (same)
    {
        if (map[y][x] == -1)
        {
            v[0]++;
        }
        else if (map[y][x] == 0)
        {
            v[1]++;
        }
        else
        {
            v[2]++;
        }
    }
    else
    {
        int cut = size / 3;
        solve(y, x, size / 3);
        solve(y + cut, x, size / 3);
        solve(y + 2 * cut, x, size / 3);
        solve(y, x + cut, size / 3);
        solve(y, x + 2 * cut, size / 3);
        solve(y + cut, x + cut, size / 3);
        solve(y + 2 * cut, x + cut, size / 3);
        solve(y + cut, x + 2 * cut, size / 3);
        solve(y + 2 * cut, x + 2 * cut, size / 3);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    map = vector<vector<int>>(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
    solve(0, 0, n);
    for (int i = 0; i < 3; i++)
    {
        cout << v[i] << '\n';
    }
}