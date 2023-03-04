#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int day = 1;
	int n, k, a, b;
	cin >> n >> k >> a >> b;
	vector<int> v(n, k);
	while (1)
	{

		sort(v.begin(), v.end());
		for (int i = 0; i < a; i++)
		{
			v[i] += b;
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < n; i++)
			v[i]--;
		if (v[0] == 0)
			break;
		day++;
	}
	cout << day << endl;
}
