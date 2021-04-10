#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m;
vector<vector<int>> map;
bool visited[100][100];

struct node {
	int dist;
	int x;
	int y;
	node(int a, int b, int c) {
		dist = a;
		x = c;
		y = b;
	}

};

struct cmp {
	bool operator()(node a, node b) {
		return a.dist > b.dist;
	}
};

vector<vector<int>> dijkstra() {
	vector<vector<int>> dist(n, vector<int>(m, 987654321));
	priority_queue<node, vector<node>, cmp> pque;
	dist[0][0] = 0;
	pque.push(node(0, 0, 0));
	visited[0][0] = true;
	while (!pque.empty()) {
		int herex = pque.top().x;
		int herey = pque.top().y;
		int herel = pque.top().dist;
		pque.pop();
		visited[herey][herex] = true;
		if ((herex + 1) < m && !visited[herey][herex + 1]) {
			if (dist[herey][herex + 1] > (herel + map[herey][herex + 1])) {
				dist[herey][herex + 1] = (herel + map[herey][herex + 1]);
				pque.push(node(herel + map[herey][herex + 1], herey, herex + 1));
			}

		}
		if ((herex - 1) >= 0 && !visited[herey][herex - 1]) {
			if (dist[herey][herex - 1] > (herel + map[herey][herex - 1])) {
				dist[herey][herex - 1] = (herel + map[herey][herex - 1]);
				pque.push(node(herel + map[herey][herex - 1], herey, herex - 1));
			}

		}


		if ((herey + 1) < n && !visited[herey + 1][herex]) {
			if (dist[herey + 1][herex] > (herel + map[herey + 1][herex])) {
				dist[herey + 1][herex] = (herel + map[herey + 1][herex]);
				pque.push(node(herel + map[herey + 1][herex], herey + 1, herex));
			}
		}
		if ((herey - 1) >= 0 && !visited[herey + -1][herex]) {
			if (dist[herey - 1][herex] > (herel + map[herey - 1][herex])) {
				dist[herey - 1][herex] = (herel + map[herey - 1][herex]);
				pque.push(node(herel + map[herey - 1][herex], herey - 1, herex));
			}
		}
	}
	return dist;
}

int main() {
	cin >> m >> n;
	map = vector<vector<int>>(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = s[j] - '0';
		}
	}
	vector<vector<int>> v = dijkstra();
	cout << v[n - 1][m - 1] << endl;
}