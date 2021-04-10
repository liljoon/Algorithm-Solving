#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int n;
vector<pair<int,int>> adj[801];

vector<int> dijkstra(int src) {
	vector<bool> visited(n, false);
	vector<int> dist(n, 987654321);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pque;
	dist[src] = 0;
	pque.push(make_pair(0, src));
	while (!pque.empty()) {
		int here = pque.top().second;
		int length = pque.top().first;
		pque.pop();
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].second;
			int therelength = length + adj[here][i].first;
			if ( dist[there] > therelength) {
				dist[there] = therelength;
				pque.push(make_pair(therelength, there));
			}

		}
	}
	return dist;
}

int main() {
	cin >> n;
	int e;
	cin >> e;
	for (int i = 0; i < e; i++) {
		int st, la, cost;
		cin >> st >> la >> cost;
		adj[st-1].push_back(make_pair(cost, la-1));
		adj[la-1].push_back(make_pair(cost, st-1));
	}
	int mid1, mid2;
	cin >> mid1 >> mid2;
	mid1--;
	mid2--;
	int sum1 = 0, sum2 = 0;
	vector<int> v = dijkstra(0);

	sum1 += v[mid1];
	sum2 += v[mid2];
	if (sum1 > 900000000 || sum2 > 900000000) {
		cout << -1 << endl;
		return 0;
	}
	v = dijkstra(mid1);
	sum1 += v[mid2];
	sum2 += v[n - 1];
	if (sum1 > 900000000 || sum2 > 900000000) {
		cout << -1 << endl;
		return 0;
	}

	v = dijkstra(mid2);
	sum1 += v[n - 1];
	sum2 += v[mid1];
	if (sum1 > 900000000 || sum2 > 900000000) {
		cout << -1 << endl;
		return 0;
	}

	cout << (sum1 < sum2 ? sum1 : sum2) << endl;

}