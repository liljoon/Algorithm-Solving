#include<iostream>
#include<queue>
using namespace std;

int main() {
	queue<int> card;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		card.push(i + 1);
	}
	while (card.size() != 1) {
		card.pop();
		int temp =card.front();
		card.pop();
		card.push(temp);
	}
	cout << card.front() << endl;
}