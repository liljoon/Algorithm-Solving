#include <iostream>
#include <vector>
using namespace std;

vector<int> v(10001, 0);

void solve(int n)
{
    if (n > 10000)
    {
        return;
    }
    int next = n;
    while (n > 0)
    {
        next += n % 10;
        n /= 10;
    }
    if (next < 10001)
    {
        v[next] = 1;
        solve(next);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 1; i < 10001; i++)
    {
        solve(i);
    }
    for (int i = 1; i < 10001; i++)
    {
        if (v[i] == 0)
        {
            cout << i << "\n";
        }
    }
}