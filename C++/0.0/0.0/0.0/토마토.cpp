#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int m, n, h;


struct box {
	box(int z, int y, int x) {
		this->x = x;
		this->y = y;
		this->z = z;
	};
	int x;
	int y;
	int z;
};
int arr[100][100][100];
queue<box> que;
queue<box> tempque;

void solve(int z, int y, int x) {
	if (z < 0 || z >= h || y < 0 || y >= n || x < 0 || x >= m) {
		return;
	}
	if (arr[z][y][x] == -1 || arr[z][y][x] == 1) {
		return;
	}
	arr[z][y][x] = 1;
	tempque.push(box(z, y, x));
}

int main() {
	cin >> m >> n >> h;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[k][i][j];
				if (arr[k][i][j] == 1) {
					que.push(box(k, i, j));
				}
			}
		}
	}
	int count = 0;
	while (!que.empty()) {
		while (!que.empty()) {
			int z = que.front().z;
			int y = que.front().y;
			int x = que.front().x;
			que.pop();
			solve(z+1, y, x);
			solve(z-1, y, x);
			solve(z, y+1, x);
			solve(z, y-1, x);
			solve(z, y, x+1);
			solve(z, y, x-1);
		}
		tempque.swap(que);
		count++;
	}
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[k][i][j] == 0) {
					cout << -1 << endl;
					return 0;
				}
			}
		}
	}
	cout << count - 1 << endl;
}