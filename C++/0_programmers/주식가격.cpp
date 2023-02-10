#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices)
{
    vector<int> answer(prices.size());

    stack<pair<int, int>> st;

    for (int i = 0; i < prices.size(); i++)
    {
        while (!st.empty() && st.top().second > prices[i])
        {
            answer[st.top().first] = i - st.top().first;
            st.pop();
        }
        st.push(make_pair(i, prices[i]));
    }
    while (!st.empty())
    {
        answer[st.top().first] = prices.size() - 1 - st.top().first; // 마지막 지난 초가 아닌 마지막 초 기준
        st.pop();
    }
    return answer;
}