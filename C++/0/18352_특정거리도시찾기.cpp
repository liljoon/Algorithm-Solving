#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, x, dist = 0;
    cin >> n >> m >> k >> x;
    bool find = false;
    vector<vector<int>> adj(n + 1);
    vector<int> visited(n + 1, 0);
    vector<int> result;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    queue<int> que;
    que.push(x);
    while (!que.empty())
    {
        queue<int> tempque;
        que.swap(tempque);
        while (!tempque.empty())
        {
            int idx = tempque.front();
            tempque.pop();
            if (visited[idx])
            {
                continue;
            }
            visited[idx] = 1;
            if (dist == k)
            {
                result.push_back(idx);
            }
            for (int i = 0; i < adj[idx].size(); i++)
            {
                que.push(adj[idx][i]);
            }
        }
        dist++;
        if (dist > k)
        {
            break;
        }
    }
    if (result.empty())
    {
        cout << -1 << endl;
    }
    else
    {
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << '\n';
        }
    }
}