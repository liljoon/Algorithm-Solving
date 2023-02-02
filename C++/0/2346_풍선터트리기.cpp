#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	short n;
	cin >> n;
	deque<short> dq;
	vector<short> v(n);

	v.reserve(n);
	for (short i = 0; i < n; i++)
	{
		dq.push_back(i + 1);
		cin >> v[i];
	}
	for (short i = 0; i < n; i++)
	{
		short t = dq.front();
		cout << t << " ";
		dq.pop_front();
		if (v[t - 1] > 0)
		{
			for (short j = 0; j < v[t - 1] - 1; j++)
			{
				short t = dq.front();
				dq.pop_front();
				dq.push_back(t);
			}
		}
		else
		{
			for (short j = 0; j < -v[t - 1]; j++)
			{
				short t = dq.back();
				dq.pop_back();
				dq.push_front(t);
			}
		}
	}
}
