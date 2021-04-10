//น้มุ 1541น๘

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	string s;
	cin >> s;
	vector<int> v;
	vector<char> v2;
	int i = 0;
	while (1) {
		if (i >= s.size()) {
			break;
		}
		string temp = "";
		while (1) {
			if (s[i] == '+' || s[i] == '-' || i == s.size()) {
				v2.push_back(s[i]);
				i++;
				break;
			}
			temp += s[i];
			i++;
		}
		v.push_back(stoi(temp));
	}
	v2.pop_back();
	/*for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << endl;
	}*/
	int sum = v[0];
	int i1 = 1;
	int i2 = 0;
	while (1) {
		if (i2 == v2.size()) {
			break;
		}
		if (v2[i2] == '+') {
			sum += v[i1];
			i1++;
			i2++;
		}
		else if (v2[i2] == '-') {
			break;
		}
	}
	while (1) {
		if (i2 == v2.size() || i1 == v.size()) {
			break;
		}
		sum -= v[i1];
		i1++;
	}
	cout << sum << endl;
}