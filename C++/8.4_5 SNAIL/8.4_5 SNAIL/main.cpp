#include<iostream>
#include<cstring>
using namespace std;

double cache[1002][1002];
double solve(int n, int m);

int main() {
	int c;
	cin >> c;
	for (int ci = 0; ci < c; ci++) {
		int n, m;
		cin>> n >> m;
		for (int i = 0; i < 1002; i++) {
			for (int j = 0; j < 1002; j++) {
				cache[i][j] = -1.0;
			}
		}
		cout.precision(11); //10ÀÚ¸®
		cout << solve(n, m) << endl;
	}
}

double solve(int n, int m) {
	if (n <= 0) {
		return 1;
	}
	if (m == 0) {
		return 0;
	}
	double& ret = cache[n][m];
	if (ret != -1.0) {
		return ret;
	}
	ret = 0.75 * solve(n - 2, m - 1) + 0.25 * solve(n - 1, m - 1);
	return ret;
}