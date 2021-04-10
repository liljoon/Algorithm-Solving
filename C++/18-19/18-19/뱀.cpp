#include<iostream>
#include<deque>
#include<queue>
#include<list>
using namespace std;

void next(int& x, int& y);
int n;
enum direction{ up, right_, down, left_ };
int dir = right_;
int k;
list<pair<int,int>> applel;
int l;
queue<pair<int,int>> turnq;
int time = 0;
deque<pair<int, int>> snake;
bool checksnake(int x, int y);
bool checkapple(int x, int y);

int main() {
	cin >> n;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int temp, temp1;
		cin >> temp >> temp1;
		applel.push_back(pair<int, int>(temp - 1, temp1 - 1));
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		int temp1;
		cin >> temp1;
		char temp;
		cin >> temp;
		// 1: 시계방향 //-1: 반시계방향
		if (temp == 'D') {
			turnq.push(pair<int, int>(temp1, 1));
		}
		else {
			turnq.push(pair<int, int>(temp1, -1));
		}
	}

	snake.push_front(pair<int,int>(0,0));
	while (1) {
		int x = snake.front().first;
		int y = snake.front().second;
		next(x, y);

		if (x >= n || x < 0 || y < 0 || y >= n) {
			time++;
			break;
		}
		if (checksnake(x, y)) {
			time++;
			break;
		}
		time++;
		snake.push_front(pair<int, int>(x,y));
		if (checkapple(x, y) == false) {
			snake.pop_back();
		}

	}
	cout << time << endl;

}

bool checkapple(int x, int y) {
	if (applel.empty()) return false;
	list<pair<int,int>>::iterator it = applel.begin();
	for (int i = 0; i < k; i++) {
		int tempx, tempy;
		tempx = it->first;
		tempy = it->second;
		
		if (tempx == x && tempy == y) {
			applel.erase(it);
			k--;
			return true;
		}
		it++;
	}
	return false;
}

bool checksnake(int x, int y) {
	int length = snake.size();
	bool ret = false;
	for (int i = 0; i < length; i++) {
		if (snake.back().first == x && snake.back().second == y) {
			ret = true;
		}
		int tempx, tempy;
		tempx = snake.back().first;
		tempy = snake.back().second;
		//cout << tempx << " " << tempy << endl;
		snake.pop_back();
		snake.push_front(pair<int, int>(tempx, tempy));
	}
	return ret;
}

void next(int& x, int& y) {
	if (turnq.empty()) {

	}
	else if (time == turnq.front().first) {
		if (turnq.front().second == 1) {
			dir = (dir + 1) % 4;
		}
		else {
			dir = (dir + 3) % 4;
		}
		turnq.pop();
	}

	if (dir == up) {
		x--;
	}
	else if (dir == right_) {
		y++;
	}
	else if (dir == down) {
		x++;
	}
	else if (dir == left_) {
		y--;
	}
}