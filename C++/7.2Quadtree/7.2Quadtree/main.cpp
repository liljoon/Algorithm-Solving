#include<iostream>
#include<string>
using namespace std;

string input;
int it;
string reverse(int& it);

int main() {
	int c;
	cin >> c;
	for (int ci = 0; ci < c; ci++) {
		it = 0;
		cin >> input;
		cout << reverse(it) << endl;
	}
}

string reverse(int& it) {

	if (input[it] == 'b' || input[it] == 'w') {
		string a = "";
		a += input[it];
		it++;
		return a;
	}
	else if (input[it] == 'x') {
		it++;
		string upleft = reverse(it);

		string upright = reverse(it);

		string downleft = reverse(it);

		string downright = reverse(it);
		
		//cout << downleft + downright + upleft + upright << endl;
		return 'x' + downleft + downright + upleft + upright;
	}
}