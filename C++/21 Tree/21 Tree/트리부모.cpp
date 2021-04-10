//น้มุ 11725
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> v;
int n;
int parent[100001];
void solve(int index);

int main() {
	ios::sync_with_stdio(false);
	v.assign(100001, vector<int>(0));
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	v[1].push_back(0);
	solve(1);
	for (int i = 2; i <= n ; i++) {
		cout << parent[i] << '\n';
	}
}

void solve(int index) {
	if (v[index].size()==1) {
		return;
	}
	int length = v[index].size();
	for (int i = 0; i < length; i++) {
		if (parent[index] != v[index][i]) {
			parent[v[index][i]] = index;
			solve(v[index][i]);
		}
	}
}