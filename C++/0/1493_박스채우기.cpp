#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> v;
int n;
bool possible = true;

long long solve(int length, int width, int height)
{
    if (!possible)
    {
        return 0;
    }
    if (length == 0 || width == 0 || height == 0)
    {
        return 0;
    }
    int k = min({length, width, height});
    k = log2(k);
    k = min(k, n - 1);
    for (int i = k; i >= 0; i--)
    {
        long long p = pow(2, i);
        if (v[i] > 0 && p <= length && p <= width && p <= height)
        {
            v[i]--;
            return solve(length - p, width, height) + solve(p, width - p, height) + solve(p, p, height - p) + 1;
        }
    }
    possible = false;
    return -99999;
}

int main()
{
    int length, width, height;
    cin >> length >> width >> height;

    cin >> n;
    v = vector<int>(n, 0);
    long long all = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a] = b;
    }
    long long rst = solve(length, width, height);
    if (possible)
    {
        cout << rst << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}