#include <iostream>
#include <vector>
using namespace std;
#define div 1000000000

//나왔던 수 체크할 때 연속되기 때문에 처음과 끝만 기록하는게 핵심 -> chk_start, chk_end

int dp[101][10][10][10];
int n;
int solve(int idx, int before, int chk_start, int chk_end)
{
    if (idx == 0)
    {
        int sum = 0;
        for (int i = 1; i < 10; i++)
        {
            sum = (sum + solve(idx + 1, i, i, i)) % div;
        }
        return sum;
    }
    if (idx >= n)
    {
        if (chk_start == 0 && chk_end == 9)
            return 1;
        else
            return 0;
    }
    if (dp[idx][before][chk_start][chk_end] != -1)
    {
        return dp[idx][before][chk_start][chk_end];
    }
    int sum = 0;
    int a = 0;
    if (before + 1 < 10)
    {
        a = solve(idx + 1, before + 1, chk_start, max(before + 1, chk_end));
    }
    int b = 0;
    if (before - 1 >= 0)
    {
        b = solve(idx + 1, before - 1, min(before - 1, chk_start), chk_end);
    }
    sum = (sum + a) % div;
    sum = (sum + b) % div;
    dp[idx][before][chk_start][chk_end] = sum;
    return sum;
}

int main()
{
    cin >> n;
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                for (int l = 0; l < 10; l++)
                {
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }
    cout << solve(0, 0, 0, 0) << endl;
}