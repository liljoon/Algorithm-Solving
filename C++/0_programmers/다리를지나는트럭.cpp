#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;
    int time = 1;
    int start = 0;
    int end = 1;
    int sum = truck_weights[0];
    vector<int> uptime(truck_weights.size());
    uptime[0] = 1;
    while (start < truck_weights.size())
    {
        if (time - uptime[start] >= bridge_length)
        {
            sum -= truck_weights[start];
            start++;
        }
        if (end < truck_weights.size() && sum + truck_weights[end] <= weight)
        {
            uptime[end] = time;
            sum += truck_weights[end];
            end++;
        }
        time++;
    }
    answer = time - 1;
    return answer;
}