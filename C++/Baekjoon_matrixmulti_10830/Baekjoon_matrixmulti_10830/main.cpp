#include<iostream>
using namespace std;

struct matrix {
	int index[5][5];
};

matrix m;
matrix multi(matrix a, matrix b);
matrix solve(long long int n);
int n;
long long int b;

int main() {
	cin >> n >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int input;
			cin >> input;
			m.index[i][j] = input % 1000;
		}
	}
	matrix m1 = solve(b);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << m1.index[i][j] << " ";
		}
		cout << endl;
	}
}

matrix multi(matrix a, matrix b)
{
	matrix result;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int sum = 0;
			for (int k = 0; k < n; k++) {
				sum += a.index[i][k] * b.index[k][j];
			}
			result.index[i][j] = sum % 1000;
		}
	}
	return result;
}

matrix solve(long long int n)
{
	if (n == 1) {
		return m;
	}
	if (n % 2 == 0) {
		matrix temp = solve(n / 2);
		return multi(temp, temp);
	}
	else {
		return multi(solve(n - 1), m);
	}
}
