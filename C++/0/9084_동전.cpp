#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int ti = 0; ti < t; ti++)
    {
        int n;
        cin >> n;
        vector<int> coin(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> coin[i];
        }
        int price;
        cin >> price;
        vector<int> dp(price + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= price; j++)
            {
                if ((j - coin[i]) > 0)
                {
                    dp[j] += dp[j - coin[i]];
                }
            }
        }
        cout << dp[price] << endl;
    }
}