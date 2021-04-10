//น้มุ  3015น๘
#include<iostream>
#include<stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	stack<pair<int,int>> st;
	long long int sum = 0;
	for (int i = 0; i < n; i++) {
		int input = 1;
		//cin >> input;
		if (st.empty()) {
			st.push(pair<int,int>(input,1));
			continue;
		}
		int temp = 0;
		while (1) {
			if (st.empty()) {
				break;
			}
			else if (st.top().first > input) {
				sum++;
				break;
			}
			else if (st.top().first == input) {
				temp = st.top().second;
				sum += temp;
				st.pop();
			}
			else {
				sum+=st.top().second;
				st.pop();
			}
		}
		st.push(pair<int, int>(input, temp + 1));
	}
	cout << sum << endl;
}