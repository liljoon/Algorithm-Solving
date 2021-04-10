#include<iostream>
using namespace std;

//น้มุ 11047

int main() {
	int n, k;
	int arr[11];
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int count = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (k == 0) break;
		if (arr[i] > k) continue;
		count += k / arr[i];
		k %= arr[i];
	}
	cout << count << endl;
}