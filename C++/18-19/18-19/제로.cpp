//น้มุ10773
#include<iostream>
#include<stack>
using namespace std;

int main() {
	stack<int> st;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (temp == 0) {
			st.pop();
		}
		else {
			st.push(temp);
		}
	}
	int sum = 0;
	while (!st.empty()) {
		sum += st.top();
		st.pop();
	}
	cout << sum << endl;

}