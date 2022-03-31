#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int find_left, find_right;
vector<int> v;
vector<int> tree;

void init(int start, int end, int node)
{
    if (start == end)
    {
        tree[node] = v[start];
    }
    else
    {
        int mid = (start + end) / 2;
        init(start, mid, node * 2 + 1);
        init(mid + 1, end, node * 2 + 2);
        tree[node] = min(tree[node * 2 + 1], tree[node * 2 + 2]);
    }
}

int query(int start, int end, int node)
{
    if (find_left > end || find_right < start)
    {
        return 2100000000;
    }
    if (find_left <= start && find_right >= end)
    {
        return tree[node];
    }
    int mid = (start + end) / 2;
    int a = query(start, mid, node * 2 + 1);
    int b = query(mid + 1, end, node * 2 + 2);
    return min(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    v.resize(n);
    tree.resize(4 * n);
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
        cout << query(0, n - 1, 0) << '\n';
    }
}