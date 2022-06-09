#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long k, n;
    cin >> k >> n;
    vector<long long> v(n);
    long long start = 1;
    long long end;
    for (int i = 0; i < k; i++)
    {
        cin >> v[i];
        end = max(v[i], end);
    }
    end++;
    while (start + 1 < end)
    {
        long long cnt = 0;
        for (int i = 0; i < k; i++)
            cnt += v[i] / ((end + start) / 2);
        if (cnt >= n)
        {
            start = (end + start) / 2;
        }
        else
        {
            end = (end + start) / 2;
        }
    }
    cout << start << endl;
}