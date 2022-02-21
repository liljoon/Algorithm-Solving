#include <iostream>
using namespace std;

long long a, b;
int c;

int solve(int n)
{
    if (n == 1)
    {
        return a % c;
    }
    if (n % 2 == 1)
    {
        return solve(n - 1) * a % c;
    }
    long long temp = solve(n / 2);
    return temp * temp % c;
}

int main()
{
    cin >> a >> b >> c;
    cout << solve(b) << endl;
}