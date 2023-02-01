#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v2;
vector<int> cache(101, -1);

int solve(int idx)
{
    if (idx != -1 && cache[idx] != -1)
    {
        return cache[idx];
    }
    int temp = 0;
    for (int i = idx + 1; i < v2.size(); i++)
    {
        int a;
        if (idx == -1)
            a = -1;
        else
            a = v2[idx];
        if (a < v2[i])
            temp = max(temp, solve(i) + 1);
    }
    if (idx != -1)
        cache[idx] = temp;
    return temp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> v(501, -1);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a] = b;
    }
    for (int i = 0; i < 501; i++)
    {
        if (v[i] != -1)
            v2.push_back(v[i]);
    }
    cout << n - solve(-1) << endl;
}