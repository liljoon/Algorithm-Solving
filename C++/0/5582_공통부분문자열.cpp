#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string a, b;
vector<vector<int>> cache;
int samecount(int idx1, int idx2)
{
    if (idx1 >= a.length() || idx2 >= b.length())
    {
        return 0;
    }
    if (a[idx1] != b[idx2])
    {
        return 0;
    }
    else if (cache[idx1][idx2] != -1)
    {
        return cache[idx1][idx2];
    }
    else
    {

        cache[idx1][idx2] = samecount(idx1 + 1, idx2 + 1) + 1;
        return cache[idx1][idx2];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    cache = vector<vector<int>>(a.length(), vector<int>(b.length(), -1));
    int result = 0;
    for (int i = 0; i < b.length(); i++)
    {
        int sum = 0;
        for (int j = 0; j < a.length(); j++)
        {
            if (b[i] == a[j])
            {
                sum = samecount(j, i);
            }
            result = max(result, sum);
        }
    }
    cout << result << '\n';
}