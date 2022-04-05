#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'
#define div 1000000007

vector<int> v;
vector<long long> tree;

void init(int start, int end, int node)
{
    if (start == end)
    {
        tree[node] = v[start];
    }
    else
    {
        int mid = (start + end) / 2;
        init(start, mid, node * 2);
        init(mid + 1, end, node * 2 + 1);
        tree[node] = tree[node * 2] * tree[node * 2 + 1] % div;
    }
}

int query(int start, int end, int left, int right, int node)
{
    if (right < start || left > end)
    {
        return 1; // 1은 곱해져도 의미X
    }
    else if (left <= start && right >= end)
    {
        return tree[node];
    }
    else
    {
        int mid = (start + end) / 2;
        long long a = query(start, mid, left, right, node * 2);
        long long b = query(mid + 1, end, left, right, node * 2 + 1);
        return a * b % div;
    }
}

void update(int start, int end, int node, int idx, int val)
{
    if (start > idx || end < idx)
    {
        return;
    }
    else if (start == end)
    {
        tree[node] = val;
        v[idx] = val;
    }
    else
    {
        int mid = (start + end) / 2;
        update(start, mid, node * 2, idx, val);
        update(mid + 1, end, node * 2 + 1, idx, val);
        tree[node] = tree[node * 2] * tree[node * 2 + 1] % div;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    v.resize(n);
    tree.resize(4 * n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    init(0, n - 1, 1);
    for (int i = 0; i < m + k; i++)
    {
        int mode, a, b;
        cin >> mode >> a >> b;
        if (mode == 1) // change
        {
            a--;
            update(0, n - 1, 1, a, b);
        }
        else // query
        {
            a--;
            b--;
            cout << query(0, n - 1, a, b, 1) << endl;
        }
    }
}