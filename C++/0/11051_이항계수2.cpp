#include <iostream>
#include <vector>
using namespace std;

vector<vector<long long>> cache;

long long solve(long long n, long long k)
{
    if (n == k || k == 0)
    {
        return 1;
    }
    if (cache[n][k] != -1)
    {
        return cache[n][k];
    }
    cache[n][k] = solve(n - 1, k - 1) % 1000000007 + solve(n - 1, k) % 1000000007;
    return cache[n][k];
}

int main()
{
    long long n, k;
    cin >> n >> k;
    cache = vector<vector<long long>>(n + 1, vector<long long>(k + 1, -1));
    cout << solve(n, k) % 1000000007 << endl;
}