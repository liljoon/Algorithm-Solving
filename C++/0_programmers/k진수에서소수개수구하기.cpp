#include <string>
#include <vector>
#include <iostream>

using namespace std;

string transfer(int n, int k)
{
    string s = "";
    if (n == 0)
        s = "0";
    while (n != 0)
    {
        s.append(1, n % k + '0');
        n /= k;
    }
    for (int i = 0; i < s.size() / 2; i++)
    {
        int temp = s[i];
        s[i] = s[s.size() - i - 1];
        s[s.size() - i - 1] = temp;
    }
    return s;
}

int is_sosu(long long n)
{
    if (n < 2)
        return 0;
    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int spl(string s)
{
    int start, end;
    start = 0;
    int cnt = 0;
    while (end < s.size())
    {
        while (s[start] == '0')
            start++;
        if (start >= s.size())
            break;
        end = start;
        while (s[end] != '0' && s[end] != '\0')
            end++;
        // cout<<start<<" "<<end<<endl;
        cnt += is_sosu(stol(s.substr(start, end - start)));
        start = end;
    }
    return cnt;
}

int solution(int n, int k)
{
    int answer = -1;
    string s = transfer(n, k);
    answer = spl(s);
    return answer;
}