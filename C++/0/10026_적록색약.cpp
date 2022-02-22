#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> map;
vector<vector<bool>> visited;
int n;

void dfs(int y, int x, char beforecolor)
{
    if (y < 0 || y >= n || x < 0 || x >= n)
    {
        return;
    }
    if (visited[y][x])
    {
        return;
    }
    if (map[y][x] != beforecolor)
    {
        return;
    }
    visited[y][x] = true;
    dfs(y - 1, x, map[y][x]);
    dfs(y + 1, x, map[y][x]);
    dfs(y, x - 1, map[y][x]);
    dfs(y, x + 1, map[y][x]);
}

void dfs2(int y, int x, char beforecolor)
{
    if (y < 0 || y >= n || x < 0 || x >= n)
    {
        return;
    }
    if (visited[y][x])
    {
        return;
    }
    if (((map[y][x] == 'R' || map[y][x] == 'G') && beforecolor == 'B') || ((beforecolor == 'R' || beforecolor == 'G') && map[y][x] == 'B'))
    {
        return;
    }
    visited[y][x] = true;
    dfs2(y - 1, x, map[y][x]);
    dfs2(y + 1, x, map[y][x]);
    dfs2(y, x - 1, map[y][x]);
    dfs2(y, x + 1, map[y][x]);
}
int main()
{
    cin >> n;
    map = vector<vector<char>>(n, vector<char>(n));
    visited = vector<vector<bool>>(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                cnt++;
                dfs(i, j, map[i][j]);
            }
        }
    }
    cout << cnt << " ";
    cnt = 0;
    visited = vector<vector<bool>>(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                cnt++;
                dfs2(i, j, map[i][j]);
            }
        }
    }
    cout << cnt << endl;
}