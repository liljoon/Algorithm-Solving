#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int map[60][60];
int n, m;

struct node
{
	int y, x, dist;
};

int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};

node bfs(int st_y, int st_x)
{
	vector<vector<int>> visited(60, vector<int>(60, -1));
	queue<node> que;

	que.push({st_y, st_x, 0});
	while (!que.empty())
	{
		int y = que.front().y;
		int x = que.front().x;
		int dist = que.front().dist;
		que.pop();
		if (y < 0 || y >= n || x < 0 || x >= m)
			continue;
		if (map[y][x] == 0)
			continue;
		if (visited[y][x] != -1)
			continue;
		visited[y][x] = dist;
		for (int i = 0; i < 4; i++)
			que.push({y + dy[i], x + dx[i], dist + 1});
	}
	node ret = {0,
				0,
				visited[0][0]};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (ret.dist < visited[i][j])
			{
				ret = {i, j, visited[i][j]};
			}
			if (ret.dist == visited[i][j] && map[i][j] > map[ret.y][ret.x])
			{
				ret = {i, j, visited[i][j]};
			}
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	}
	vector<pair<int, int>> ans;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			node ret = bfs(i, j);
			node ret2 = bfs(ret.y, ret.x);
			ans.push_back(make_pair(ret2.dist, map[ret.y][ret.x] + map[ret2.y][ret2.x]));
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans[ans.size() - 1].second << "\n";
}
