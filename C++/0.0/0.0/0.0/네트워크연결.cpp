#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<pair<int, int>>> adj;
int n, m;

int main() {
	cin >> n >> m;
	adj = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());
	vector<int> visited(n, 0);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a - 1].push_back(make_pair(c, b - 1));
		adj[b - 1].push_back(make_pair(c, a - 1));
	}
	priority_queue<pair<int, int>> pque;
	int ret = 0;
	pque.push(make_pair(0, 0));

	while (!pque.empty()) {
		int dist = -pque.top().first;
		int here = pque.top().second;
		pque.pop();
		if (visited[here] == 1) {
			continue;
		}
		visited[here] = 1;
		ret += dist;
		for (int i = 0; i < adj[here].size(); i++) {
			if (visited[adj[here][i].second] == 0) {
				pque.push(make_pair(-adj[here][i].first, adj[here][i].second));
			}
		}
	}
	cout << ret << endl;
}