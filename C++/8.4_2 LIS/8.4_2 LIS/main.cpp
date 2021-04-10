#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int arr[1000001];
int cache[1000001];
int n;
int solve(int start);
int main() {
	int c = 1;
	//cin >> c;
	for (int ci = 0; ci < c; ci++) {
		
		memset(cache, -1, sizeof(cache));
		
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int result = 0;
		for (int i = 0; i < n; i++) {
			result = max(result, solve(i));
		}
		cout << result << endl;

	}
}

int solve(int start) {
	int& ret = cache[start];
	if (ret != -1) {
		return ret;
	}
	ret = 1;
	for (int next = start + 1; next < n; next++) {
		if (arr[start] < arr[next]) {
			ret = max(ret, solve(next) + 1);
		}
	}
	return ret;
}