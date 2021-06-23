#include<iostream>
#include<queue>
using namespace std;

int arr[101][101];
int chk[101][101];
int n, m;
bool fin = false;
queue<pair<int,int>> que;
queue<pair<int, int>> tempque;

void solve(int y, int x){
	if (y == n - 1 && x == m - 1) {
		fin = true;
		return;
	}
	if (y < 0 || y >= n || x < 0 || x >= m) {
		return;
	}
	if (arr[y][x] == 0 || chk[y][x] == 1) {
		return;
	}
	chk[y][x] = 1;
	tempque.push(make_pair(y, x));
}

int main() {
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		for (int j = 0; j < m; j++) {
			arr[i][j] = (int)a[j] - 48;
		}
	}
	int count = 0;
	que.push(make_pair(0, 0));
	while (!fin) {
		tempque = queue<pair<int, int>>();
		while (!que.empty()) {
			int y = que.front().first;
			int x = que.front().second;
			que.pop();
			solve(y+1, x);
			solve(y, x+1);
			solve(y-1, x);
			solve(y, x-1);
		}
		tempque.swap(que);
		count += 1;
	}
	cout << count + 1 << endl;
}