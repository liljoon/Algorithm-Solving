#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long t, n, m;
    cin >> t >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
    {
        long long in;
        cin >> in;
        if (i != 0)
            a[i] = a[i - 1] + in;
        else
            a[i] = in;
    }
    cin >> m;
    vector<long long> b(m);
    for (long long i = 0; i < m; i++)
    {
        long long in;
        cin >> in;
        if (i != 0)
            b[i] = b[i - 1] + in;
        else
            b[i] = in;
    }
    vector<long long> v;
    for (long long i = -1; i < m - 1; i++)
    {
        for (long long j = i + 1; j < m; j++)
        {
            if (i == -1)
                v.push_back(b[j]);
            else
                v.push_back(b[j] - b[i]);
        }
    }
    long long cnt = 0;
    sort(v.begin(), v.end());
    for (long long i = -1; i < n - 1; i++)
    {
        for (long long j = i + 1; j < n; j++)
        {
            long long temp;
            if (i == -1)
                temp = a[j];
            else
                temp = (a[j] - a[i]);
            long long find = lower_bound(v.begin(), v.end(), t - temp) - v.begin();
            long long find2 = upper_bound(v.begin(), v.end(), t - temp) - v.begin();
            if (v[find] + temp == t)
            {
                cnt += find2 - find;
            }
        }
    }
    cout << cnt << endl;
}