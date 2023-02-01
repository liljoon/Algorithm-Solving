#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int h, w, n;
		cin >> h >> w >> n;
		int hosu = (n - 1) / h + 1;
		int floor = (n - 1) % h + 1;
		if (hosu < 10)
			floor *= 10;
		cout << floor << hosu << endl;
	}
}
