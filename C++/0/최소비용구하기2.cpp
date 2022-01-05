#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m;
vector<vector<pair<int, int>>> v(n, vector<pair<int, int>>());
vector<int> track;
int start, last;

struct node {
	int first;
	int second;
	int third;
	node(int a, int b, int c) {
		first = a;
		second = b;
		third = c;
	}
};

struct cmp {
	bool operator()(node t, node u) {
		return t.first > u.first;
	}
};


vector<int> dijkstra(int src) {
	vector<int> dist(n, 2147483647);
	dist[src] = 0;
	priority_queue<node,vector<node>,cmp> pque;
	pque.push(node(0, src, -1));
	while (!pque.empty()) {
		node temp = pque.top();
		pque.pop();
		int length = -temp.first;
		int place = temp.second;
		if (length > dist[place]) {
			continue;
		}
		track[place] = temp.third;
		for (int i = 0; i < v[place].size(); i++) {
			int nextlength = length + v[place][i].second;
			int nextplace = v[place][i].first;
			if (dist[nextplace] > nextlength) {
				dist[nextplace] = nextlength;
				pque.push(node(-nextlength, nextplace, place));
				track[nextplace] = place;
			}
		}
	}
	return dist;
}

int cnt = 0;
void print_track(int src) {
	cnt += 1;
	if (src == start - 1) {
		cout << cnt << endl;
		cout << start << " ";
		return;
	}
	print_track(track[src]);
	cout << src + 1 << " ";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	v = vector<vector<pair<int, int>>> (n, vector<pair<int, int>>());
	track = vector<int>(n, -1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a - 1].push_back(make_pair(b - 1, c));
	}

	cin >> start >> last;
	vector<int> dist = dijkstra(start - 1);
	cout << dist[last - 1] << endl;
	print_track(last - 1);
}