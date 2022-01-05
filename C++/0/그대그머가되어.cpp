#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cout.tie(NULL);
	

	int start, last;
	cin >> start >> last;
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>());
	vector<int> chk(n,0);
	queue<pair<int, int>> que;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a - 1].push_back(b - 1);
		v[b - 1].push_back(a - 1);
	}
	que.push(make_pair(start-1, 0));
	bool found = false;
	while(!que.empty()) {
		pair<int,int> temp = que.front();
		que.pop();
		if (temp.first == last-1) {
			found = true;
			cout << temp.second << endl;
			break;
		}
		if (chk[temp.first] == 1) {
			continue;
		}
		chk[temp.first] = 1;
		for (int i = 0; i < v[temp.first].size(); i++) {
			que.push(make_pair(v[temp.first][i], temp.second + 1));
		}
	}
	if (!found) {
		cout << -1 << endl;
	}
}