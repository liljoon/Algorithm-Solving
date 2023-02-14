#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<int>> map;
vector<int> island(1);

int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
vector<vector<int>> visited;
vector<vector<int>> visited2;

int bfs(int y, int x, int input)
{
    queue<pair<int, int>> que;

    int ret = 0;
    que.push(make_pair(y, x));
    while (!que.empty())
    {
        int temp_y = que.front().first;
        int temp_x = que.front().second;
        que.pop();
        if (temp_y < 0 || temp_y >= n || temp_x < 0 || temp_x >= m)
            continue;
        if (map[temp_y][temp_x] == -1)
            continue;
        if (visited[temp_y][temp_x])
            continue;
        visited[temp_y][temp_x] = 1;
        map[temp_y][temp_x] = input;
        ret++;
        for (int i = 0; i < 4; i++)
            que.push(make_pair(temp_y + dy[i], temp_x + dx[i]));
    }
    return ret;
}

int bfs2(int y, int x, int input)
{
    queue<pair<int, int>> que;

    int ret = 0;
    que.push(make_pair(y, x));
    while (!que.empty())
    {
        int temp_y = que.front().first;
        int temp_x = que.front().second;
        que.pop();
        if (temp_y < 0 || temp_y >= n || temp_x < 0 || temp_x >= m)
            continue;
        if (map[temp_y][temp_x] == -1)
            continue;
        if (visited2[temp_y][temp_x])
            continue;
        visited2[temp_y][temp_x] = 1;
        map[temp_y][temp_x] = input;
        ret++;
        for (int i = 0; i < 4; i++)
            que.push(make_pair(temp_y + dy[i], temp_x + dx[i]));
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    map = vector<vector<int>>(n, vector<int>(m));
    vector<vector<int>> ans(n, vector<int>(m, 0));
    visited = vector<vector<int>>(n, vector<int>(m, 0));
    visited2 = vector<vector<int>>(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            map[i][j] = c - '0';
            if (map[i][j] == 1)
                map[i][j] = -1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0)
            {
                int temp = bfs(i, j, 0);
                island.push_back(temp);
                bfs2(i, j, island.size() - 1);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vector<int> did;
            if (map[i][j] == -1)
            {
                for (int k = 0; k < 4; k++)
                {
                    if (i + dy[k] >= 0 && i + dy[k] < n && j + dx[k] >= 0 && j + dx[k] < m && map[i + dy[k]][j + dx[k]] != -1)
                    {
                        int flag = 0;
                        for (int l = 0; l < did.size(); l++)
                        {
                            if (map[i + dy[k]][j + dx[k]] == did[l])
                                flag = 1;
                        }
                        if (!flag)
                        {
                            ans[i][j] += island[map[i + dy[k]][j + dx[k]]];
                            did.push_back(map[i + dy[k]][j + dx[k]]);
                        }
                    }
                }
                ans[i][j]++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j] % 10;
        }
        cout << "\n";
    }
}