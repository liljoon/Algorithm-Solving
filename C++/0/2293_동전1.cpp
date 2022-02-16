#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int n, k;
vector<int> cache;

int main()
{
    cin >> n >> k;
    v = vector<int>(n, 0);
    cache = vector<int>(k + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cache[0] = 1;

    // https://danidani-de.tistory.com/5
    for (int i = 0; i < n; i++)
    {
        for (int j = v[i]; j <= k; j++)
        {
            cache[j] += cache[j - v[i]];
        }
    }

    cout << cache[k] << endl;
}