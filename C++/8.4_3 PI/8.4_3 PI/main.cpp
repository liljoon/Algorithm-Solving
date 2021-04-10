#include<iostream>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;

int cache[100000];
string s;
int solve(int start);
int score(int a, int b);
int main() {
	int c; cin >> c;
	for (int ci = 0; ci < c; ci++) {
		memset(cache, -1, sizeof(cache));
		cin >> s;
		cout << solve(0) << endl;
	}
}

int solve(int start) {
	if (cache[start] != -1) {
		return cache[start];
	}
	if (start == s.length()) {
		return 0;
	}
	if ((s.length() - start) == 1 || (s.length() - start) == 2) {
		return 999999;
	}
	
	if ((s.length() - start) == 3) {
		cache[start] = solve(start + 3) + score(start, start + 2);
		return cache[start];
	}
	if ((s.length() - start) == 4) {
		cache[start] = solve(start + 4) + score(start, start + 3);
		return cache[start];
	}
	int cut3 = solve(start + 3) + score(start, start + 2);
	int cut4 = solve(start + 4)+ score(start, start + 3);
	int cut5 = solve(start + 5) + score(start, start + 4);
	
	int mini = min(cut3, cut4);
	cache[start] = min(mini, cut5);
	return cache[start];
}

int score(int a, int b) {
	bool allsame = true;
	for (int i = a; i < b; i++) {
		if (s[i] != s[i + 1]) {
			allsame = false;
			break;
		}
	}
	if (allsame == true) return 1;

	bool alter = true;
	for (int i = a + 2; i <= b; i++) {
		if (s[i] != s[i - 2]) {
			alter = false;
			break;
		}
	}
	if (alter == true) return 4;

	bool mono = true;
	int gap = s[a + 1] - s[a];
	for (int i = a + 1; i < b; i++) {
		if (gap != s[i + 1] - s[i]) {
			mono = false;
			break;
		}
	}
	if (mono == true) {
		if ((s[a + 1] - s[a]) == 1 || (s[a + 1] - s[a]) == -1) {
			return 2;
		}
		else {
			return 5;
		}

	}
	

	return 10;

}