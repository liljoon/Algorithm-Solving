#include <string>
#include <vector>
#include <iostream>

using namespace std;

int score_diff(vector<int> lion, vector<int> apeach)
{
    int ret = 0;
    for (int i = 0; i < 11; i++)
    {
        if (lion[i] == 0 && apeach[i] == 0)
            continue;
        if (lion[i] <= apeach[i])
            ret -= 10 - i;
        else
            ret += 10 - i;
    }
    return ret;
}

vector<int> solve(int idx, int shots, vector<int> info, vector<int> lion)
{
    if (idx == 11)
        return lion;
    if (info[idx] >= shots)
        return (solve(idx + 1, shots, info, lion));
    vector<int> a = solve(idx + 1, shots, info, lion);
    lion[idx] = info[idx] + 1;
    vector<int> b = solve(idx + 1, shots - (info[idx] + 1), info, lion);
    if (score_diff(a, info) > score_diff(b, info))
        return a;
    else if (score_diff(a, info) == score_diff(b, info))
    {
        for (int i = 10; i >= 0; i--)
        {
            if (a[i] > b[i])
                return a;
            else if (a[i] < b[i])
                return b;
        }
    }
    else
        return b;
}

vector<int> solution(int n, vector<int> info)
{
    vector<int> answer;
    vector<int> lion(11, 0);
    answer = solve(0, n, info, lion);
    int cnt = 0;
    for (int i = 0; i < 11; i++)
        cnt += answer[i];
    if (cnt != n)
        answer[10] += n - cnt;
    if (score_diff(answer, info) <= 0)
        return vector<int>(1, -1);
    return answer;
}