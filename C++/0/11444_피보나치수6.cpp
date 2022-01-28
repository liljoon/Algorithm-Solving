#include <iostream>
#include <map>
using namespace std;

map<long long, long long> m;

long long solve(long long n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1 || n == 2)
    {
        return 1;
    }
    if (m.find(n) != m.end())
    {
        return m[n];
    }
    if (n % 2 == 0)
    {
        long long a = solve(n / 2);
        long long b = solve(n / 2 - 1);
        long long ret = (a * a + 2 * a * b) % 1000000007;
        m.insert({n, ret});
        return ret;
    }
    else
    {
        long long a = solve(n / 2 + 1);
        long long b = solve(n / 2);
        int ret = (a * a + b * b) % 1000000007;
        m.insert({n, ret});
        return ret;
    }
}

int main()
{
    long long n;

    cin >> n;
    cout << solve(n) << endl;
}