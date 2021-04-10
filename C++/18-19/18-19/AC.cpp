//น้มุ 5430
#include<iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int ti = 0; ti < t; ti++) {
		queue<int> que;
		string command;
		cin >> command;
		int n;
		cin >> n;
		char temp;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			int temp1;
			cin >> temp1;
			que.push(temp1);
		}
		if (n == 0) {
			cin >> temp;
		}
		cin >> temp;
		bool error = false;
		int length = command.length();
		for (int i = 0; i < length; i++) {
			if (command[i] == 'R') {
				stack<int> st;
				for (int j = 0; j < n; j++) {
					int temp = que.front();
					st.push(temp);
					que.pop();
				}
				for (int j = 0; j < n; j++) {
					que.push(st.top());
					st.pop();
				}
			}
			else if (command[i] == 'D') {
				if (que.empty()) {
					error = true;
					break;
				}
				que.pop();
				n--;
			}
		}
		if (error) {
			cout << "error" << endl;
		}
		else {
			cout << '[';
			for (int i = 0; i < n; i++) {
				cout << que.front();
				if (i != n - 1) cout << ',';
				que.pop();
			}
			cout <<']'<< endl;
		}
	}
}