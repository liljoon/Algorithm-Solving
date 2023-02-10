#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums)
{
    vector<int> answer;

    int correct = 0;
    int zero_cnt = 0;
    for (auto num : lottos)
    {
        if (num == 0)
            zero_cnt++;
        for (auto win_num : win_nums)
        {
            if (num == win_num)
                correct++;
        }
    }
    int high = 7 - correct - zero_cnt;
    int low = 7 - correct;
    if (high >= 6)
        high = 6;
    if (low >= 6)
        low = 6;
    answer.push_back(high);
    answer.push_back(low);

    return answer;
}