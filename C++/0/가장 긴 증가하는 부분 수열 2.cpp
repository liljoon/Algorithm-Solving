#include<iostream>
#include<vector>
using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		int temp = lower_bound(v.begin(), v.end(), a) - v.begin();
		if (temp == v.size()) {
			v.push_back(a);
		}
		else {
			v[temp] = a;
		}
	}
	cout << v.size() << endl;
}