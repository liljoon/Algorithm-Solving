#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int cache[510][510];

int dfs(int i, int j, vector<vector<int>> &map, int before)
{
	if (i >= n || i < 0 || j >= n || j < 0)
		return 0;
	if (before >= map[i][j])
		return 0;
	if (cache[i][j] != 0)
		return cache[i][j];
	int a = dfs(i + 1, j, map, map[i][j]);
	int b = dfs(i - 1, j, map, map[i][j]);
	int c = dfs(i, j + 1, map, map[i][j]);
	int d = dfs(i, j - 1, map, map[i][j]);
	cache[i][j] = max(a, max(b, max(c, d))) + 1;
	return cache[i][j];
}

int main()
{
	int ans = -1;
	cin >> n;
	vector<vector<int>> map(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int dist = dfs(i, j, map, -1);
			if (dist > ans)
				ans = dist;
		}
	}
	cout << ans << endl;
}
