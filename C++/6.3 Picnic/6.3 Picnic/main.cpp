#include<iostream>
using namespace std;
int countpair(bool taken[10]);
int n,m;//학생수
int marr[10][10];

int main() {
	int c;
	cin >> c;
	for (int ci = 0; ci < c; ci++) {

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				marr[i][j] = 0;
			}
		}
		
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			marr[x][y] = 1;
			marr[y][x] = 1;
		}
		bool taken[10] = { false };
		cout << countpair(taken) << endl;
	}
}

int countpair(bool taken[10]) {

	bool finish = true;
	int first = 0;
	for (first = 0; first < n; first++) {
		if (taken[first] == false) {
			finish = false;
			break;
		}
	}
	if (finish) {
		return 1;
	}
	// 끝
	int result = 0;

	for (int j = first + 1; j < n; j++) {
		if (taken[j] == false && marr[j][first] == 1) {
			taken[j] = taken[first] = true;
			result += countpair(taken);
			taken[j] = taken[first] = false;
		}
	}
	return result;
}