//https://school.programmers.co.kr/learn/courses/30/lessons/118666

#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "    ";
    map<char, int> result;
    result['R'] = 0;
    result['T'] = 0;
    result['C'] = 0;
    result['F'] = 0;
    result['J'] = 0;
    result['M'] = 0;
    result['A'] = 0;
    result['N'] = 0;
    for (int i=0;i<survey.size();i++)
    {
        if (choices[i] >= 1 && choices[i] <= 3)
            result[survey[i][0]] += (4 - choices[i]);
        else
            result[survey[i][1]] += (choices[i] - 4);
    }
    if (result['R'] >= result['T'])
        answer[0] = 'R';
    else
        answer[0] = 'T';
    if (result['C'] >= result['F'])
        answer[1] = 'C';
    else
        answer[1] = 'F';
    if (result['J'] >= result['M'])
        answer[2] = 'J';
    else
        answer[2] = 'M';
    if (result['A'] >= result['N'])
        answer[3] = 'A';
    else
        answer[3] = 'N';
    return answer;
}
