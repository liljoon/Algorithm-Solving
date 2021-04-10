#include<iostream>
using namespace std;

int board[100][100];
int n;

int jump(int y, int x);

int main() {
	int c;
	cin >> c;
	for (int ci = 0; ci < c; ci++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}
		if (jump(n - 1, n - 1)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}


	}
}

int jump(int y, int x) {
	if (y == 0 && x == 0) {
		return 1;
	}
	
	for (int i = 0; i < y; i++) {
		if (board[i][x] == y - i) {
			if (jump(i, x) == 1) {
				return 1;
			}
		}
	}

	for (int i = 0; i < x; i++) {
		if (board[y][i] == x - i) {
			if (jump(y, i) == 1) {
				return 1;
			}
		}
	}

	return 0;
}