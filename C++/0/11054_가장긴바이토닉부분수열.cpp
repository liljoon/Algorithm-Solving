#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> v;
vector<vector<vector<int>>> cache;

int solve(int idx, int last_idx, int state)
{
	if (idx >= n)
	{
		return 0;
	}
	int last;
	if (last_idx != -1) {
		last = v[last_idx];
		if (cache[idx][last_idx][state] != -1)
		{
			return cache[idx][last_idx][state];
		}
	}
	else {
		last = -987654321;
	}
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	int mx = 0;
	if (state == 0)
	{
		if (v[idx] > last)
		{
			a = solve(idx + 1, idx, 0) + 1; //증가 포함
		}
		b = solve(idx + 1, last_idx, 0);//증가 미포함
		if (v[idx] < last)
		{
			c = solve(idx + 1, idx, 1) + 1; //감소 포함
		}
		mx = max(a, b);
		mx = max(mx, c);
	}
	else
	{
		if (last > v[idx])
		{
			d = solve(idx + 1, idx, 1) + 1;
		}
		e = solve(idx + 1, last_idx, 1);
	}
	mx = max(mx, d);
	mx = max(mx, e);
	if (last_idx != -1)
	{
		cache[idx][last_idx][state] = mx;
	}
	return mx;
}


int main()
{
	cin >> n;
	cache = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(2, -1)));
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	cout << solve(0, -1, 0) << endl;

}