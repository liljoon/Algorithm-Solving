#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;

int gems_num(vector<string> &gems)
{
    set<string> s;

    for (auto gem : gems)
        s.insert(gem);
    return s.size();
}

vector<int> solution(vector<string> gems)
{
    vector<int> answer;
    map<string, int> m;
    answer.push_back(-1);
    answer.push_back(-1);

    int min_len = 987654321;
    int gem_n = gems_num(gems);
    int start = 0;
    int end = 0;

    while (start < gems.size())
    {
        if (gem_n == m.size()) // 최소 하나씩 다 들고 있으면
        {
            if (min_len > end - start)
            {
                answer[0] = start;
                answer[1] = end - 1;
                min_len = end - start;
            }
            m[gems[start]] -= 1;
            if (m[gems[start]] == 0)
                m.erase(gems[start]);
            start++;
        }
        else
        {
            if (end == gems.size())
                break;
            if (m.find(gems[end]) == m.end())
                m.insert({gems[end], 1});
            else
                m[gems[end]] += 1;
            end++;
        }
    }
    answer[0] += 1;
    answer[1] += 1;
    return answer;
}