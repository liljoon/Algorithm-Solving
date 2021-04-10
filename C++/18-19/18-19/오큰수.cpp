#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int arr[1000000];

int main() {
	vector<int> v(1000000, -1);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	stack<int> st;
	st.push(0);
	for (int i = 1; i < n; i++) {
		while (1) {
			if (st.empty()) {
				break;
			}
			if (arr[st.top()] < arr[i]) {
				v[st.top()] = arr[i];
				st.pop();
			}
			else {
				break;
			}
		}
		st.push(i);
	}
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	cout << endl;

}