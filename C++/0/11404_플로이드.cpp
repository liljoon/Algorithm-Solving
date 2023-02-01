#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<vector<long long>> adj;

int main()
{
    cin >> n >> m;
    adj = vector<vector<long long>>(n, vector<long long>(n, 9876543210000));
    for (int i = 0; i < m; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        adj[a - 1][b - 1] = min(adj[a - 1][b - 1], c);
    }
    for (int i = 0; i < n; i++)
        adj[i][i] = 0;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == 9876543210000)
                cout << "0 ";
            else
                cout << adj[i][j] << ' ';
        }
        cout << endl;
    }
}