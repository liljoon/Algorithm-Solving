#include<iostream>
#include<algorithm>
using namespace std;
long long int* height;

long long int solve(long long int left, long long int right);

int main() {
	long long int input = 1;
	cin >> input;
	while (input != 0) {
		
		height = new long long int[input];
		for (long long int i = 0; i < input; i++) {
			cin >> height[i];
		}
		cout << solve(0, input - 1) << endl;
		delete[] height;
		cin >> input;
	}




	/*long long int c;
	cin >> c;
	for (long long int ci = 0; ci < c; ci++) {
		long long int n;
		cin >> n;
		for (long long int ni = 0; ni < n; ni++) {
			cin >> height[ni];
		}
		cout << solve(0, n - 1) << endl;

	}*/
}

long long int solve(long long int left, long long int right) {
	if (left == right) {
		return height[left];
	}
	long long int mid = (left + right) / 2;
	long long int leftbig = solve(left, mid);
	long long int rightbig = solve(mid + 1, right);
	long long int result = max(leftbig, rightbig);

	long long int maxh = min(height[mid], height[mid + 1]);
	long long int maxs = maxh * 2;
	long long int midleft = mid;
	long long int midright = mid + 1;
	while (midleft > left || midright < right) {
		if ((height[midleft - 1] < height[midright + 1] || midleft <= left) && midright < right) {
			midright++;
			maxh = min(height[midright], maxh);
		}
		else {
			midleft--;
			maxh = min(height[midleft], maxh);
		}
		maxs = max(maxs, maxh * (midright - midleft + 1));
	}
	result = max(maxs, result);
	return result;
}