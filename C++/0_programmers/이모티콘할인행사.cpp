#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int n;

void make_permutation(vector<int> per, int idx, vector<vector<int>> &ret)
{
    if (idx == n)
    {
        ret.push_back(per);
        return;
    }
    per.push_back(10);
    for (int i = 0; i < 4; i++)
    {
        make_permutation(per, idx + 1, ret);
        per[idx] += 10;
    }
}

pair<int, int> calc(vector<int> &discount, vector<vector<int>> &users, vector<int> &emoticons)
{
    int price = 0;
    int emoticon_plus = 0;
    for (int i = 0; i < users.size(); i++)
    {
        int temp_price = 0;
        for (int j = 0; j < emoticons.size(); j++)
        {
            if (discount[j] >= users[i][0])
            {
                temp_price += emoticons[j] * (100 - discount[j]) / 100;
            }
        }
        if (temp_price >= users[i][1])
            emoticon_plus++;
        else
            price += temp_price;
    }
    return make_pair(emoticon_plus, price);
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons)
{
    vector<int> answer;
    n = emoticons.size();
    vector<vector<int>> per_arr;
    make_permutation(vector<int>(), 0, per_arr);

    vector<pair<int, int>> v;
    for (auto i : per_arr)
    {
        pair<int, int> p = calc(i, users, emoticons);
        v.push_back(p);
    }
    sort(v.begin(), v.end());
    answer.push_back(v[v.size() - 1].first);
    answer.push_back(v[v.size() - 1].second);

    return answer;
}