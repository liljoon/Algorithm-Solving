#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }
    vector<int> visited(n, 0);
    vector<int> tovisit(m);
    for (int i = 0; i < m; i++)
    {
        cin >> tovisit[i];
        tovisit[i]--;
    }
    queue<int> que;
    que.push(tovisit[0]);
    while (!que.empty())
    {
        int idx = que.front();
        que.pop();
        if (visited[idx])
        {
            continue;
        }
        visited[idx] = 1;
        for (int i = 0; i < n; i++)
        {
            if (adj[idx][i])
            {
                que.push(i);
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (!visited[tovisit[i]])
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}