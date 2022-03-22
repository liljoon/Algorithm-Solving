#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<string, pair<string, int>> parent;

string findroot(string a)
{
    if (a == parent[a].first)
    {
        return a;
    }
    parent[a].first = findroot(parent[a].first);
    return parent[a].first;
}

void sum(string a, string b)
{
    string a_root = findroot(a);
    string b_root = findroot(b);
    if (a_root != b_root)
    {
        parent[a_root].first = b_root;
        parent[b_root].second += parent[a_root].second;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int ti = 0; ti < t; ti++)
    {
        parent.clear(); //초기화 주의! push_back이나 insert시 까먹기 조심 ,TestCase 여러개 일 때
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string a, b;
            cin >> a >> b;
            if (parent.find(a) == parent.end())
            {
                parent.insert({a, make_pair(a, 1)});
            }
            if (parent.find(b) == parent.end())
            {
                parent.insert({b, make_pair(b, 1)});
            }
            sum(a, b);
            string a_root = findroot(a);
            cout << parent[a_root].second << "\n";
        }
    }
}