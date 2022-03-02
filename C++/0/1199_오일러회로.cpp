#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<vector<pair<int, int>>> adj;
vector<vector<int>> map; // 반대방향 간선 줄여야 하는 거 기록
vector<int> adj_sum;

void getEulerCircuit(int here)
{
	for (int i = 0; i < adj[here].size(); i++) {
		if (map[here][adj[here][i].first] > 0) { // 반대 간선 기록 있으면 지우고 가기
			adj[here][i].second -= map[here][adj[here][i].first];
			map[here][adj[here][i].first] = 0;
		}
		if (adj[here][i].second > 0) {
			adj[here][i].second--;
			map[adj[here][i].first][here]++; // 반대 간선 기록
			getEulerCircuit(adj[here][i].first);
		}
		else
		{
			adj[here].erase(adj[here].begin() + i);// 더 이상 간선이 없으면 지우고 한칸 뒤로 해서 시간 초과 해결
			i--;
		}
	}
	cout << here + 1 << " ";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	adj = vector<vector<pair<int, int>>>(n); 
	map = vector<vector<int>>(n, vector<int>(n, 0));
	adj_sum = vector<int>(n, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int in;
			cin >> in;
			if (in != 0) {
				adj[i].push_back(make_pair(j, in));
			}
			adj_sum[i] += in;
		}
	}
	for (int i = 0; i < n; i++) {
		if (adj_sum[i] % 2 == 1) {
			cout << "-1\n";
			return 0;
		}
	}
	getEulerCircuit(0);
	cout << "\n";
}