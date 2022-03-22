#include <iostream>
#include <vector>
using namespace std;

int weight;

int chu_n, ball_n;
vector<int> chu_v;
vector<vector<int>> dp;
bool solve(int idx, int gap)
{
    if (abs(gap) == weight)
    {
        return true;
    }
    if (idx >= chu_n)
    {
        return false;
    }
    if (dp[idx][abs(gap)] != -1)
    {
        return dp[idx][abs(gap)];
    }
    int a = solve(idx + 1, gap + chu_v[idx]);
    int b = solve(idx + 1, gap - chu_v[idx]);
    int c = solve(idx + 1, gap);
    if (!a && !b && !c)
    {
        dp[idx][abs(gap)] = false;
        return false;
    }
    else
    {
        dp[idx][abs(gap)] = true;
        return true;
    }
}

int main()
{
    cin >> chu_n;
    for (int i = 0; i < chu_n; i++)
    {
        int a;
        cin >> a;
        chu_v.push_back(a);
    }
    cin >> ball_n;
    for (int i = 0; i < ball_n; i++)
    {
        dp = vector<vector<int>>(chu_n, vector<int>(15001, -1));
        cin >> weight;
        if (solve(0, 0))
        {
            cout << "Y";
        }
        else
        {
            cout << "N";
        }
        if (i != ball_n - 1)
        {
            cout << " ";
        }
    }
}