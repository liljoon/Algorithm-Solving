#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int n;
vector<vector<pair<int,double>>> adj;

vector<double> dijkstra(int src) {
	vector<double> dist(n, 1.79769e+308);
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pque;
	pque.push(make_pair(1, src));
	dist[src] = 1;
	while (!pque.empty()) {
		int here = pque.top().second;
		double cost = pque.top().first;
		pque.pop();
		if (dist[here] < cost) continue;
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			double therecost = adj[here][i].second * cost;
			if (dist[there] > therecost) {
				dist[there] = therecost;
				pque.push(make_pair(therecost, there));
			}
		}
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int ti = 0; ti < t; ti++) {
		cin >> n;
		adj = vector<vector<pair<int, double>>>(n, vector<pair<int, double>>());
		int e;
		cin >> e;
		for (int i = 0; i < e; i++) {
			int a, b;
			double c;
			cin >> a >> b >> c;
			adj[a].push_back(make_pair(b, c));
			adj[b].push_back(make_pair(a, c));
		}
		vector<double> ans = dijkstra(0);
		cout << fixed;
		cout.precision(10);
		cout << ans[n - 1] << '\n';
	}
}