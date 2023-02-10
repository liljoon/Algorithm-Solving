#include <vector>
#include <iostream>
#include <queue>
using namespace std;

struct s
{
    int y;
    int x;
    int cnt;
};

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    queue<s> que;
    int n = maps.size();
    int m = maps[0].size();
    que.push({0, 0, 0});
    vector<vector<int>> visited(n, vector<int>(m, 0));
    while (!que.empty())
    {
        int y = que.front().y;
        int x = que.front().x;
        int cnt = que.front().cnt;
        // cout<<y<<" "<< x<<endl;
        que.pop();

        if (y >= n || x >= m || x < 0 || y < 0)
            continue;
        if (maps[y][x] == 0)
            continue;
        if (y == n - 1 && x == m - 1)
        {
            answer = cnt;
            break;
        }
        if (visited[y][x])
            continue;
        visited[y][x] = 1;
        que.push({y + 1, x, cnt + 1});
        que.push({y, x + 1, cnt + 1});
        que.push({y - 1, x, cnt + 1});
        que.push({y, x - 1, cnt + 1});
    }
    if (answer == 0)
        return -1;
    return answer + 1;
}