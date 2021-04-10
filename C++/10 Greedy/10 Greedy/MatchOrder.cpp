#include<iostream>
#include<algorithm>
using namespace std;

int arr1[101];
int arr2[101];

int main() {
	int c; 
	cin >> c;
	for (int ci = 0; ci < c; ci++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr1[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> arr2[i];
		}
		sort(arr1, arr1 + n);
		sort(arr2, arr2 + n);
		int i1 = 0;
		int i2 = 0;
		int count = 0;
		while (1) {
			if (i1 >= n || i2 >= n) {
				break;
			}
			if (arr1[i1] <= arr2[i2]) {
				count++;
				i1++;
				i2++;
			}
			else {
				i2++;
			}
		}
		cout << count << endl;

	}
}