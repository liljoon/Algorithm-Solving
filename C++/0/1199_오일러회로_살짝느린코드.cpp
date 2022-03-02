#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<vector<pair<int, int>>> adj;
vector<int> adj_sum;

void getEulerCircuit(int here)
{
	for (int i = 0; i < adj[here].size(); i++) {
		if (adj[here][i].second > 0) {
			adj[here][i].second--;

			for (int j = 0; j < adj[adj[here][i].first].size(); j++)
			{
				if (adj[adj[here][i].first][j].first == here)
				{
					adj[adj[here][i].first][j].second--;
				}
			}
			getEulerCircuit(adj[here][i].first);
		}
		else
		{
			adj[here].erase(adj[here].begin() + i);// 더 이상 간선이 없으면 지우고 한칸 뒤로 해서 시간 초과 해결
			i--;
		}
	}
	cout << here + 1 << " ";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	adj = vector<vector<pair<int, int>>>(n);
	adj_sum = vector<int>(n, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int in;
			cin >> in;
			if (in != 0) {
				adj[i].push_back(make_pair(j, in));
			}
			adj_sum[i] += in;
		}
	}
	for (int i = 0; i < n; i++) {
		if (adj_sum[i] % 2 == 1) {
			cout << "-1\n";
			return 0;
		}
	}
	getEulerCircuit(0);
	cout << "\n";
}