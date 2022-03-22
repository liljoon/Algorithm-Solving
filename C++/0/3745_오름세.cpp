#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while (1)
    {
        cin >> n;
        if (cin.eof())
        {
            break;
        }
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int inp;
            cin >> inp;
            if (i == 0)
            {
                v.push_back(inp);
            }
            else
            {
                if (inp > v[v.size() - 1])
                {
                    v.push_back(inp);
                }
                else
                {
                    int put_idx = lower_bound(v.begin(), v.end(), inp) - v.begin();
                    v[put_idx] = inp;
                }
            }
        }
        cout << v.size() << endl;
    }
}