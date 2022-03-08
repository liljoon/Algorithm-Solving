#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int r, c;
vector<vector<char>> map;
vector<int> visited(26,0);
int rst = 0;

void dfs(int y, int x,int cnt)
{
	if (y < 0 || y >= r || x < 0 || x >= c) 
	{
		return;
	}
	if (visited[(int)map[y][x] - (int)'A'])
	{
		return;
	}
	rst = max(rst, cnt);
	visited[(int)map[y][x] - (int)'A'] = true;
	dfs(y + 1, x,cnt+1);
	dfs(y - 1, x, cnt+1);
	dfs(y, x + 1,cnt +1);
	dfs(y, x - 1,cnt+1);
	visited[(int)map[y][x] - (int)'A'] = false;
}

int main()
{
	cin >> r >> c;
	map = vector<vector<char>>(r, vector<char>(c));
	for (int i = 0; i < r; i++) 
	{
		for (int j = 0; j < c; j++)
		{
			cin >> map[i][j];
		}
	}
	dfs(0, 0, 1);
	cout << rst << endl;
}
