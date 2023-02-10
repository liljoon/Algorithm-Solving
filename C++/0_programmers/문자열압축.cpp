#include <string>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int solve(string s, int n)
{
    int cnt = 1;
    int ret = s.size();
    for (int i = 0; i < s.size() - n; i += n)
    {
        if (s.substr(i, n) == s.substr(i + n, n))
        {
            cnt++;
            ret -= n;
        }
        else
        {
            if (cnt > 1)
                ret += to_string(cnt).size();
            cnt = 1;
        }
    }
    if (cnt > 1)
        ret += to_string(cnt).size();
    return ret;
}

int solution(string s)
{
    int answer = 0;
    answer = s.size();
    for (int i = 1; i <= s.size() / 2; i++)
    {
        answer = min(answer, solve(s, i));
    }
    return answer;
}