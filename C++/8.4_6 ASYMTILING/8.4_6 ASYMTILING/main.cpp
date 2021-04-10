#include<iostream>
#include<cstring>
using namespace std;
int cache2[101];
int cache[101];
int solve(int n);
int solve2(int n);
int main() {
	int c;
	cin >> c;
	for (int ci = 0; ci < c; ci++) {
		memset(cache, -1, sizeof(cache));
		memset(cache2, -1, sizeof(cache2));
		int n;
		cin >> n;
		cout << (solve2(n) - solve(n)+1000000007)%1000000007 << endl;
	}
	
}

int solve(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 0;
	}
	if (n == 2) {
		return 1;
	}
	if (n == 3) {
		return 0;
	}
	if (cache[n] != -1) {
		return cache[n];
	}
	cache[n] = (solve(n - 2) + solve(n - 4) + 1) % 1000000007;
	return cache[n];
}

int solve2(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 0;
	}
	if (cache2[n] != -1) {
		return cache2[n];
	}
	cache2[n] = (solve2(n - 1) + solve2(n - 2) + 1) % 1000000007;
	return cache2[n];

}