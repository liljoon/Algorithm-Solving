#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<vector<int>> map;

struct sh
{
    int y;
    int x;
    int size;
    int eat_cnt;
};

struct st
{
    int y;
    int x;
    int time;
};

sh shark;

int check_can_eat()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] != 0 && map[i][j] < shark.size)
                return 1;
        }
    }
    return 0;
}

int dy[] = {-1, 0, 0, 1};
int dx[] = {0, -1, 1, 0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int ret = 0;
    cin >> n;
    map = vector<vector<int>>(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 9)
            {
                shark = {i, j, 2, 0};
                map[i][j] = 0;
            }
        }
    }
    while (check_can_eat())
    {
        queue<st> que;
        que.push({shark.y, shark.x, 0});
        int visited[30][30] = {0};
        int shortest = 987654321;
        vector<pair<int, int>> togo;
        while (!que.empty())
        {
            int y = que.front().y;
            int x = que.front().x;
            int time = que.front().time;
            que.pop();

            if (y >= n || y < 0 || x < 0 || x >= n)
                continue;
            if (map[y][x] > shark.size)
                continue;
            if (visited[y][x])
                continue;
            visited[y][x] = 1;
            if (shortest < time)
                break;
            if (map[y][x] != 0 && map[y][x] < shark.size)
            {
                togo.push_back(make_pair(y, x));
                shortest = time;
                continue;
            }
            for (int i = 0; i < 4; i++)
                que.push({y + dy[i], x + dx[i], time + 1});
        }
        if (togo.size() == 0)
            break;
        int togo_y = togo[0].first;
        int togo_x = togo[0].second;
        for (int i = 0; i < togo.size(); i++)
        {
            if (togo_y > togo[i].first)
            {
                togo_y = togo[i].first;
                togo_x = togo[i].second;
            }
            else if (togo_y == togo[i].first && togo_x > togo[i].second)
            {
                togo_y = togo[i].first;
                togo_x = togo[i].second;
            }
        }
        map[togo_y][togo_x] = 0;
        shark.eat_cnt++;
        if (shark.eat_cnt == shark.size)
        {
            shark.eat_cnt = 0;
            shark.size++;
        }
        shark.y = togo_y;
        shark.x = togo_x;
        ret += shortest;
    }
    cout << ret << endl;
}