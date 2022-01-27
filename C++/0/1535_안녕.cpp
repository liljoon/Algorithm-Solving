#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
vector<int> L;
vector<int> J;

int solve(int index,int hp,int happy) {
	if (hp <= 0) {
		return 0;
	}
	if (index >= n) {
		return happy;
	}
	return max(solve(index + 1, hp, happy), solve(index + 1, hp-L[index],happy+J[index]));

}

int main() {
	
	cin >> n;
	L = vector<int>(n, 0);
	J = vector<int>(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> L[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> J[i];
	}
	cout << solve(0, 100, 0) << endl;


}