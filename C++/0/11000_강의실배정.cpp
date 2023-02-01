#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.first != p2.first)
		return p1.first < p2.first;
	return p1.second < p2.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	priority_queue<int, vector<int>, greater<int>> pque;
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v[i].first = a;
		v[i].second = b;
	}
	sort(v.begin(), v.end(), compare);
	pque.push(v[0].second);
	for (int i = 1; i < n; i++)
	{
		int t = pque.top();
		if (t > v[i].first)
			pque.push(v[i].second);
		else
		{
			pque.pop();
			pque.push(v[i].second);
		}
	}
	cout << pque.size() << '\n';
}
