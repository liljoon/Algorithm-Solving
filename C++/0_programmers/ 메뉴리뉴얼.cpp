#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

// 부분 문자열 모두 찾기
void part(string s, string temp, int idx, int cnt, vector<string> &v)
{
    if (cnt == 0)
    {
        v.push_back(temp);
        return;
    }
    if (idx >= s.size())
    {
        return;
    }

    part(s, temp, idx + 1, cnt, v);
    temp.push_back(s[idx]);
    part(s, temp, idx + 1, cnt - 1, v);
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;
    map<string, int> m;
    for (int i = 0; i < orders.size(); i++)
    {
        sort(orders[i].begin(), orders[i].end()); // 문자열 내부 정렬
        for (int j = 0; j < course.size(); j++)
        {
            vector<string> v;
            string temp = "";
            part(orders[i], temp, 0, course[j], v);
            for (int k = 0; k < v.size(); k++) // 모든 부분 문자열 map에 집어넣고 개수 넣기
            {
                auto it = m.find(v[k]);
                if (it == m.end())
                {
                    m[v[k]] = 0;
                }
                else
                {
                    m[v[k]] += 1;
                }
            }
        }
    }
    for (int i = 0; i < course.size(); i++)
    {
        priority_queue<pair<int, string>> pque;
        // map 전부 순회하면서 코스 개수 일치하고 2개이상 발견되었을 경우 priority queue에 넣음.
        for (auto iter = m.begin(); iter != m.end(); iter++)
        {
            if (iter->first.size() == course[i] && iter->second > 0)
            {
                pque.push({iter->second, iter->first});
            }
        }
        int temp;
        // 하나 꺼내고 계속 주문 개수가 같으면 계속 삽입.
        if (!pque.empty())
        {
            answer.push_back(pque.top().second);
            temp = pque.top().first;
            pque.pop();
            while (!pque.empty() && temp == pque.top().first)
            {
                answer.push_back(pque.top().second);
                pque.pop();
            }
        }
    }
    sort(answer.begin(), answer.end()); // 문자열 끼리 정렬
    return answer;
}