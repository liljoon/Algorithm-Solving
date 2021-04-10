#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };

int n;
int x, y;
int targetx, targety;
vector<vector<bool>> checked;
queue<pair<int, int>>  que;
vector<vector<pair<int,int>>> parent;

void bfs() {
	while (!que.empty()) {
		int tempy = que.front().first;
		int tempx = que.front().second;
		que.pop();
		if (tempy == targety && tempx == targetx) {
			break;
		}
		for (int i = 0; i < 8; i++) {
			if (tempy + dy[i] >= 0 && tempy + dy[i] < n && tempx + dx[i] >= 0 && tempx + dx[i] < n) {
				if (!checked[tempy + dy[i]][tempx + dx[i]]) {
					checked[tempy + dy[i]][tempx + dx[i]] = true;
					que.push(pair<int, int>(tempy + dy[i], tempx + dx[i]));
					parent[tempy + dy[i]][tempx + dx[i]] = pair<int, int>(tempy, tempx);
				}

			}
		}
	}
}


int main() {
	int t;
	cin >> t;
	for (int ti = 0; ti < t; ti++) {
		que = queue<pair<int, int>>();
		checked.clear();
		cin >> n;
		checked = vector<vector<bool>>(n, vector<bool>(n, false));
		parent = vector<vector<pair<int,int>>>(n, vector<pair<int,int>>(n, pair<int, int>(-1, -1)));
		cin >> x >> y;
		cin >> targetx >> targety;
		checked[y][x] = true;
		que.push(pair<int, int>(y, x));
		bfs();
		int tempy = targety, tempx = targetx;
		int ans = 0;
		while(1) {
			if (tempy == y && tempx == x) {
				break;
			}
			int tx, ty;
			ty = parent[tempy][tempx].first;
			tx = parent[tempy][tempx].second;
			tempy = ty;
			tempx = tx;
			ans++;
		}
		cout << ans << '\n';

	}
}