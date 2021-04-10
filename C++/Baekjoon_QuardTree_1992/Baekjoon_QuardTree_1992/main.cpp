#include<iostream>	
#include<string>
using namespace std;

int image[65][65];

string solve(int startx, int starty, int lastx, int lasty);

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			image[i][j] = s[j];
		}
	}
	cout << solve(0, 0, n - 1, n - 1) << endl;
}

string solve(int startx, int starty, int lastx, int lasty)
{
	if (startx == lastx && starty == lasty) {
		string s;
		s = image[startx][starty];
		return s;
	}

	int midx = (startx + lastx) / 2;
	int midy = (starty + lasty) / 2;
	string upleft = solve(startx, starty, midx, midy);
	string upright = solve(startx, midy+1, midx, lasty);
	string downleft = solve(midx + 1, starty, lastx, midy);
	string downright = solve(midx + 1, midy + 1, lastx, lasty);
	if (upleft == "0" && upright == "0" && downleft == "0" && downright == "0") {
		return "0";
	}
	else if (upleft == "1" && upright == "1" && downleft == "1" && downright == "1") {
		return "1";
	}
	return "("+upleft + upright + downleft + downright+")";
}
