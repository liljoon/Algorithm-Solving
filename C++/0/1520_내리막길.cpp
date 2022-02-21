#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int M, N;
vector<vector<int>> map;
vector<vector<long long>> cache;

long long solve(int y, int x)
{
    if (y == M - 1 && x == N - 1)
    {
        return 1;
    }
    if (cache[y][x] != -1)
    {
        return cache[y][x];
    }
    long long sum = 0;
    if (x + 1 < N && map[y][x + 1] < map[y][x]) //우
    {
        sum += solve(y, x + 1);
    }
    if (y + 1 < M && map[y + 1][x] < map[y][x]) //하
    {
        sum += solve(y + 1, x);
    }
    if (x - 1 >= 0 && map[y][x - 1] < map[y][x]) //좌
    {
        sum += solve(y, x - 1);
    }
    if (y - 1 >= 0 && map[y - 1][x] < map[y][x]) //상
    {
        sum += solve(y - 1, x);
    }
    cache[y][x] = sum;
    return sum;
}

int main()
{
    cin >> M >> N;
    map = vector<vector<int>>(M, vector<int>(N, -1));
    cache = vector<vector<long long>>(M, vector<long long>(N, -1));

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }
    cout << solve(0, 0) << endl;
}