#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> map;
vector<int> t1, t2;

int solve(int idx)
{
    if (idx == n)
    {
        //차이 계산
        if (t1.empty() || t2.empty())
        {
            return 987654321;
        }
        else
        {
            int t1_sum = 0;
            for (int i = 0; i < t1.size(); i++)
            {
                for (int j = i + 1; j < t1.size(); j++)
                {
                    t1_sum += (map[t1[i]][t1[j]] + map[t1[j]][t1[i]]);
                }
            }
            int t2_sum = 0;
            for (int i = 0; i < t2.size(); i++)
            {
                for (int j = i + 1; j < t2.size(); j++)
                {
                    t2_sum += (map[t2[i]][t2[j]] + map[t2[j]][t2[i]]);
                }
            }
            return abs(t1_sum - t2_sum);
        }
    }
    t1.push_back(idx);
    int a = solve(idx + 1);
    t1.pop_back();
    t2.push_back(idx);
    int b = solve(idx + 1);
    t2.pop_back();
    return min(a, b);
}

int main()
{
    cin >> n;
    map = vector<vector<int>>(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
    cout << solve(0) << endl;
}