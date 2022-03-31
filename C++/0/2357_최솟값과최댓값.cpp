#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int find_left, find_right;
vector<int> v;
vector<int> tree_low, tree_high;

void init(int start, int end, int node)
{
    if (start == end)
    {
        tree_low[node] = v[start];
        tree_high[node] = v[start];
    }
    else
    {
        int mid = (start + end) / 2;
        init(start, mid, node * 2 + 1);
        init(mid + 1, end, node * 2 + 2);
        tree_low[node] = min(tree_low[node * 2 + 1], tree_low[node * 2 + 2]);
        tree_high[node] = max(tree_high[node * 2 + 1], tree_high[node * 2 + 2]);
    }
}

int query_low(int start, int end, int node)
{
    if (find_left > end || find_right < start)
    {
        return 2100000000;
    }
    if (find_left <= start && find_right >= end)
    {
        return tree_low[node];
    }
    int mid = (start + end) / 2;
    int a = query_low(start, mid, node * 2 + 1);
    int b = query_low(mid + 1, end, node * 2 + 2);
    return min(a, b);
}

int query_high(int start, int end, int node)
{
    if (find_left > end || find_right < start)
    {
        return 0;
    }
    if (find_left <= start && find_right >= end)
    {
        return tree_high[node];
    }
    int mid = (start + end) / 2;
    int a = query_high(start, mid, node * 2 + 1);
    int b = query_high(mid + 1, end, node * 2 + 2);
    return max(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    v.resize(n);
    tree_low.resize(4 * n);
    tree_high.resize(4 * n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    init(0, n - 1, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> find_left;
        cin >> find_right;
        find_left--;
        find_right--;
        cout << query_low(0, n - 1, 0) << ' ' << query_high(0, n - 1, 0) << '\n';
    }
}