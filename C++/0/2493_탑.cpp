#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	stack<pair<int, int>> st;
	int n;

	cin >> n;
	vector<int> v(n);
	vector<int> ans(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		while (!st.empty())
		{
			if (st.top().second > v[i])
				break;
			int temp = st.top().first;
			st.pop();
			ans[temp] = i + 1;
		}
		st.push({i, v[i]});
	}
	for (auto i : ans)
		cout << i << " ";
}
