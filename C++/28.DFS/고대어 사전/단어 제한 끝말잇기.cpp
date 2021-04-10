#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> adj;
vector<string> word;
vector<vector<int>> findword;
int n;
vector<int> ans;


void EulerCircuit(int here) {
	for (int i = 0; i < 26; i++) {
		if (adj[here][i] > 0) {
			adj[here][i]--;
			EulerCircuit(i);
		}
	}
	ans.push_back(here);
}

int main() {
	int c;
	cin >> c;
	for (int ci = 0; ci < c; ci++) {
		word.clear();
		findword.clear();
		ans.clear();
		findword = vector<vector<int>>(26, vector<int>(26, 0));
		adj = vector<vector<int>>(26, vector<int>(26, 0));
		cin >> n;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			word.push_back(s);
			adj[(int)s[0] - 97][(int)(s[s.length() - 1] - 97)]++;
			findword[(int)s[0] - 97][(int)(s[s.length() - 1] - 97)] = i;
		}

		/*for (int i = 0; i < n; i++) {
			ans.clear();
			EulerCircuit((int)(word.front()[i] - 97));
			if (n + 1 == ans.size()) {
				break;
			}
		}*/
		EulerCircuit((int)(word.front()[0] - 97));
		if (n + 1 != ans.size()) {
			cout << "IMPOSSIBLE";
		}
		else {
			reverse(ans.begin(), ans.end());
			//다시 원래 단어 찾기
			for (int i = 0; i < ans.size() - 1; i++) {
				cout << word[findword[ans[i]][ans[i + 1]]] << " ";
			}
		}
		cout << '\n';
	}
}