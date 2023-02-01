#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m;

void solve(vector<int> v, int before)
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
		for (int i = before + 1; i <= n; i++)
		{
			v.push_back(i);
			solve(v, i);
			v.pop_back();
		}
	}
}

int main()
{
	cin >> n >> m;
	vector<int> used(n + 1, 0);
	solve(vector<int>(), 0);
}
