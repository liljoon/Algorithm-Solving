#include<iostream>
using namespace std;

int w, h;
int map[51][51];
bool visited[51][51];
int island;

void dfs(int y, int x) {
	if (x < 0 || x >= w || y < 0 || y >= h) {
		return;
	}
	if (map[y][x] == 0) {
		return;
	}
	if (visited[y][x] == true) {
		return;
	}
	visited[y][x] = true;
	dfs(y - 1, x - 1);
	dfs(y - 1, x);
	dfs(y - 1, x + 1);
	dfs(y, x - 1);
	dfs(y, x + 1);
	dfs(y + 1, x - 1);
	dfs(y + 1, x);
	dfs(y + 1, x + 1);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (1) {
		for (int i = 0; i < 51; i++) {
			for (int j = 0; j < 51; j++) {
				map[i][j] = 0;
				visited[i][j] = 0;
			}
		}

		cin >> w >> h;
		if (w == 0 && h == 0) {
			break;
		}
		island = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (visited[i][j] == false && map[i][j] == 1) {
					dfs(i, j);
					island++;
				}
			}
		}
		cout << island << '\n';


	}
	return 0;
}