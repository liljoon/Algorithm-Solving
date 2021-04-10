#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n;
vector<long long int> v;

int main() {
	int c;
	cin >> c;
	for (int ci = 0; ci < c; ci++) {
		priority_queue<int, vector<int>, less<int>> lque;
		priority_queue<int, vector<int>, greater<int>> rque;
		cin >> n;
		int a, b;
		cin >> a >> b;
		v.clear();
		v.push_back(1983);
		for (int i = 1; i < n; i++) {
			long long temp;
			temp = (v.back() * a + b) % 20090711;
			v.push_back(temp);
		}
	/*	for (int i = 0; i < n; i++) {
			cout << v[i] << " ";
		}*/
		int mid = v[0];
		v[0] = mid;
		//cout << mid << " ";
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
			//cout << mid << " ";
		}
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum = (sum + v[i]) % 20090711;
		}
		cout << sum << '\n';
	
	}
}