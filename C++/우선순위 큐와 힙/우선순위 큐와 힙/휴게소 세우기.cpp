//น้มุ 1477
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct	node {
	int initdata;
	int data;
	int divided = 1;
	node(int a) {
		initdata = a;
		data = a;
	}
};

bool operator<(node a, node b) {
	return a.data < b.data;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, l;
	cin >> n >> m >> l;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(),v.end());
	priority_queue<node,vector<node>,less<node>> pque;
	if (v.size() != 0) {
		pque.push(node(v[0]));
		for (int i = 1; i < n; i++) {
			pque.push(node(v[i] - v[i - 1]));
		}
		pque.push(node(l - v[n - 1]));
	}
	else {
		pque.push(l);
	}

	for (int i = 0; i < m; i++) {
		int init = pque.top().initdata;
		int temp = pque.top().data;
		int div = pque.top().divided;
		pque.pop();
		node tempnode(init);
		tempnode.divided = div + 1;
		tempnode.data = (init + div) / tempnode.divided;
		pque.push(tempnode);
	}
	cout << pque.top().data << '\n';
}