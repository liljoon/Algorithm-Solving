#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		v[i] = make_pair(a, b);
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < n; i++)
		cout << v[i].first << " " << v[i].second << '\n';
}
