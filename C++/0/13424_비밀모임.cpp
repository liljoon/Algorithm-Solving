#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int ti = 0; ti < t; ti++)
	{
		int n, m;
		cin >> n >> m;
		vector<vector<pair<int,int>>> adj(n);
		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			adj[a - 1].push_back(make_pair(b - 1, c));
			adj[b - 1].push_back(make_pair(a - 1, c));
		}
		int k;
		cin >> k;
		vector<vector<int>> length;
		for (int i = 0; i < k; i++)
		{
			int start;
			cin >> start;
			start--;
			priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
			que.push(make_pair(0, start));
			vector<int> visited(n, -1);
			while (!que.empty())
			{
				int len = que.top().first;
				int idx = que.top().second;
				que.pop();
				if (visited[idx] != -1)
				{
					continue;
				}
				visited[idx] = len;
				for (int j = 0; j < adj[idx].size(); j++)
				{
					int next = adj[idx][j].first;
					int next_len = adj[idx][j].second + len;
					if (visited[next] == -1)
					{
						que.push(make_pair(next_len, next));
					}
				}
			}
			length.push_back(visited);
		}
		int mn = 987654321;
		int min_idx = 0;
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = 0; j < k; j++)
			{
				sum += length[j][i];
			}
			if (mn > sum)
			{
				min_idx = i;
				mn = sum;
			}
		}
		cout << min_idx + 1 << endl;
	}
}