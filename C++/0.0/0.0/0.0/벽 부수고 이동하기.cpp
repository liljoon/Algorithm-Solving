#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> v;
vector<vector<int>> vst;
vector<vector<int>> vst2;
int n, m;

struct node {
	int first;
	int second;
	int third;
	node(int first, int second, int third) {
		this->first = first;
		this->second = second;
		this->third = third;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	v = vector<vector<int>>(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			v[i][j] = (int)(s[j] - '0');
		}
	}
	int ret = 987654321;
	vst = vector<vector<int>>(n, vector<int>(m, 0));
	vst2 = vector<vector<int>>(n, vector<int>(m, 0));
	queue<node> que;
	que.push(node(0, 0, 1));
	int cnt = 0;
	while (!que.empty()) {
		queue<node> tempque;
		while (!que.empty()) {
			int y = que.front().first;
			int x = que.front().second;
			int wall = que.front().third;
			que.pop();
			if (y == n - 1 && x == m - 1) {
				tempque = queue<node>();
				vst[n - 1][m - 1] = 1;
				vst2[n - 1][m - 1] = 1;
				break;
			}
			if (x < 0 || x >= m || y < 0 || y >= n) {
				continue;
			}
			if (vst[y][x] && wall == 1) {
				continue;
			}
			if ((vst2[y][x]||vst[y][x]) && wall == 0) {
				continue;
			}
			if (v[y][x] == 1 && wall == 0) {
				continue;
			}
			if (v[y][x] == 1 && wall == 1) {
				vst2[y][x] = 1;
				tempque.push(node(y + 1, x, 0));
				tempque.push(node(y, x + 1, 0));
				tempque.push(node(y, x - 1, 0));
				tempque.push(node(y - 1, x, 0));
				continue;
			}
			if (wall == 1) {
				vst[y][x] = 1;
			}
			else {
				vst2[y][x] = 1;
			}
			
			tempque.push(node(y + 1, x, wall));
			tempque.push(node(y, x + 1, wall));
			tempque.push(node(y, x - 1, wall));
			tempque.push(node(y - 1, x, wall));
		}
		cnt++;
		que.swap(tempque);
	}
	if (vst2[n - 1][m - 1] == 1) {
		cout << cnt << endl;
	}
	else {
		cout << -1 << endl;
	}
}