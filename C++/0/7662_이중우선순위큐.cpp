#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void chk_valid_high(priority_queue<pair<int, int>> &pque, vector<bool> &valid) // call by referenc 주의 할 것
{
    while (!pque.empty())
    {
        int idx = pque.top().second;
        if (valid[idx])
        {
            break;
        }
        pque.pop();
    }
}

void chk_valid_low(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> &pque, vector<bool> &valid)
{
    while (!pque.empty())
    {
        int idx = pque.top().second;
        if (valid[idx])
        {
            break;
        }
        pque.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int ti = 0; ti < t; ti++)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> low_pque;
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> high_pque;
        int k;
        cin >> k;
        vector<bool> valid(k, true); // 해당 번째 명령어에서 실행된 삽입 값이 지워졌는지 체크
        for (int ki = 0; ki < k; ki++)
        {
            char mode;
            int inp;
            cin >> mode >> inp;
            if (mode == 'I')
            {
                low_pque.push(make_pair(inp, ki));
                high_pque.push(make_pair(inp, ki));
            }
            else
            {
                if (inp == 1)
                {
                    chk_valid_high(high_pque, valid);
                    if (!high_pque.empty())
                    {
                        int idx = high_pque.top().second;
                        valid[idx] = false;
                        high_pque.pop();
                    }
                }
                else
                {
                    chk_valid_low(low_pque, valid);
                    if (!low_pque.empty())
                    {
                        int idx = low_pque.top().second;
                        valid[idx] = false;
                        low_pque.pop();
                    }
                }
            }
        }
        chk_valid_high(high_pque, valid);
        chk_valid_low(low_pque, valid);
        if (!high_pque.empty() && !low_pque.empty())
        {
            cout << high_pque.top().first << " " << low_pque.top().first << '\n';
        }
        else
        {
            cout << "EMPTY" << '\n';
        }
    }
}