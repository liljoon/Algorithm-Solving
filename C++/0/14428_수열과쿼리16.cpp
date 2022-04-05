#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

vector<int> v;
vector<int> tree;

void init(int start, int end, int node)
{
    if (start == end)
    {
        tree[node] = start;
    }
    else
    {
        int mid = (start + end) / 2;
        init(start, mid, node * 2);
        init(mid + 1, end, node * 2 + 1);
        if (v[tree[node * 2]] <= v[tree[node * 2 + 1]])
        {
            tree[node] = tree[node * 2];
        }
        else
        {
            tree[node] = tree[node * 2 + 1];
        }
    }
}

int query(int start, int end, int left, int right, int node)
{
    if (right < start || left > end)
    {
        return 0;
    }
    else if (left <= start && right >= end)
    {
        return tree[node];
    }
    else
    {
        int mid = (start + end) / 2;
        int a = query(start, mid, left, right, node * 2);
        int b = query(mid + 1, end, left, right, node * 2 + 1);
        if (v[a] <= v[b])
        {
            return a;
        }
        else
        {
            return b;
        }
    }
}

void update(int start, int end, int node, int idx, int val)
{
    if (idx < start || idx > end)
    {
        return;
    }
    else if (start == end)
    {
        v[start] = val;
    }
    else
    {
        int mid = (start + end) / 2;
        update(start, mid, node * 2, idx, val);
        update(mid + 1, end, node * 2 + 1, idx, val);
        if (v[tree[node * 2]] <= v[tree[node * 2 + 1]])
        {
            tree[node] = tree[node * 2];
        }
        else
        {
            tree[node] = tree[node * 2 + 1];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    v.resize(n + 1);
    v[0] = 2100000000;
    tree.resize(4 * n);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    init(1, n, 1);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int mode, a, b;
        cin >> mode >> a >> b;
        if (mode == 1) // change
        {
            update(1, n, 1, a, b);
        }
        else // query
        {
            cout << query(1, n, a, b, 1) << endl;
        }
    }
}