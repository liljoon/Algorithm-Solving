#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a - 1].push_back(make_pair(b - 1, c));
        adj[b - 1].push_back(make_pair(a - 1, c));
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
    vector<int> dist(n, 987654321);
    pque.push(make_pair(0, 0));
    dist[0] = 0;
    while (!pque.empty())
    {
        int cur_dist = pque.top().first;
        int cur_node = pque.top().second;
        pque.pop();

        if (cur_dist > dist[cur_node])
            continue;

        for (int i = 0; i < adj[cur_node].size(); i++)
        {
            int next_dist = cur_dist + adj[cur_node][i].second;
            int next_node = adj[cur_node][i].first;

            if (next_dist < dist[next_node])
            {
                dist[next_node] = next_dist;
                pque.push(make_pair(next_dist, next_node));
            }
        }
    }
    cout << dist[n - 1] << "\n";
}