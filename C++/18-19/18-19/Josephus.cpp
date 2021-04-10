#include<iostream>
#include<vector>
using namespace std;

int main() {
	int c;
	cin >> c;
	for (int ci = 0; ci < c; ci++) {
		int n, k;
		cin >> n >> k;
		vector<int> l;
		for (int i = 1; i <= n; i++) {
			l.push_back(i);
		}
		int kill = 0;
		while (l.size() != 2) {
			/*for (int i = 0; i < n; i++) {
				cout << l[i] << " ";
			}
			cout << endl;*/
			vector<int>::iterator iter = l.begin();
			iter += kill;
			l.erase(iter);
			n--;
			kill--;
			kill = (kill + k) % n;
		}
		if (l[0] > l[1]) {
			cout << l[1]<< " " << l[0] << endl;
		}
		else {
			cout << l[0] << " " << l[1] << endl;
		}
	}
}