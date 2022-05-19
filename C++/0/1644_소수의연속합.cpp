#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<int> is_prime(n + 1, 1);
    vector<int> prime;
    for(int i=2; i <= n; i++)
    {
        if (!is_prime[i])
            continue;
        prime.push_back(i);
        for (int j = i; j <= n; j += i)
            is_prime[j] = 0;
    }
    int start = 0;
    int end = 0;
    int sum = prime[0];
    int cnt = 0;
    while (end < prime.size())
    {
        if (sum > n)
        {
            sum -= prime[start];
            start++;
        }
        else if (sum < n)
        {
            end++;
            if (end < prime.size())
                sum += prime[end];
        }
        else
        {
            cnt++;
            sum -= prime[start];
            start++;
        }
    }
    cout << cnt << endl;
}