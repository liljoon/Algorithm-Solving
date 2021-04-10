#include<iostream>
#include<vector>
#include<list>
using namespace std;

int n;
vector<list<int>> v;
bool visited[1001];


void dfs(int k) {
	if (visited[k] == true) {
		return;
	}
	visited[k] = true;
	int length = v[k].size();
	for (int i = 0; i < length; i++) {
		if (visited[v[k].front()] == false) {
			dfs(v[k].front());
			v[k].pop_front();
		}
		else {
			v[k].pop_front();
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int m;
	int sum = 0;
	cin >> m;
	v = vector <list<int>>(n, list<int>());
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a - 1].push_back(b - 1);
		v[b - 1].push_back(a - 1);
	}
	for (int i = 0; i < n; i++) {
		if (visited[i] == false) {
			dfs(i);
			sum++;
		}
	}
	cout << sum << '\n';
}