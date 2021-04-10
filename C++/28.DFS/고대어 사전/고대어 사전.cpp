#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int n;
vector<string> word;
vector<vector<int>> adj;
bool visited[26];
vector<int> ans;

void setadj() {
	for (int i = 0; i < n - 1; i++) {
		int j = 0;
		while (1) {
			if (word[i].length() <= j || word[i + 1].length() <= j) {
				break;
			}
			if (word[i][j] == word[i + 1][j]) {
				j++;
			}
			else {
				adj[(int)word[i][j] - 97][(int)word[i + 1][j] - 97] = 1;
				break;
			}
		}

	}
}

bool checkcircle() {
	for (int i = 0; i < 26; i++) {
		for (int j = i + 1; j < 26; j++) {
			if (adj[ans[j]][ans[i]] == 1) {
				return false;
			}
		}
	}
	return true;
}

void dfs(int here) {
	if (visited[here]) {
		return;
	}
	visited[here] = true;
	for (int i = 0; i < 26; i++) {
		if (adj[here][i] == 1) {
			dfs(i);
		}
	}
	ans.push_back(here);
}

int main() {
	int c;
	cin >> c;
	for (int ci = 0; ci < c; ci++) {
		ans.clear();
		adj.clear();
		for (int i = 0; i < 26; i++) {
			visited[i] = false;
		}
		adj = vector<vector<int>>(26, vector<int>(26, 0));
		word.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			string temp;
			cin >> temp;
			word.push_back(temp);
		}
		setadj();
		for (int i = 0; i < 26; i++) {
			dfs(i);
		}
		reverse(ans.begin(), ans.end());
		if (!checkcircle()) {
			cout << "INVALID HYPOTHESIS" << endl;
		}
		else {
			for (int i = 0; i < ans.size(); i++) {
				cout << (char)(ans[i] + 97);
			}
			cout << '\n';
		}
	}
}
