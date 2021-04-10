#include<iostream>
#include<cstring>
using namespace std;

int board[200][200];
int board2[200][200];
int n;
int jump2(int y, int x);
int jump(int y, int x);

int main() {
	int c;
	cin >> c;
	for (int ci = 0; ci < c; ci++) {
		memset(board2, -1, sizeof(board2));
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
			}
		}
		if (jump2(0, 0)==1) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << board2[i][j]<<" ";
			}
			cout << endl;
		}*/
	}
}

int jump(int y, int x) {
	if (y == n - 1 && x == n - 1) {
		return 1;
	}
	if (y >= n || x >= n) {
		return 0;
	}
	if (board2[y][x] != -1) {
		return board2[y][x];
	}
	int num = board[y][x];
	int right, down;
	right = jump(y, x + num);
	down = jump(y + num, x);
	board2[y][x] = (right == 1 || down == 1);
	return board2[y][x];
}


int jump2(int y, int x) {
	if (y == n - 1 && x == n - 1) {
		board2[y][x] = 1;
		return 1;
	}
	if (y >= n || x >= n) {
		return 0;
	}
	int num = board[y][x];
	int right, down;
	if (board2[y][x + num] != -1) {
		right = board2[y][x + num];
	}
	else {
		right = jump2(y, x + num);
	}
	if (board2[y + num][x] != -1) {
		down = board2[y + num][x];
	}
	else {
		down = jump2(y + num, x);
	}
	board2[y][x] = (right == 1 || down == 1);
	return board2[y][x];
}