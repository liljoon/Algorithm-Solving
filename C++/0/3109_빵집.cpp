#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int r, c;
vector<vector<char>> map;
int sum = 0;
bool found = false;

void dfs(int y, int x)
{
    if (y < 0 || y >= r)
    {
        return;
    }
    if (map[y][x] == 'x')
    {
        return;
    }
    if (found) //길을 하나 뚫었으면 다른 길은 전부 안가도록 스킵
    {
        return;
    }
    if (x == c - 1)
    {
        found = true;
        map[y][x] = 'x';
        sum++;
        return;
    }
    map[y][x] = 'x';
    dfs(y - 1, x + 1);
    dfs(y, x + 1);
    dfs(y + 1, x + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> r >> c;
    map = vector<vector<char>>(r, vector<char>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < r; i++)
    {
        dfs(i, 0);
        found = false;
    }
    cout << sum << endl;
}