#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int tofind;
        cin >> tofind;
        int start = lower_bound(v.begin(), v.end(), tofind) - v.begin();
        int end = upper_bound(v.begin(), v.end(), tofind) - v.begin();
        cout << end - start << " ";
    }
}