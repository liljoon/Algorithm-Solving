//���� 11399��
#include<iostream>
#include<algorithm>
using namespace std;

int arr[1001];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int temp = 0;
		for (int j = 0; j <= i; j++) {
			temp += arr[j];
		}
		sum += temp;
	}
	cout << sum << endl;
}