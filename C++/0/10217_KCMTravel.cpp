#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct node
{
	int next, cost, time;
	node(int _next,int _cost,int _time) :next(_next), cost(_cost), time(_time) {}
};

struct cmp
{
	bool operator() (node& a, node& b) {
		return a.time > b.time;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int ti = 0; ti < t; ti++)
	{
		int n, m, k;
		bool found = false;
		cin >> n >> m >> k;
		vector<vector<node>> adj(n);
		vector<vector<int>> visited_time(n, vector<int>(10001, 987654321));
		for (int i = 0; i < k; i++)
		{
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			adj[a - 1].push_back(node(b - 1, c, d));
		}
		priority_queue<node, vector<node>, cmp> pque;
		pque.push(node(0, 0, 0));
		while(!pque.empty())
		{
			int idx = pque.top().next;
			int cost_sum = pque.top().cost;
			int time_sum = pque.top().time;
			pque.pop();
			if (cost_sum > m)
			{
				continue;
			}
			if (time_sum > visited_time[idx][cost_sum])
			{
				continue;
			}
			if (idx == n - 1)
			{
				cout << time_sum << "\n";
				found = true;
				break;
			}
			visited_time[idx][cost_sum] = time_sum;
			for (int i = 0; i < adj[idx].size(); i++)
			{
				int next_idx = adj[idx][i].next;
				int next_time = time_sum + adj[idx][i].time;
				int next_cost = cost_sum + adj[idx][i].cost;
				if (next_cost <= m && next_time < visited_time[next_idx][next_cost])
				{
					visited_time[next_idx][next_cost] = next_time;
					pque.push(node(next_idx, next_cost, next_time));
				}
			}

		}
		if(!found)
		{
			cout << "Poor KCM" << "\n";
		}
	}
}