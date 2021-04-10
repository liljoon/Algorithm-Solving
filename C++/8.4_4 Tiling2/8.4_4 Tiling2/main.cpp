#include<iostream>
#include<cstring>
using namespace std;

int cache[101];
int solve(int n);

int main() {
	int c;
	cin >> c;
	for (int ci = 0; ci < c; ci++) {
		memset(cache, -1, sizeof(cache));
		int n;
		cin >> n;
		cout << solve(n)+1 << endl;

	}
}

int solve(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 0;
	}
	if (cache[n] != -1) {
		return cache[n];
	}
	cache[n] = (solve(n - 1) + solve(n - 2) + 1) % 1000000007;
	return cache[n];
}