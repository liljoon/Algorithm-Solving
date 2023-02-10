#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups)
{
    long long answer = 0;
    int togo = n - 1;

    while (togo != -1)
    {
        if (deliveries[togo] <= 0 && pickups[togo] <= 0)
        {
            if (togo != 0)
            {
                deliveries[togo - 1] += deliveries[togo];
                pickups[togo - 1] += pickups[togo];
            }
            togo--;
            continue;
        }
        deliveries[togo] -= cap;
        pickups[togo] -= cap;
        answer += (togo + 1) * 2;
    }

    return answer;
}