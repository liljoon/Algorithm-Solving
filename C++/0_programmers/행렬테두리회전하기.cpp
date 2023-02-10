#include <string>
#include <vector>

using namespace std;

vector<vector<int>> map;

void swap(int &a, int &b)
{
    int t;

    t = a;
    a = b;
    b = t;
}

int exec_query(vector<int> query)
{
    int y, x;
    int ret = 987654321;
    for (auto &i : query)
        i--;
    y = query[0];
    x = query[1];
    int dx = 1;
    int dy = 0;
    int temp = 987654321;
    while (1)
    {
        swap(temp, map[y][x]);
        ret = min(temp, ret);
        if (y == query[0] && x == query[3])
        {
            dx = 0;
            dy = 1;
        }
        else if (y == query[0] && x == query[1])
        {
            dx = 1;
            dy = 0;
        }
        else if (y == query[2] && x == query[3])
        {
            dx = -1;
            dy = 0;
        }
        else if (y == query[2] && x == query[1])
        {
            dx = 0;
            dy = -1;
        }
        x += dx;
        y += dy;
        if (y == query[0] && x == query[1])
        {
            swap(temp, map[y][x]);
            break;
        }
    }
    return ret;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    vector<int> answer;
    int idx = 1;
    map = vector(rows, vector<int>(columns));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            map[i][j] = idx;
            idx++;
        }
    }
    for (auto query : queries)
        answer.push_back(exec_query(query));

    return answer;
}