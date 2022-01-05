#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void move(int from, int to, vector<vector<int>>& v) {
	if (v[from].size() == 0) {
		return;
	}
	if (v[to].size()== 0  || v[from].back() < v[to].back()) {
		v[to].push_back(v[from].back());
		v[from].pop_back();
	}
}

int solve(queue<pair<int, int>> que, vector<vector<int>> v) {
	while (que.size() != 0) {

	}
}

int main() {
	int t;
	cin >> t;
	vector<vector<int>> v = vector<vector<int>>(4, vector<int>());
	for (int ti = 0; ti < t; ti++) {
		int n;
		cin >> n;
		for (int q = 0; q < 4; q++) {
			int a;
			cin >> a;
			for (int ai = 0; ai < a; ai++) {
				int b;
				cin >> b;
				v[q].push_back(b);
			}
		}
		

		while (v[3].size() != n) {
			
		}


		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < v[i].size(); j++) {
				cout << v[i][j] << " ";
			}
			cout << endl;
		}


	}
}