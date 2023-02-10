#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

long long solution(vector<int> queue1, vector<int> queue2)
{
    int answer = 0;

    long long sum_1 = 0, sum_2 = 0;
    queue<int> que1, que2;

    for (auto i : queue1)
    {
        sum_1 += i;
        que1.push(i);
    }
    for (auto i : queue2)
    {
        sum_2 += i;
        que2.push(i);
    }
    long long target = (sum_1 + sum_2) / 2;
    while (1)
    {
        if (sum_1 == target)
            break;
        else if (sum_1 > target)
        {
            int temp = que1.front();
            que1.pop();
            que2.push(temp);
            sum_1 -= temp;
            sum_2 += temp;
        }
        else
        {
            int temp = que2.front();
            que2.pop();
            que1.push(temp);
            sum_2 -= temp;
            sum_1 += temp;
        }
        answer++;
        if (answer > (queue1.size() + queue2.size()) * 2)
        {
            answer = -1;
            break;
        }
    }

    return answer;
}