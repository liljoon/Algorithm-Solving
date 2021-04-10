#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> haveline;
vector<vector<int>> adj;
vector<bool> visited;

//전부 이어져있는지.
void check(int here) {
	if (visited[here] == true) {
		return;
	}
	visited[here] = true;
	for (int i = 0; i < n; i++) {
		if (adj[here][i] == 1) {
			adj[here][i]--;
			adj[i][here]--;
			check(i);
		}
	}
}

int main() {
	cin >> n;
	int e;
	cin >> e;
	haveline = vector<int>(n, 0);
	adj = vector<vector<int>>(n, vector<int>(n, 0));
	visited = vector<bool>(n, false);
	for (int i = 0; i < e; i++) {
		int a, b;
		cin >> a >> b;
		adj[a - 1][b - 1] = 1;
		adj[b - 1][a - 1] = 1;
		haveline[a-1]++;
		haveline[b-1]++;
	}
	
	check(0);
	for (int i = 0; i < n; i++) {
		if (visited[i] == false) {
			cout << "NO" << endl;
			return 0;
		}
	}


	int oddn = 0;
	for (int i = 0; i < n; i++) {
		if (haveline[i] % 2 == 1) {
			oddn++;
		}
	}
	if (oddn == 2 || oddn == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

}