#include<iostream>
#include<algorithm>
using namespace std;


int n;
int solve(int endtime);

struct meet {
	int start;
	int finish;
	bool operator< (meet other) {
		if (finish < other.finish) {
			return true;
		}
		else if (finish == other.finish) {
			if (start < other.start) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
};

meet arr[100001];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].start >> arr[i].finish;
	}
	sort(arr, arr + n);
	/*cout << endl;*/
	/*for (int i = 0; i < n; i++) {
		cout << arr[i].start << " " << arr[i].finish << endl;
	}*/
	cout << solve(-1) << endl;
}

int solve(int end) {
	
	if (end == -1) {
		return solve(0)+1;
	}
	int i = end + 1;
	for (i = end + 1; i < n; i++) {
		if (arr[i].start >= arr[end].finish) {
			break;
		}
	}
	if (i == n) {
		return 0;
	}
	return solve(i) + 1;
}