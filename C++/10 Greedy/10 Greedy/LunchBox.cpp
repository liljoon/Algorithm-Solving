#include<iostream>
#include<algorithm>
using namespace std;

struct lunch {
	int cook;
	int eat;
	
};

bool cmp(lunch l, lunch other) {
		if (l.eat <= other.eat) return false;
		else return true;
}

lunch arr[10001];

int main() {
	int c; 
	cin >> c;
	for (int ci = 0; ci < c; ci++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i].cook;
		}
		for (int i = 0; i < n; i++) {
			cin >> arr[i].eat;
		}
		sort(arr, arr + n, cmp);
		/*for (int i = 0; i < n; i++) {
			cout << arr[i].cook <<" " <<arr[i].eat << endl;
		}*/
		int time = 0;
		for (int i = 0; i < n; i++) {
			time += arr[i].cook;
		}
		int eattime = arr[0].eat;
		//cout << eattime;
		for (int i = 1; i < n; i++) {
			eattime -= arr[i].cook;
			eattime = max(eattime, arr[i].eat);
		}
		cout << time +eattime << endl;
	}
	
}