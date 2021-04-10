#include<iostream>
#include<stack>
using namespace std;

int main() {
	int c;
	cin >> c;
	for (int ci = 0; ci < c; ci++) {
		stack<char> st;
		string s;
		cin >> s;

		for (int i = 0; i < s.length(); i++) {
			if (st.empty() == true) {
				st.push(s[i]);
			}
			else if (st.top() == '(' && s[i] == ')') {
				st.pop();
			}
			else if (st.top() == '{' && s[i] == '}') {
				st.pop();
			}
			else if (st.top() == '[' && s[i] == ']') {
				st.pop();
			}
			else {
				st.push(s[i]);
			}
		}
		if (st.empty() == true) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}


	}
}