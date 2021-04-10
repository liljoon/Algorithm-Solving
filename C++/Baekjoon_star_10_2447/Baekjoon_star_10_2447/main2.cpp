#include<iostream>
using namespace std;

string solve(int n);

int main() {
	int n;
	cin >> n;
	string s = solve(n);
	for (int i = 0; i < n*n; i++) {
		if (i% n == 0 && i != 0) {
			cout << endl;
		}
		cout << s[i];
	}
	cout << endl;
}

string solve(int n) {
	if (n == 3) {
		return "**** ****";
	}
	int cut = n / 3;
	string result = "";
	string s = solve(n / 3);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = (i % (n/3)) * cut; k < (i % (n/3) + 1) * cut; k++) {
				if (i >= n / 3 && i < 2 * n / 3 && j == 1) {
					result += " ";
				}
				else {
					result += s[k];
				}
			}
		}
	}
	return result;
}