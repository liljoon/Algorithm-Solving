#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> dp;
vector<int> trace;

int solve(int num)
{
    if (num == 1)
        return 0;
    if (dp[num] != -1)
        return dp[num];
    int a = solve(num - 1) + 1;
    int b = 987654321;
    int c = 987654321;
    if (num % 2 == 0)
        b = solve(num / 2) + 1;
    if (num % 3 == 0)
        c = solve(num / 3) + 1;
    dp[num] = min(a, min(b, c));
    if (dp[num] == a)
        trace[num] = num - 1;
    else if (dp[num] == b)
        trace[num] = num / 2;
    else
        trace[num] = num / 3;
    return dp[num];
}

int main()
{
    cin >> n;
    dp.assign(n + 1, -1);
    trace.assign(n + 1, -1);
    cout << solve(n) << endl;
    int i = n;

    vector<int> v;
    while (trace[i] != -1)
    {
        cout << i << " ";
        i = trace[i];
    }
    cout << 1;
}