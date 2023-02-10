#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<char> split_operator(string s)
{
    vector<char> v;
    
    for (int i=0; i < s.size(); i++)
    {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*')
        {
          v.push_back(s[i]);
        }
    }
    return v;
}
vector<long long> split_int(string s)
{
    vector<long long> v;
    
    long long temp = 0;
    for (int i=0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            temp *= 10;
            temp += s[i] - '0';
        }
        else
        {
            v.push_back(temp);
            temp = 0;
        }
    }
    v.push_back(temp);
    return v;
}

long long operate(long long a, long long b, char oper)
{
    if (oper == '+')
        return a+b;
    if (oper == '-')
        return a-b;
    if (oper == '*')
        return a*b;
}   

void operate_all(vector<long long>& num, vector<char>& opers, char oper)
{
    int n = opers.size();
    int num_i = 0;
    int opers_i = 0;
    
    for(int i=0; i< n;i++)
    {
        if (opers[opers_i] == oper)
        {
            num[num_i] = operate(num[num_i], num[num_i+1], oper);
            num.erase(num.begin() + num_i+1);
            opers.erase(opers.begin() + opers_i);
        }
        else
        {
            opers_i++;
            num_i++;
        }
    }
}

long long solution(string expression) {
    long long answer = 0;
    vector<long long> num = split_int(expression);
    vector<char> opers = split_operator(expression);
    
    
    string oper_order[] = { "*+-", "*-+","+*-","+-*","-+*","-*+"};
    for(int i=0;i<6;i++)
    {
        vector<long long> num_t = num;
        vector<char> opers_t = opers;
        operate_all(num_t, opers_t, oper_order[i][0]);
        operate_all(num_t, opers_t, oper_order[i][1]);
        operate_all(num_t, opers_t, oper_order[i][2]);
        answer = answer  > abs(num_t[0]) ? answer : abs(num_t[0]);
    }
  
    

    
    return answer;
}