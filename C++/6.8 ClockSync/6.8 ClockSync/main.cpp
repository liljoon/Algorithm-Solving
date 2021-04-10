#include<iostream>
using namespace std;

int clock_switch_size[10] = { 3,4,4,5,5,4,3,5,5,5 };

int clock_switch[10][5] = {
	{ 0,1,2 },
	{ 3,7,9,11 },
	{ 4,10,14,15 },
	{ 0,4,5,6,7 },
	{ 6,7,8,10,12 },
	{ 0,2,14,15 },
	{ 3,14,15 },
	{ 4,5,7,14,15 },
	{ 1,2,3,4,5 },
	{ 3,4,5,9,13 }
};


int clocksync(int clock[16],int n,int count);

int main() {
	int c;
	cin >> c;
	int clock[16];
	for (int ci = 0; ci < c; ci++) {
		for (int i = 0; i < 16; i++) {
			cin >> clock[i];
			clock[i] = clock[i] % 12;
		}
		int a = clocksync(clock, 0, 0);
		if (a == 99999) {
			cout << -1 << endl;
		}
		else {
			cout << a << endl;
		}
		
	}
}

int clocksync(int clock[16], int n, int count)
{
	bool finish = true;
	for (int i = 0; i < 16; i++) {
		if (clock[i] != 0) {
			finish = false;
			break;
		}
	}
	if (finish) {
		return count;
	}
	//base case2: finish;

	if (n == 10) {
		return 99999;
	}
	//base case1 : no answer
	//general case

	int min[4];
	min[0] = clocksync(clock, n + 1, count);//한번도 안누를 때
	for (int j = 0; j < clock_switch_size[n]; j++) {
		clock[clock_switch[n][j]] = (clock[clock_switch[n][j]] + 3) % 12;
	}
	min[1] = clocksync(clock, n + 1, count + 1);
	for (int j = 0; j < clock_switch_size[n]; j++) {
		clock[clock_switch[n][j]] = (clock[clock_switch[n][j]] + 3) % 12;
	}
	min[2] = clocksync(clock, n + 1, count + 2);
	for (int j = 0; j < clock_switch_size[n]; j++) {
		clock[clock_switch[n][j]] = (clock[clock_switch[n][j]] + 3) % 12;
	}
	min[3] = clocksync(clock, n + 1, count + 3);

	//*********************//
	for (int j = 0; j < clock_switch_size[n]; j++) {
		clock[clock_switch[n][j]] = (clock[clock_switch[n][j]] + 3) % 12;
	}//********************************//


	//최소값
	int minimum = min[0];
	for (int i = 1; i < 4; i++) {
		if (min[i] < minimum) {
			minimum = min[i];
		}
	}
	return minimum;
}
