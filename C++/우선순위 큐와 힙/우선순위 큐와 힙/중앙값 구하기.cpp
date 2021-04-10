#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n;
vector<long long int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int c;
	cin >> c;
	for (int ci = 0; ci < c; ci++) {
		priority_queue<int, vector<int>, less<int>> lque;
		priority_queue<int, vector<int>, greater<int>> rque;
		cin >> n;
		v.clear();
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			v.push_back(temp);
		}
		int mid = v[0];
		v[0] = mid;
		for (int i = 1; i < n; i++) {

			if (v[i] > mid) {
				if (rque.size() == lque.size()) {
					rque.push(v[i]);
				}
				else {
					lque.push(mid);
					rque.push(v[i]);
					mid = rque.top();
					rque.pop();
				}
			}
			else {
				if (rque.size() != lque.size()) {
					lque.push(v[i]);
				}
				else {
					rque.push(mid);
					lque.push(v[i]);
					mid = lque.top();
					lque.pop();
				}
			}
			v[i] = mid;
		}
		cout << n / 2 + 1 << '\n';
		for (int i = 0; i < n; i+=2) {
			cout << v[i] << " ";
		}
		cout << '\n';
	}
}