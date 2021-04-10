#include<iostream>
#include<queue>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int ti = 0; ti < t; ti++) {
		int n;
		cin >> n;
		int m;
		cin >> m;
		int arr[100];
		queue<int> que;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < n; i++) {
			que.push(i);
		}
		int time = 1;
		while (1) {
			int temp = que.front();
			int length = que.size();
			bool print = true;
			for (int i = 0; i < length; i++) {
				if (arr[que.front()] > arr[temp]) {
					print = false;
				}
				que.push(que.front());
				que.pop();
			}
			if (que.front() == m && print) {
				break;
			}
			if (print) {
				que.pop();
				time++;
			}
			else {
				que.push(que.front());
				que.pop();
			}
		}

		cout << time << endl;

	}
}