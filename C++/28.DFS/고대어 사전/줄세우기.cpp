#include<iostream>
#include<vector>
using namespace std;

vector<int> check(32002, 0);
vector<vector<int>> arr;
int n;

void solve(int current) {
	if (check[current] == 1) {
		return;
	}
	for (int i = 0; i < arr[current].size(); i++) {
		if (check[arr[current][i]] == 0) {
			solve(arr[current][i]);
		}
	}
	cout << current+1 << " ";
	check[current] = 1;
}

int main() {
	int m;
	cin >> n >> m;
	arr = vector<vector<int>>(n, vector<int>(0, 0));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[b - 1].push_back(a - 1);
	}
	for (int i = 0; i < n; i++) {
		solve(i);
	}
}