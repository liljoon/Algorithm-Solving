#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define endl "\n"

// 다익스트라 -> 경로 모두 제거 -> 다익스트라 해결
// 최단 경로가 여러 개인데 간선이 겹쳐서 제대로 안지워지는 경우 매우 주의!
//다익스트라 경로 구하는 법 숙지(역으로 추적)
// https://lyzqm.blogspot.com/2017/06/dijkstra-5719.html
// ex)
// 5 8
// 0 4
// 0 1 1
// 0 2 1
// 1 3 1
// 2 3 1
// 3 4 1
// 0 4 6
// 1 4 4
// 2 4 4

int start, des;
int n, m;

vector<int> dijkstra(vector<vector<int>> adj)
{
    vector<int> dist(n, 987654321);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
    pque.push(make_pair(0, start));
    while (!pque.empty())
    {
        int length = pque.top().first;
        int idx = pque.top().second;
        // cout << length << " " << idx << endl;
        pque.pop();
        if (dist[idx] < length)
        {
            continue;
        }
        for (int i = 0; i < n; i++)
        {
            if (adj[idx][i])
            {
                int next_idx = i;
                int next_length = length + adj[idx][i];
                if (dist[next_idx] > next_length)
                {
                    pque.push(make_pair(next_length, next_idx));
                    dist[next_idx] = next_length;
                }
            }
        }
    }
    return dist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (true)
    {
        int res = -1;

        cin >> n >> m;
        if (n == 0 && m == 0)
        {
            break;
        }
        vector<vector<int>> adj(n, vector<int>(n, 0));

        cin >> start >> des;
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a][b] = c;
        }
        vector<int> dist = dijkstra(adj);
        queue<int> que;
        que.push(des);
        vector<int> visited(n, 0);
        // 다익스트라 경로 구하기 위한 bfs
        // 끝부터 역추적 자신이 온 곳에서 최단 거리였는지 확인
        while (!que.empty())
        {
            int here = que.front();
            que.pop();

            for (int i = 0; i < n; i++)
            {
                if (adj[i][here])
                {
                    if (dist[here] == (dist[i] + adj[i][here]))
                    {
                        adj[i][here] = 0;
                        que.push(i);
                    }
                }
            }
        }
        vector<int> dist2 = dijkstra(adj);
        if (dist2[des] == 987654321)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dist2[des] << endl;
        }
    }
}