#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;

void solve(vector<int> v, vector<int> used)
{
	if (v.size() == m)
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << "\n";
		return;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (used[i])
				continue;
			used[i] = 1;
			v.push_back(i);
			solve(v, used);
			v.pop_back();
			used[i] = 0;
		}
	}
}

int main()
{
	cin >> n >> m;
	vector<int> used(n + 1, 0);
	solve(vector<int>(), used);
}
