#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n;
int m;
int v;
vector<vector<int>> adj;
vector<int> visited;
queue<int> que;

void dfs(int idx)
{
    if (visited[idx])
    {
        return;
    }
    visited[idx] = 1;
    cout << idx << " ";
    for (int i = 1; i <= n; i++)
    {
        if (adj[idx][i])
        {
            dfs(i);
        }
    }
}

void bfs(int idx)
{
    que.push(idx);
    while (!que.empty())
    {
        int node = que.front();
        que.pop();
        if (visited[node])
        {
            continue;
        }
        visited[node] = 1;
        cout << node << " ";
        for (int i = 1; i <= n; i++)
        {
            if (adj[node][i])
            {
                que.push(i);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> m;
    cin >> v;
    adj = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
    visited = vector<int>(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    dfs(v);
    visited = vector<int>(n + 1, 0);
    cout << '\n';
    bfs(v);
}