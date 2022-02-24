#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> num;
vector<char> oper;

long long calc(int a, int b, char op) //연산 해주는 함수
{
    if (op == '+')
    {
        return a + b;
    }
    else if (op == '-')
    {
        return a - b;
    }
    else
    {
        return a * b;
    }
}

long long solve(int start, int end, int min_need) // min_need: 최소값 필요할때 1
{
    if (start == end) //혼자 남으면 자신 반환
    {
        return num[start];
    }
    long long ret;
    if (min_need)
    {
        ret = 987654321;
    }
    else //음수 나올 수도 있으므로 주의
    {
        ret = -987654321;
    }
    for (int i = start; i < end; i++) // 최대, 최소 모든 경우의 수 생각, 더하기는 상관 x, 뺼셈은 뒤에 수가 작아야하고, 곱은 음수끼리 일때 오히려 커짐
    {
        long long amx = solve(start, i, 0);
        long long bmx = solve(i + 1, end, 0);
        long long amn = solve(start, i, 1);
        long long bmn = solve(i + 1, end, 1);
        long long c;
        if (min_need)
        {
            ret = min(ret, calc(amx, bmx, oper[i]));
            ret = min(ret, calc(amx, bmn, oper[i]));
            ret = min(ret, calc(amn, bmx, oper[i]));
            ret = min(ret, calc(amn, bmn, oper[i]));
        }
        else
        {
            ret = max(ret, calc(amx, bmx, oper[i]));
            ret = max(ret, calc(amx, bmn, oper[i]));
            ret = max(ret, calc(amn, bmx, oper[i]));
            ret = max(ret, calc(amn, bmn, oper[i]));
        }
    }
    return ret;
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            num.push_back(int(s[i]) - '0');
        }
        else
        {
            oper.push_back(s[i]);
        }
    }

    cout << solve(0, num.size() - 1, 0) << endl;
}