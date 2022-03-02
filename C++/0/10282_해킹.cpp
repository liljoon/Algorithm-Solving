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
		int all_time = 0;
		int n, d, c;
		cin >> n >> d >> c;
		c--;
		int cnt = 0;
		vector<vector<pair<int, int>>> adj(n);
		vector<int> visited(n, 0);
		for (int i = 0; i < d; i++)
		{
			int a, b, s;
			cin >> a >> b >> s;
			a--;
			b--;
			adj[b].push_back(make_pair(a, s));
		}
		priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
		pque.push(make_pair(0, c));
		while (!pque.empty())
		{
			int time = pque.top().first;
			int idx = pque.top().second;
			pque.pop();
			if (visited[idx])
			{
				continue;
			}
			visited[idx] = 1;
			cnt++;
			all_time = max(all_time, time);
			for (int i = 0; i < adj[idx].size(); i++)
			{
				pque.push(make_pair(time + adj[idx][i].second, adj[idx][i].first));
			}
		}
		cout << cnt << " " << all_time << endl;
	}
}