#include<iostream>
#include<queue>
using namespace std;

struct node {
	int data;
	int abs1;
	node(int a) {
		data = a;
		abs1 = abs(data);
	}
	bool operator>(node b)const {
		if (abs1 == b.abs1) {
			return data > b.data;
		}
		return abs1 > b.abs1;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	priority_queue<node,vector<node>,greater<node>> pque;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		if (input == 0) {
			if (pque.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << pque.top().data << '\n';
				pque.pop();
			}
		}
		else {
			pque.push(node(input));
		}
	}

}