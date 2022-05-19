#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> dp;

int solve(int num)
{
    if (num > n)
        return 987654321;
    if (num == n)
        return 0;
    if (dp[num] != -1)
        return dp[num];
    int a = solve(num + 1) + 1;
    int b = solve(num * 2) + 1;
    int c = solve(num * 3) + 1;
    dp[num] = min(a, min(b, c));
    return dp[num];
}

int main()
{
    cin >> n;
    dp.assign(1000000, -1);
    cout << solve(1) << endl;
}