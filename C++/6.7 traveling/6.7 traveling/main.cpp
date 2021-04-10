#include<iostream>
using namespace std;
int cost[10][10];
int n;
int nextplace(bool went[20], int whereis, int sumcost);

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cost[i][j];
		}
	}
	bool went[20] = { false };
	went[0] = true;
	cout << nextplace(went, 0, 0) << endl;
}

int nextplace(bool went[20],int whereis, int sumcost)
{
	bool finish = true;
	for (int i = 0; i < n; i++) {
		if (went[i] == false) {
			finish = false;
			break;
		}
	}
	if (finish) {
		if (cost[whereis][0] == 0) {
			return 1e9;
		}
		else {
			return (cost[whereis][0] + sumcost);
		}
	}
	//basecase

	int min[20];
	for (int i = 0; i < 20; i++) {
		min[i] = 1e9;
	}
	
	for (int i = 0; i < n; i++) {
		if (went[i] == false && cost[whereis][i] != 0) {
			went[i] = true;
			min[i] = nextplace(went, i, sumcost + cost[whereis][i]);
			went[i] = false;
		}
	}

	int minimum = min[0];
	for (int i = 1; i < n; i++) {
		if (min[i] < minimum) {
			minimum = min[i];
		}
	}
	return minimum;

}
