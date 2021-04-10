#include<iostream>
#include<algorithm>
using namespace std;
int arr[101][101];
int cache[101][101];

int main() {
	int c;
	cin >> c;
	for (int ci = 0; ci < c; ci++) {
		int n;
		cin >> n;
		//입력받기
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				if (i == 0) {
					cache[0][0] = arr[0][0];
				}
				else if (j == 0) {
					cache[i][j] = cache[i - 1][j] + arr[i][j];
				}
				else {
					cache[i][j] = max(cache[i - 1][j - 1] + arr[i][j], cache[i - 1][j] + arr[i][j]);
				}

			}


		}
		int result = 0;
		for (int i = 0; i < n; i++) {
			result = max(cache[n - 1][i], result);
		}
		cout << result << endl;
	}
}