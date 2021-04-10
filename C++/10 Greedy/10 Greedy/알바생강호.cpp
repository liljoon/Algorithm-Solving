#include<iostream>
#include<algorithm>
using namespace std;


int main() {
	int arr[100001];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	long long int sum = 0;
	int temp = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (arr[i] - temp <= 0) {
			break;
		}
		sum += arr[i] - temp;
		temp++;
	}
	cout << sum << endl;
}