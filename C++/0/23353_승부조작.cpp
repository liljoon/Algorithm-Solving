#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> map;
int n;

int dp[4][2001][2001][2];

int right(int y, int x, int fake)
{
	int ret;
	if (x >= n)
		ret = 0;
	else if (dp[0][y][x][fake] != 0)
		return (dp[0][y][x][fake]);
	else if (map[y][x] == 0)
		ret = 0;
	else if (map[y][x] == 1)
		ret = (1 + right(y, x + 1, fake));
	else if (map[y][x] == 2)
	{
		if (fake == 1)
			ret = 1 + right(y, x + 1, 0);
		else
			ret = 0;
	}
	dp[0][y][x][fake] = ret;
	return ret;
}

int down(int y, int x, int fake)
{
	int ret;
	if (y >= n)
		ret = 0;
	else if (dp[1][y][x][fake] != 0)
		return (dp[1][y][x][fake]);
	else if (map[y][x] == 0)
		ret = 0;
	else if (map[y][x] == 1)
		ret = (1 + down(y + 1, x, fake));
	else if (map[y][x] == 2)
	{
		if (fake == 1)
			ret = 1 + down(y + 1, x, 0);
		else
			ret = 0;
	}
	dp[1][y][x][fake] = ret;
	return ret;
}

int cross(int y, int x, int fake)
{
	int ret;
	if (x >= n || y >= n)
		ret = 0;
	else if (dp[2][y][x][fake] != 0)
		return (dp[2][y][x][fake]);
	else if (map[y][x] == 0)
		ret = 0;
	else if (map[y][x] == 1)
		ret = (1 + cross(y + 1, x + 1, fake));
	else if (map[y][x] == 2)
	{
		if (fake == 1)
			ret = 1 + cross(y + 1, x + 1, 0);
		else
			ret = 0;
	}
	dp[2][y][x][fake] = ret;
	return ret;
}

int cross2(int y, int x, int fake)
{
	int ret;
	if (x >= n || y < 0)
		ret = 0;
	else if (dp[3][y][x][fake] != 0)
		return (dp[3][y][x][fake]);
	else if (map[y][x] == 0)
		ret = 0;
	else if (map[y][x] == 1)
		ret = (1 + cross2(y - 1, x + 1, fake));
	else if (map[y][x] == 2)
	{
		if (fake == 1)
			ret = 1 + cross2(y - 1, x + 1, 0);
		else
			ret = 0;
	}
	dp[3][y][x][fake] = ret;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	map = vector<vector<int>>(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ans = max(ans, right(i, j, 1));
			ans = max(ans, down(i, j, 1));
			ans = max(ans, cross(i, j, 1));
			ans = max(ans, cross2(i, j, 1));
		}
	}
	cout << ans << "\n";
}
