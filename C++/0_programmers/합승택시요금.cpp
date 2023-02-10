#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> dijkstra(int &start, int &n, vector<vector<pair<int, int>>> &vertex)
{
    vector<int> dist(n + 1, 987654321);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
    pque.push(make_pair(0, start));
    dist[start] = 0;

    while (!pque.empty())
    {
        int cost = pque.top().first;
        int cur = pque.top().second;
        pque.pop();

        if (cost > dist[cur])
            continue;
        for (int i = 0; i < vertex[cur].size(); i++)
        {
            int Next = vertex[cur][i].first;
            int nCost = vertex[cur][i].second;

            if (dist[Next] > cost + nCost)
            {
                dist[Next] = cost + nCost;
                pque.push(make_pair(dist[Next], Next));
            }
        }
    }
    return dist;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
    long answer = 987654321;
    vector<vector<pair<int, int>>> vertex(n + 1);

    for (auto i : fares)
    {
        vertex[i[0]].push_back(make_pair(i[1], i[2]));
        vertex[i[1]].push_back(make_pair(i[0], i[2]));
    }
    vector<int> dist[n + 1];

    for (int i = 1; i <= n; i++)
    {
        dist[i] = dijkstra(i, n, vertex);
    }

    for (int i = 1; i <= n; i++)
    {
        if (answer > dist[s][i] + dist[i][a] + dist[i][b])
        {
            answer = dist[s][i] + dist[i][a] + dist[i][b];
        }
    }
    return answer;
}