#include<iostream>
using namespace std;

int h, w;
int fillboard(int board[20][20]);


int main() {
	int c;
	cin >> c;
	for (int ci = 0; ci < c; ci++) {
		int board[20][20];
		cin >> h >> w;
		int count = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				char inp;
				cin >> inp;
				if (inp == '#') {
					board[i][j] = 1;
				}
				else if (inp == '.') {
					board[i][j] = 0;
					count++;
				}
			}
		}
		// board에 저장
		if ((count % 3) != 0) {
			cout << 0 << endl;
			continue;
		}
		cout << fillboard(board) << endl;
	}
}

int fillboard(int board[20][20])
{
	bool finish = true;
	bool error = false;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (board[i][j] != 1) {
				finish = false;
			}
			if (board[i][j] > 1) {
				error = true;
			}
		}
	}
	if (error == true) {
		return 0;
	}
	//base case1 : error
	if (finish == true) {
		return 1;
	}//base case2 : finish

	bool exit = false;
	int fh = 0, fw = 0;
	for (fh = 0; fh < h; fh++) {
		for (fw = 0; fw < w; fw++) {
			if (board[fh][fw] == 0) {
				exit = true;
				break;
			}
		}
		if (exit == true) break;
	}
	int result = 0;
	if ((fw - 1) >= 0 && (fh + 1) < h) {
		board[fh][fw]++;
		board[fh + 1][fw]++;
		board[fh + 1][fw - 1]++;
		result += fillboard(board);
		board[fh][fw]--;
		board[fh + 1][fw]--;
		board[fh + 1][fw - 1]--;
	}
	//┘모양

	if ((fw + 1) < w && (fh + 1) < h) {
		board[fh][fw]++;
		board[fh + 1][fw]++;
		board[fh + 1][fw + 1]++;
		result += fillboard(board);
		board[fh][fw]--;
		board[fh + 1][fw]--;
		board[fh + 1][fw + 1]--;
	}
	//└ 모양

	if ((fw + 1) < w && (fh + 1) < h) {
		board[fh][fw]++;
		board[fh][fw+1]++;
		board[fh + 1][fw + 1]++;
		result += fillboard(board);
		board[fh][fw]--;
		board[fh][fw+1]--;
		board[fh + 1][fw+ 1]--;
	}
	//┐모양

	if ((fw + 1) < w && (fh + 1) < h) {
		board[fh][fw]++;
		board[fh][fw + 1]++;
		board[fh + 1][fw]++;
		result += fillboard(board);
		board[fh][fw]--;
		board[fh][fw + 1]--;
		board[fh + 1][fw]--;
	}
	//┌모양

	return result;
}
