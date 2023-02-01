#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct st
{
	int y;
	int x;
	int cost;
};

struct compare
{
	bool operator()(st s1, st s2)
	{
		return s1.cost > s2.cost;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> map(n, vector<int>(n));
	vector<vector<int>> answer(n, vector<int>(n, 987654321));
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
			map[i][j] = s[j] - '0';
	}
	priority_queue<st, vector<st>, compare> pque;
	pque.push(st{0, 0, 0});
	while (!pque.empty())
	{
		int y = pque.top().y;
		int x = pque.top().x;
		int cost = pque.top().cost;
		pque.pop();
		if (y == n - 1 && x == n - 1)
		{
			cout << cost << endl;
			break;
		}

		if (answer[y][x] < cost)
			continue;
		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n)
				continue;
			int next_cost = cost;
			if (map[next_y][next_x] == 0)
				next_cost += 1;
			if (next_cost < answer[next_y][next_x])
			{
				answer[next_y][next_x] = next_cost;
				pque.push({next_y, next_x, next_cost});
			}
		}
	}
}
