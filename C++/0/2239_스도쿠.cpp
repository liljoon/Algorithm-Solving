#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> map(9, vector<int>(9, 0));
bool fin = 0;
int check_updown(int y, int x)
{
    for (int i = 0; i < 9; i++)
    {
        if (map[i][x] == map[y][x] && i != y)
        {
            return 0;
        }
    }
    return 1;
}

int check_leftright(int y, int x)
{
    for (int i = 0; i < 9; i++)
    {
        if (map[y][i] == map[y][x] && i != x)
        {
            return 0;
        }
    }
    return 1;
}

int check_33(int y, int x)
{
    int start_x = x / 3 * 3;
    int start_y = y / 3 * 3;
    for (int i = start_y; i < start_y + 3; i++)
    {
        for (int j = start_x; j < start_x + 3; j++)
        {
            if (y != i && x != j && map[i][j] == map[y][x])
                return 0;
        }
    }
    return 1;
}

void solve(int y, int x)
{
    if (fin)
        return;
    if (y >= 9)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << map[i][j];
            }
            cout << endl;
        }
        fin = 1;
        return;
    }
    if (x >= 9)
    {
        solve(y + 1, 0);
        return;
    }
    if (map[y][x] != 0)
    {
        solve(y, x + 1);
        return;
    }
    for (int i = 1; i <= 9; i++)
    {
        map[y][x] = i;
        if (check_leftright(y, x) && check_updown(y, x) && check_33(y, x))
        {
            solve(y, x + 1);
        }
        map[y][x] = 0;
    }
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            char c;
            cin >> c;
            map[i][j] = c - '0';
        }
    }
    solve(0, 0);
}