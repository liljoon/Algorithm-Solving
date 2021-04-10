#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

vector<pair<int, int>> adj[20000];
vector<int> dist;
int v;

void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
	pque.push(pair<int, int>(0, start));
	dist = vector<int>(v, 2147483646);
	dist[start] = 0;
	while (!pque.empty()) {
		int length = pque.top().first;
		int here = pque.top().second;
		pque.pop();

		if (dist[here] < length) continue;

		for (int i = 0; i < adj[here].size(); i++) {
			if (dist[adj[here][i].first] > (length + adj[here][i].second)) {
				pque.push(pair<int, int>(length + adj[here][i].second, adj[here][i].first));
				dist[adj[here][i].first] = length + adj[here][i].second;
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int e, start;
	cin >> v >> e >> start;
	start--;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a - 1].push_back(pair<int, int>(b - 1, c));
	}
	dijkstra(start);
	for (int i = 0; i < v; i++) {
		if (dist[i] == 2147483646) {
			cout << "INF" << '\n';
		}
		else {
			cout << dist[i] << '\n';
		}
	}
	
}