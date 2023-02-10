#include <string>
#include <vector>
#include <set>

using namespace std;

bool is_match(string id, string banned_id)
{
    if (id.length() != banned_id.length())
        return false;
    for (int i = 0; i < id.length(); i++)
    {
        if (id[i] != banned_id[i] && banned_id[i] != '*')
            return false;
    }
    return true;
}

vector<vector<int>> ans;

void solve(int idx, vector<int> &used, vector<string> &user_id, vector<string> &banned_id)
{
    if (idx >= banned_id.size())
    {
        ans.push_back(used);
        return;
    }
    int flag = 0;
    for (int i = 0; i < user_id.size(); i++)
    {
        if (used[i])
            continue;
        if (is_match(user_id[i], banned_id[idx]))
        {
            flag = 1;
            used[i] = 1;
            solve(idx + 1, used, user_id, banned_id);
            used[i] = 0;
        }
    }
    if (!flag)
        return;
}

int solution(vector<string> user_id, vector<string> banned_id)
{
    int answer = 0;
    vector<int> used(user_id.size(), 0);
    solve(0, used, user_id, banned_id);
    set<vector<int>> s;

    for (auto i : ans)
        s.insert(i);
    answer = s.size();
    return answer;
}