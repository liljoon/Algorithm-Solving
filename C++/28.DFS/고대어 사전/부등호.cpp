#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool visited[20];
bool visited2[20];
vector<vector<int>> adj;
vector<vector<int>> adj2;
vector<int> v;
vector<int> v2;

void dfs(int i) {
	if (visited[i] == true) {
		return;
	}
	visited[i] = true;
	int length = adj[i].size();
	//sort(adj[i].begin(), adj[i].end());
	for (int j = 0; j < length; j++) {
		dfs(adj[i][j]);
	}
	v.push_back(i);


}

void dfs2(int i) {
	if (visited2[i] == true) {
		return;
	}
	visited2[i] = true;
	int length = adj2[i].size();
	//sort(adj[i].begin(), adj[i].end());
	for (int j = 0; j < length; j++) {
		dfs2(adj2[i][j]);
	}
	v2.push_back(i);


}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	char c[11];
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	adj = vector<vector<int>>(n + 1, vector<int>());
	adj2 = vector<vector<int>>(n + 1, vector<int>());
	for (int i = 0; i < n; i++) {
		if (c[i] == '<') {
			adj[i].push_back(i + 1);
			adj2[i + 1].push_back(i);
		}
		else {
			adj[i + 1].push_back(i);
			adj2[i].push_back(i + 1);
		}
	}
	for (int i = 0; i < n + 1; i++) {
		if (visited[i] == false) {
			dfs(i);
		}
		if (visited2[i] == false) {
			dfs2(i);
		}
	}
	vector<int> ans(n + 1);
	for (int i = 0; i < v.size(); i++) {
		ans[v[i]] = 9 - i;
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
	}
	for (int i = 0; i < v2.size(); i++) {
		ans[v2[i]] = i;
	}
	cout << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i];
	}

}