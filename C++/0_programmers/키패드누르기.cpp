#include <string>
#include <vector>

using namespace std;

int dist(int a, int b)
{
    pair<int, int> map[12] = {{3, 1}, {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {2, 0}, {2, 1}, {2, 2}, {3, 0}, {3, 2}}; // 10 : *, 11 : #

    int ret = 0;
    ret += abs(map[a].first - map[b].first);
    ret += abs(map[a].second - map[b].second);
    return ret;
}

void touch(char c, int &left, int &right, int n, string &answer)
{
    answer.push_back(c);
    if (c == 'L')
        left = n;
    else
        right = n;
}

string solution(vector<int> numbers, string hand)
{
    string answer = "";
    int left = 10;
    int right = 11;

    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
            touch('L', left, right, numbers[i], answer);
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
            touch('R', left, right, numbers[i], answer);
        else
        {
            if (dist(left, numbers[i]) > dist(right, numbers[i]))
                touch('R', left, right, numbers[i], answer);
            else if (dist(left, numbers[i]) < dist(right, numbers[i]))
                touch('L', left, right, numbers[i], answer);
            else
            {
                if (hand == "right")
                    touch('R', left, right, numbers[i], answer);
                else
                    touch('L', left, right, numbers[i], answer);
            }
        }
    }
    return answer;
}