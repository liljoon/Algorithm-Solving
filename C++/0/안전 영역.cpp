#include<iostream>
#include<vector>
using namespace std;

int n;
int arr[101][101];
vector<vector<int>> vst;

void dfs(int y, int x, int i) {
	if (y >= n || y < 0 || x >= n || x < 0) {
		return;
	}
	if (vst[y][x]) {
		return;
	}
	if (arr[y][x] <= i) {
		return;
	}
	vst[y][x] = 1;
	dfs(y + 1, x, i);
	dfs(y, x + 1, i);
	dfs(y - 1, x, i);
	dfs(y, x - 1, i);
}

int main() {
	
	cin >> n;
	int high = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (high < arr[i][j]) {
				high = arr[i][j];
			}
		}
	}
	int cnt = 0;
	int ans = 0;
	for (int k = 0; k < high; k++) {
		cnt = 0;
		vst = vector<vector<int>>(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (vst[i][j]==0 && arr[i][j]>k) {
					dfs(i, j, k);
					cnt++;
				}
			}
		}
		if (ans < cnt) {
			ans = cnt;
		}
		
	}
	cout << ans << endl;
}