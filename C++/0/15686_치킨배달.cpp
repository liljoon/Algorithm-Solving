#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int>> map;
vector<pair<int, int>> chick;
int n, m;

int dist()
{
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 1)
			{
				int d = 987654321;
				for (int k = 0; k < chick.size(); k++)
				{
					if (chick[k].first == -1)
						continue;
					d = min(d, abs(i - chick[k].first) + abs(j - chick[k].second));
				}
				ret += d;
			}
		}
	}
	return ret;
}

int solve(int idx, int todel)
{
	int ret = 987654321;
	if (todel == 0)
		return dist();
	for (int i = idx + 1; i < chick.size(); i++)
	{
		int t1 = chick[i].first;
		int t2 = chick[i].second;
		chick[i] = make_pair(-1, -1);
		int a = solve(i, todel - 1);
		chick[i] = make_pair(t1, t2);

		ret = min(ret, a);
	}
	return ret;
}

int main()
{
	cin >> n >> m;
	map = vector<vector<int>>(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
				chick.push_back(make_pair(i, j));
		}
	}
	cout << solve(-1, chick.size() - m) << endl;
}
