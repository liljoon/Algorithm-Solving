#include<iostream>
using namespace std;

long long int city[100001];
long long int length[100001];

int main() {
	long long int n;
	cin >> n;
	for (long long int i = 0; i < n - 1; i++) {
		cin >> length[i];
	}
	for (long long int i = 0; i < n; i++) {
		cin >> city[i];
	}
	long long int pay = 0;
	long long int min = city[0];
	for (long long int i = 0; i < n - 1; i++) {
		pay += min * length[i];
		if (min > city[i + 1]) {
			min = city[i + 1];
		}
	}
	cout << pay << endl;
}