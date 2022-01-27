#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<char>> v;

void solve(int n, int y, int x)
{
    if (n == 1)
    {
        v[y][x] = '*';
        return;
    }
    if (n % 2 == 1)
    {
        int l = (int)pow(2, n) - 1;
        for (int i = 0; i < l; i++) //대각선
        {
            v[y + i][x + i] = '*';
            v[y + i][x - i] = '*';
        }
        for (int i = x - l + 1; i < x + l; i++) //밑변
        {
            v[y + l - 1][i] = '*';
        }
        v[y][x] = '*';
        solve(n - 1, y + (int)pow(2, n) - 3, x);
    }
    else
    {
        int l = (int)pow(2, n) - 1;
        for (int i = 0; i < l; i++) //대각선
        {
            v[y - i][x + i] = '*';
            v[y - i][x - i] = '*';
        }
        for (int i = x - l + 1; i < x + l; i++) //밑변
        {
            v[y - l + 1][i] = '*';
        }
        solve(n - 1, y - (int)pow(2, n) + 3, x);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    int n;
    cin >> n;
    int l = (int)pow(2, n) - 1;
    v = vector<vector<char>>(2 * (int)pow(2, n) - 3, vector<char>(2 * (int)pow(2, n) - 3, ' '));
    if (n % 2 == 1)
    {
        solve(n, 0, (int)pow(2, n) - 2);
    }
    else
    {
        solve(n, (int)pow(2, n) - 2, (int)pow(2, n) - 2);
    }
    for (int i = 0; i < (int)pow(2, n) - 1; i++)
    {
        int lim;
        if (n % 2 == 1)
        {
            lim = (int)pow(2, n) - 1 + i;
        }
        else
        {
            lim = 2 * l - 1 - i;
        }
        for (int j = 0; j < lim; j++)
        {
            cout << v[i][j];
        }
        cout << endl;
    }
}