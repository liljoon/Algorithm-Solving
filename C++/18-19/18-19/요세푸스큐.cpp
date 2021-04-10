#include<iostream>
#include<queue>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	queue<int> que;
	for (int i = 0; i < n; i++) {
		que.push(i + 1);
	}
	int count = 0;
	cout << '<';
	while (n != 0) {
		if (count == k-1) {
			if (n == 1) {
				cout << que.front();
			}
			else { cout << que.front() << ',' << " "; }
			que.pop();
			count = (count + 1) % k;
			n--;
		}
		else {
			int temp = que.front();
			que.pop();
			que.push(temp);
			count = (count + 1) % k;
		}
	}
	cout << '>' << endl;

}