#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int dist_min(int from, int to, int n)
{
    return min(abs(from - to), n - abs(from - to));
}

int dfs(int idx, string name)
{
    int ret = 987654321;
    for (int i = 0; i < name.length(); i++)
    {
        if (idx != i && name[i] != 'A')
        {
            char temp = name[i];
            name[i] = 'A';
            ret = min(ret, dist_min(idx, i, name.length()) + dfs(i, name));
            name[i] = temp;
        }
    }
    if (ret == 987654321)
        return 0;
    return ret;
}

int solution(string name)
{
    int answer = 0;
    int cnt_ud = 0;
    int cnt_lr = 0;

    for (int i = 0; i < name.length(); i++)
        cnt_ud += min(name[i] - 'A', 26 + 'A' - name[i]);

    name[0] = 'A';
    cnt_lr = dfs(0, name);
    answer = cnt_ud + cnt_lr;
    return answer;
}