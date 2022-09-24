//https://school.programmers.co.kr/learn/courses/30/lessons/92334

#include <string>
#include<iostream>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

map<string, int> index_init(vector<string> id_list)
{
    map<string, int> m;
    for(int i=0;i<id_list.size();i++)
        m.insert({id_list[i], i});
    return m;
}

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(),0);
    vector<vector<int>> adj(id_list.size(), vector<int>(id_list.size(), 0));
    map<string, int> m = index_init(id_list);
    
    for(int i=0;i < report.size();i++)
    {
        vector<string> sp = split(report[i], ' ');
        adj[m[sp[0]]][m[sp[1]]] = 1;    
    }
    for(int i=0;i<id_list.size();i++)
    {
        int cnt = 0;
        for(int j=0;j<id_list.size();j++)
        {
            cnt += adj[j][i];
        }
        if(cnt >= k)
        {
            for(int j=0;j<id_list.size();j++)
            {
                answer[j] += adj[j][i];
            }
        }
    }
    
    return answer;
}
