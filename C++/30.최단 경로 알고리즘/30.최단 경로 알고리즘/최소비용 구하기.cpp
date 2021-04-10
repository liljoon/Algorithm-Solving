#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

vector<pair<int, int>> adj[1001];
int n, m;

vector<int> dijksta(int src) {
	vector<int> dist(n, 2147483647);
	vector<bool> visited(n, false);
	dist[src] = 0;
	while (1) {
		int closest = 2147483647, here;
		for (int i = 0; i < n; i++) {
			if (closest > dist[i] && !visited[i]) {
				here = i;
				closest = dist[i];
			}
		}
		if (closest == 2147483647) break;
		visited[here] = true;
		for (int i = 0; i < (int)adj[here].size(); i++) {
			int there = adj[here][i].first;
			if (visited[there]) continue;
			int nextDist = dist[here] + adj[here][i].second;
			dist[there] = min(dist[there], nextDist);
		}

	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int start, last, cost;
		cin >> start >> last >> cost;
		adj[start - 1].push_back(make_pair(last - 1, cost));
	}
	int start, finish;
	cin >> start >> finish;
	start--;
	finish--;
	vector<int> v = dijksta(start);
	cout << v[finish] << '\n';
}