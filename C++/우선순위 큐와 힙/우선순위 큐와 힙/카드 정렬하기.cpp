//น้มุ 1715
#include<iostream>
#include<queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pque;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		pque.push(temp);
	}
	int sum = 0;
	while (pque.size() != 1) {
		int first = pque.top();
		pque.pop();
		int second = pque.top();
		pque.pop();
		sum += (first + second);
		pque.push(first + second);
	}
	cout << sum << '\n';
}