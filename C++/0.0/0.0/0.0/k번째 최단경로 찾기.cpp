#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m, k;
vector<vector<pair<int, int>>> v(n, vector<pair<int, int>>());
vector<vector<int>> record;

vector<int> dijkstra(int src) {
	vector<int> dist(n, 2147483647);
	dist[src] = 0;
	priority_queue<pair<int, int>> pque;
	pque.push(make_pair(0, src));
	while (!pque.empty()) {
		pair<int, int> temp = pque.top();
		pque.pop();
		int length = -temp.first;
		int place = temp.second;

		if (record[place].size() >= k) {
			continue;
		}
		record[place].push_back(length);
		for (int i = 0; i < v[place].size(); i++) {
			int nextlength = length + v[place][i].second;
			int nextplace = v[place][i].first;
			if (dist[nextplace] > nextlength) {
				dist[nextplace] = nextlength;
			}
			pque.push(make_pair(-nextlength, nextplace));
		}
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> k;

	record = vector<vector<int>>(n, vector<int>());
	v = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a - 1].push_back(make_pair(b - 1, c));
	}
	vector<int> dist = dijkstra(0);
	
	for (int i = 0; i < n; i++) {

			if (record[i].size() != k) {
				cout << -1 << endl;
			}
			else {
				cout << record[i].back() << endl;
			}
		}
}