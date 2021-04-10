#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> map;
queue<pair<int, int>> que;
vector<vector<pair<int, int>>> parent;

int x, y;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int tempx, tempy;

void bfs() {

	while (!que.empty()) {
		tempy = que.front().first;
		tempx = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++) {
			if (tempy + dy[i] >= 0 && tempy + dy[i] < y && tempx + dx[i] >= 0 && tempx + dx[i] < x) {
				if (map[tempy + dy[i]][tempx + dx[i]] == 0) {
					map[tempy + dy[i]][tempx + dx[i]] = 1;
					parent[tempy + dy[i]][tempx + dx[i]] = pair<int, int>(tempy, tempx);
					que.push(pair<int, int>(tempy + dy[i], tempx + dx[i]));
				}
			}
		}

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> x >> y;
	parent = vector<vector<pair<int, int>>>(y, vector<pair<int, int>>(x, pair<int, int>(-1, -1)));
	map = vector<vector<int>>(y, vector<int>(x, 0));
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				que.push(pair<int, int>(i, j));
			}
		}
	}
	bfs();
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (map[i][j] == 0) {
				cout << -1 << '\n';
				return 0;
			}
		}
	}

	int tx = tempx, ty = tempy;//마지막 1된 자리
	int ans = 0;
	while (1) {
		if (parent[ty][tx].first == -1 && parent[ty][tx].second == -1) {
			break;
		}
		int xx, yy;
		xx = parent[ty][tx].second;
		yy = parent[ty][tx].first;
		tx = xx;
		ty = yy;
		ans++;
	}
	cout << ans << endl;


}