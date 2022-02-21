#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string a, b;
vector<vector<string>> cache;

string solve1(int idx1, int idx2)
{
    if (idx1 >= a.length() || idx2 >= b.length())
    {
        return "";
    }
    if (cache[idx1][idx2] != "-1")
    {
        return cache[idx1][idx2];
    }
    if (a[idx1] == b[idx2])
    {
        string temp1 = b[idx1] + solve1(idx1 + 1, idx2 + 1);
        string temp2 = b[idx2] + solve1(idx1 + 1, idx2 + 1);
        cache[idx1][idx2] = (temp1.length() > temp2.length()) ? temp1 : temp2;
        return cache[idx1][idx2];
    }
    else
    {
        string temp1 = solve1(idx1 + 1, idx2);
        string temp2 = solve1(idx1, idx2 + 1);
        cache[idx1][idx2] = (temp1.length() > temp2.length()) ? temp1 : temp2;
        return cache[idx1][idx2];
    }
}

int main()
{
    cin >> a;
    cin >> b;
    cache = vector<vector<string>>(a.length(), vector<string>(b.length(), "-1"));
    string ans = solve1(0, 0);
    cout << ans.length() << endl;
    cout << ans << endl;
}