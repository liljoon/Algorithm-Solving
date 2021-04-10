#include<iostream>
#include<algorithm>
using namespace std;

struct score {
	int test1;
	int test2;
	bool operator<(score other) {
		if (test1 < other.test1) {
			return true;
		}
		else {
			return false;
		}
	}
};

score arr[100001];

int main() {
	int t;
	cin >> t;
	for (int ti = 0; ti < t; ti++) {
		
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i].test1 >> arr[i].test2;
		}
		sort(arr, arr + n);
		
		int mini = arr[0].test2;
		int count = 1;

		for (int i = 1; i < n; i++) {
			if (mini > arr[i].test2) {
				mini = arr[i].test2;
				count++;
			}
		}
		cout << count << endl;
	}
}