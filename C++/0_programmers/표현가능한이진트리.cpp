#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solve(int left, int right, string &s, int parent)
{
    if (left > right)
        return 1;
    int idx = (left + right) / 2;
    if (parent == 0 && s[idx] == '1')
        return 0;
    int te;
    if (parent == 0 || s[idx] == '0')
        te = 0;
    else if (s[idx] == '1')
        te = 1;
    return (solve(left, idx - 1, s, te) && solve(idx + 1, right, s, te));
}

vector<int> solution(vector<long long> numbers)
{
    vector<int> answer;
    for (auto num : numbers)
    {
        string s = "";
        while (num)
        {
            string t = "";
            t.push_back(num % 2 + '0');
            s.insert(0, t);
            num /= 2;
        }
        int n = 1;
        while (1)
        {
            int temp = pow(2, n) - 1;
            if (temp >= s.size())
            {
                string t = "";
                t.append(temp - s.size(), '0');
                s.insert(0, t);
                break;
            }
            n++;
        }
        answer.push_back(solve(0, s.size() - 1, s, 1));
    }

    return answer;
}