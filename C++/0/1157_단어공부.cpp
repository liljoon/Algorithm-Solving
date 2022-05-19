#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> cnt(26, 0);
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            cnt[s[i] - 'a']++;
        }
        else
        {
            cnt[s[i] - 'A']++;
        }
    }
    int ret = 0;
    for (int i = 0; i < 26; i++)
    {
        if (cnt[ret] < cnt[i])
        {
            ret = i;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (ret != i && cnt[ret] == cnt[i])
        {
            cout << "?" << endl;
            return 0;
        }
    }

    cout << char(ret + 'A') << endl;
}