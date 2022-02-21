#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());
    int sum = 0;
    int start = v[0].first, end = v[0].second;
    for (int i = 1; i < n; i++)
    {
        if (v[i].first <= end)
        {
            end = max(end, v[i].second);
        }
        else
        {
            sum += end - start;
            start = v[i].first;
            end = v[i].second;
        }
    }
    sum += end - start;
    cout << sum << endl;
}