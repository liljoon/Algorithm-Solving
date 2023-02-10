#include <string>
#include <vector>

using namespace std;

vector<int> vst;

void dfs(int idx, int n, vector<vector<int>> computers)
{
    if (vst[idx])
        return;
    vst[idx] = 1;
    for (int i = 0; i < n; i++)
    {
        if (computers[idx][i] == 1)
            dfs(i, n, computers);
    }
    return;
}

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    vst = vector<int>(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (vst[i] == 0)
        {
            answer++;
            dfs(i, n, computers);
        }
    }
    return answer;
}