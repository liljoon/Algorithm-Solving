#include <string>
#include <vector>

using namespace std;

int solve(vector<int> numbers, int idx, int sum, int target)
{
    if (idx == numbers.size())
    {
        if (sum == target)
            return 1;
        else
            return 0;
    }
    int a = solve(numbers, idx + 1, sum + numbers[idx], target);
    int b = solve(numbers, idx + 1, sum - numbers[idx], target);
    return a + b;
}

int solution(vector<int> numbers, int target)
{
    int answer = 0;
    answer = solve(numbers, 0, 0, target);
    return answer;
}