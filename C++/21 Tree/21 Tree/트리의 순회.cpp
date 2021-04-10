#include<iostream>
using namespace std;

int n;
int arr1[100001];
int arr2[100001];
void solve(int root, int start, int finish);

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> arr2[i];
	}
	solve(n-1, 0, n - 1);
	cout << endl;
}

void solve(int root, int start, int finish) {
	if (start > finish) {
		return;
	}
	int i = start;
	for (i = start; i <= finish; i++) {
		if (arr2[root] == arr1[i]) {
			break;
		}
	}
	cout << arr2[root] << " ";
	solve(root - (finish-i+1), start, i - 1);
	solve(root-1, i+1, finish);
}