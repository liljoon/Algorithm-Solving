#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    queue<pair<int, int>> que;
    priority_queue<int> pque;
    for (int i = 0; i < priorities.size(); i++)
    {
        pque.push(priorities[i]);
        que.push(make_pair(i, priorities[i]));
    }
    while (1)
    {
        int temp_i = que.front().first;
        int temp_prior = que.front().second;
        que.pop();
        if (temp_prior < pque.top())
        {
            que.push(make_pair(temp_i, temp_prior));
            continue;
        }
        if (temp_i == location)
            break;
        else
        {
            answer++;
            pque.pop();
        }
    }

    return answer + 1;
}