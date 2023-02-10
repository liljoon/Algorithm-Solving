#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies)
{
    vector<int> answer;
    int today_year = stoi(today.substr(0, 4));
    int today_month = stoi(today.substr(5, 4));
    int today_day = stoi(today.substr(8, 2));
    int compare = today_year * 12 * 28 + today_month * 28 + today_day;
    int deadline[30] = {0};

    for (auto i : terms)
        deadline[i[0] - 'A'] = stoi(i.substr(2, 3));
    for (int i = 0; i < privacies.size(); i++)
    {
        int compare_p = stoi(privacies[i].substr(0, 4)) * 12 * 28 + stoi(privacies[i].substr(5, 4)) * 28 + stoi(privacies[i].substr(8, 2));
        if (compare_p + deadline[privacies[i][11] - 'A'] * 28 <= compare)
            answer.push_back(i + 1);
    }
    return answer;
}