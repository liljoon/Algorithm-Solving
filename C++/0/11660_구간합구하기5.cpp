#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int inp;
            cin >> inp;
            if (j - 1 >= 0)
            {
                inp += v[i][j - 1];
            }
            v[i][j] = inp;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            v[i][j] += v[i - 1][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        x1--;
        y1--;
        x2--;
        y2--;
        int sum = v[y2][x2];
        if (x1 - 1 >= 0)
        {
            sum -= v[y2][x1 - 1];
        }
        if (y1 - 1 >= 0)
        {
            sum -= v[y1 - 1][x2];
        }
        if (y1 - 1 >= 0 && x1 - 1 >= 0)
        {
            sum += v[y1 - 1][x1 - 1];
        }
        cout << sum << '\n';
    }
}