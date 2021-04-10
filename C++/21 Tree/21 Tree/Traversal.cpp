#include<iostream>
using namespace std;

int n;
int arr1[1001];
int arr2[1001];
void solve(int root, int start, int finish);

int main() {
	int c = 1;
	//cin >> c;
	for (int ci = 0; ci < c; ci++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr1[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> arr2[i];
		}
		solve(0, 0, n-1);
		cout << endl;
	}
	
}

void solve(int root, int start, int finish) {
	if (start > finish) {
		return;
	}
	int i = start;
	for (i = start; i <= finish; i++) {
		if (arr1[root] == arr2[i]) {
			break;
		}
	}
	solve(root+1, start, i - 1);
	solve(i - start + root + 1, i + 1, finish);
	cout << arr1[root] << " ";
}