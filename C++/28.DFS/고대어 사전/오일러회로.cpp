#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<vector<int>> adj;
vector<int> ans;


void getEulerCircuit(int here)
{
	for (int i = 0; i < n; i++) {
		if (adj[here][i] > 0) {
			adj[here][i]--;
			adj[i][here]--;
			getEulerCircuit(i);
		}
	}
	ans.push_back(here);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	adj = vector<vector<int>>(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> adj[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (adj[i][j] > 0) {
				sum += adj[i][j];
			}
		}
		if (sum % 2 == 1) {
			cout << -1 << '\n';
			return 0;
		}
	}
	getEulerCircuit(0);
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] + 1 << " ";
	}
}