#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

struct node
{
    int y, x, cnt, broken;
    node(int _y, int _x, int _cnt, int _broken) : y(_y), x(_x), cnt(_cnt), broken(_broken) {}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> map(n, vector<int>(m));
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(k + 1, false)));
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            map[i][j] = s[j] - '0';
        }
    }
    queue<node> que;
    que.push(node(0, 0, 1, 0));
    visited[0][0][0] = true;

    while (!que.empty())
    {
        int y = que.front().y;
        int x = que.front().x;
        int cnt = que.front().cnt;
        int broken = que.front().broken;
        que.pop();

        if (y == n - 1 && x == m - 1)
        {
            cout << cnt << endl;
            return 0;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            {
                continue;
            }

            if (map[ny][nx])
            {
                if (broken < k && !visited[ny][nx][broken + 1]) //중요
                {
                    visited[ny][nx][broken + 1] = true;
                    que.push(node(ny, nx, cnt + 1, broken + 1));
                }
            }
            else
            {
                if (!visited[ny][nx][broken])
                {
                    visited[ny][nx][broken] = true;
                    que.push(node(ny, nx, cnt + 1, broken));
                }
            }
        }
    }
    cout << -1 << endl;
}