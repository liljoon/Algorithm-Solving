#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n, m;
vector <vector<int>> adj;
vector<bool> visited;
int rst = 0;

void dfs(int idx,int cnt)
{
	if (rst) {
		return;
	}
	if (cnt >= 5) {
		rst = 1;
		return;
	}
	if (visited[idx])
	{
		return;
	}
	visited[idx] = true;
	for (int i = 0; i < adj[idx].size(); i++) {
		dfs(adj[idx][i], cnt + 1);
	}
	visited[idx] = false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	adj = vector<vector<int>>(n);
	visited = vector<bool>(n, false);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		if (!rst) {
			dfs(i, 0);
		}
	}
	cout << rst << endl;
}