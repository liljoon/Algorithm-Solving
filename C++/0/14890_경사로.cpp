#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, l;
    cin >> n >> l;
    vector<vector<int>> map(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        bool possible = true;
        vector<int> v(n, 0);
        for (int j = 0; j < n - 1; j++)
        {
            if (map[i][j] + 1 == map[i][j + 1])
            {
                if (j < l - 1)
                {
                    possible = false;
                    break;
                }
                for (int k = 0; k < l; k++)
                {
                    if (map[i][j - k] != map[i][j] || v[j - k] == 1)
                    {
                        possible = false;
                        break;
                    }
                }
                if (!possible)
                {
                    break;
                }
                else
                {
                    for (int k = 0; k < l; k++)
                    {
                        v[j - k] = 1;
                    }
                }
            }
            else if (map[i][j] == map[i][j + 1] + 1)
            {
                if (j >= n - l)
                {
                    possible = false;
                    break;
                }
                for (int k = j + 1; k <= j + l; k++)
                {
                    if (map[i][k] != map[i][j + 1] || v[k] == 1)
                    {
                        possible = false;
                        break;
                    }
                }
                if (!possible)
                {
                    break;
                }
                else
                {
                    for (int k = j + 1; k <= j + l; k++)
                    {
                        v[k] = 1;
                    }
                }
            }
            else if (map[i][j] == map[i][j + 1])
            {
                continue;
            }
            else
            {
                possible = false;
                break;
            }
        }

        if (possible)
        {
            cnt++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        bool possible = true;

        vector<int> v(n, 0);
        for (int j = 0; j < n - 1; j++)
        {
            if (map[j][i] + 1 == map[j + 1][i])
            {
                if (j < l - 1)
                {
                    possible = false;
                    break;
                }
                for (int k = 0; k < l; k++)
                {
                    if (map[j - k][i] != map[j][i] || v[j - k] == 1)
                    {
                        possible = false;
                        break;
                    }
                }
                if (!possible)
                {
                    break;
                }
                else
                {
                    for (int k = 0; k < l; k++)
                    {
                        v[j - k] = 1;
                    }
                }
            }
            else if (map[j][i] == map[j + 1][i] + 1)
            {
                if (j >= n - l)
                {
                    possible = false;
                    break;
                }
                for (int k = j + 1; k <= j + l; k++)
                {
                    if (map[k][i] != map[j + 1][i] || v[k] == 1)
                    {
                        possible = false;
                        break;
                    }
                }
                if (!possible)
                {
                    break;
                }
                else
                {
                    for (int k = j + 1; k <= j + l; k++)
                    {
                        v[k] = 1;
                    }
                }
            }
            else if (map[j][i] == map[j + 1][i])
            {
                continue;
            }
            else
            {
                possible = false;
                break;
            }
        }

        if (possible)
        {
            cnt++;
        }
    }

    cout << cnt << endl;
}