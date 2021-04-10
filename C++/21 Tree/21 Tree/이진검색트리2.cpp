#include<iostream>
#include<vector>
using namespace std;

vector<int> v;
void solve(int start, int finish);
int main() {
	int n;
	while (cin >> n) {
		v.push_back(n);
	}
	solve(0, v.size()-1);
}

void solve(int start, int finish) {
	if (start > finish) {
		return;
	}
	int temp = v[start];
	int length = v.size();
	int i = 0;
	for (i = start + 1; i < length; i++) {
		if (temp < v[i]) {
			break;
		}
	}
	solve(start + 1, i - 1);
	solve(i, finish);
	cout << v[start] << '\n';
}