#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> build_time;
vector<vector<int>> adj;
vector<int> before;
vector<int> all_time;
int n;
int dest;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int ti = 0; ti < t; ti++)
    {
        cin >> n;
        before.assign(n + 1, 0);
        all_time.assign(n + 1, 0);
        build_time.assign(n + 1, 0);
        adj = vector<vector<int>>(n + 1);
        int m;
        cin >> m;
        for (int i = 1; i <= n; i++)
            cin >> build_time[i];
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            before[b]++;
        }
        cin >> dest;
        queue<int> que;
        for (int i = 1; i <= n; i++)
        {
            if (before[i] == 0)
            {
                all_time[i] = build_time[i];
                que.push(i);
            }
        }
        while (!que.empty())
        {
            int idx = que.front();
            que.pop();
            for (int i = 0; i < adj[idx].size(); i++)
            {
                int next = adj[idx][i];
                before[next]--;
                all_time[next] = max(all_time[next], all_time[idx] + build_time[next]);
                if (before[next] == 0)
                    que.push(next);
            }
        }
        cout << all_time[dest] << endl;
    }
}