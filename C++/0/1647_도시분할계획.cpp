#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct st
{
    int weight;
    int from;
    int to;
    st(int w, int f, int t)
    {
        weight = w;
        from = f;
        to = t;
    }
};

bool cmp(st a, st b)
{
    return a.weight < b.weight;
}

int n, m;
vector<st> v;
vector<int> vst;
int find_top(int a)
{
    if (vst[a] == a)
        return a;
    vst[a] = find_top(vst[a]);
    return vst[a];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> m;
    vst.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back(st(c, b, a));
    }
    sort(v.begin(), v.end(), cmp);

    for (int i = 1; i <= n; i++)
        vst[i] = i;
    int ret = 0;
    int before = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (find_top(vst[v[i].from]) == find_top(vst[v[i].to]))
            continue;
        ret += v[i].weight;
        before = v[i].weight;
        vst[find_top(vst[v[i].from])] = vst[find_top(vst[v[i].to])];
    }
    cout << ret - before << endl;
}