//백준 11437
#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int n;
int depth[50100];
vector<int> v[50100];
int parent[50100]; 
void solve(int index);
void setdepth(int index, int count);
int m;

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	v[1].push_back(0);
	solve(1);
	setdepth(1, 0);
	
	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		int tempa = a, tempb = b;
		if (depth[a] > depth[b]) {
			for (int j = 0; j < (depth[tempa] - depth[tempb]); j++) {
				a = parent[a];
			}
		}
		else {
			for (int j = 0; j < (depth[tempb] - depth[tempa]); j++) {
				b = parent[b];
			}
		}
		while (1) {
			if (a == b) {
				break;
			}
			a = parent[a];
			b = parent[b];
		}
		cout << a << '\n';
	}
}

//parent 저장
void solve(int index) {
	
	if (v[index].size() == 1) {
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

void setdepth(int index, int count) {

	depth[index] = count;
	if (v[index].size() == 1) {
		return;
	}
	int length = v[index].size();
	for (int i = 0; i < length; i++) {
		if (parent[index] != v[index][i]) {
			setdepth(v[index][i], count + 1);
		}
	}
}
