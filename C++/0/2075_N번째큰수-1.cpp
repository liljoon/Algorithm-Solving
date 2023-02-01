#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	priority_queue<int, vector<int>, greater<int>> pque;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp;

			cin >> temp;
			pque.push(temp);
		}
		for (int j = 0; j < n - 1; j++)
			pque.pop();
	}
	cout << pque.top() << endl;
}
