#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string a, b;
int dp[2000][2000];

int main()
{
    cin >> a;
    cin >> b;
    for (int i = 0; i <= a.length(); i++)
    {
        for (int j = 0; j <= b.length(); j++)
        {
            if (a[i] == b[j])
            {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
            }
            dp[i][j + 1] = max(dp[i][j + 1], dp[i][j]);
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        }
    }
    int x = b.length();
    int y = a.length();
    string s;
    while (dp[y][x] != 0)
    {
        if (dp[y - 1][x] == dp[y][x])
            y--;
        else if (dp[y][x - 1] == dp[y][x])
            x--;
        else
        {
            s.push_back(a[y - 1]);
            x--;
            y--;
        }
    }
    cout << dp[a.length()][b.length()] << endl;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        cout << s[i];
    }
}