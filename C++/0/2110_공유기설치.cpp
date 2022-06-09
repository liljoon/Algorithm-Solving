#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, c;
    cin >> n >> c;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    long long start = 1, end = v[n - 1] - v[0] + 1;
    while (start + 1 < end)
    {
        long long mid = (start + end) / 2;
        int idx = 0;
        int cnt = 0;
        while (idx != n)
        {
            idx = lower_bound(v.begin(), v.end(), v[idx] + mid) - v.begin();
            cnt++;
        }
        if (cnt < c)
            end = mid;
        else
            start = mid;
    }
    cout << start << endl;
}