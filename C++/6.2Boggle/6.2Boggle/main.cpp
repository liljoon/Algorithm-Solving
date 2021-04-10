#include<iostream>
using namespace std;

bool checkaround(char arr[5][5], int n, int i, int j,string input);

int main() {
	int a;
	cin >> a;
	char arr[5][5]{ {'U','R','L','P','M'}, 
					{'X','P','R','E','T'},
					{'G','I','A','E','T'},
					{'X','T','N','Z','Y'},
					{'X','O','Q','R','S'} };
	string input;
	for (int s = 0; s < a; s++) {
		bool result = false;
		cin >> input;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (arr[i][j] == input[0]) {
					result = checkaround(arr, 1, i, j, input);
					if (result == true) {
						break;
					}
				}
			}
			if (result == true)break;
		}
		if (result) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}

bool checkaround(char arr[5][5], int n, int i, int j, string input) {
	if (n >= input.length()) {
		return true;
	}
	for (int x = -1; x <= 1; x++) {
		for (int y = -1; y <= 1; y++) {
			if (x == 0 && y == 0) {
				continue;
			}
			if ((i + x >= 0 && i + x < 5) && (j +y >= 0 && j + y < 5)) {
				if (input[n] == arr[x + i][j + y]) {
					if (checkaround(arr, n + 1, i + x, j + y, input)) {
						return true;
					}
				}
			}
		}
	}
	return false;

}