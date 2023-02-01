#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int ret = 987654321;
vector<vector<int>> map;
int n;

void cal(int idx, vector<int> team1, vector<int> team2)
{
	if (n / 2 == team1.size() && n / 2 == team2.size())
	{
		int a = 0;
		int b = 0;
		for (int i = 0; i < n / 2; i++)
		{
			for (int j = i + 1; j < n / 2; j++)
			{
				a += (map[team1[i]][team1[j]] + map[team1[j]][team1[i]]);
				b += (map[team2[i]][team2[j]] + map[team2[j]][team2[i]]);
				ret = min(ret, abs(a - b));
			}
		}
	}
	if (idx >= n)
	{
		return;
	}
	team1.push_back(idx);
	cal(idx + 1, team1, team2);
	team1.pop_back();
	team2.push_back(idx);
	cal(idx + 1, team1, team2);
}

int main()
{
	cin >> n;
	map = vector<vector<int>>(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	cal(0, vector<int>(), vector<int>());
	cout << ret << endl;
	return 0;
}
