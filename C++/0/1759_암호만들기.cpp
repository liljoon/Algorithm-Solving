#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int L, C;
vector<char> v, ans;

const char chk[5] = {'a', 'e', 'i', 'o', 'u'};

bool check()
{
    int count = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (ans[i] == chk[j])
            {
                count++;
            }
        }
    }
    if (count > 0 && (ans.size() - count) >= 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve(int n)
{
    if (ans.size() == L)
    {
        if (check())
        {
            for (int i = 0; i < L; i++)
            {
                cout << ans[i];
            }
            cout << "\n";
        }
        return;
    }
    for (int i = n + 1; i < C; i++)
    {
        ans.push_back(v[i]);
        solve(i);
        ans.pop_back();
    }
}

int main()
{
    cin >> L >> C;
    v = vector<char>(C);
    for (int i = 0; i < C; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    solve(-1);
}