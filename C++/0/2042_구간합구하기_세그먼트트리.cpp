#include <iostream>
#include <vector>
using namespace std;

vector<long long> v;
vector<long long> tree;
int find_left, find_right;
int n, m, k;

void init(int start, int end, int node)
{
    if (start == end)
    {
        tree[node] = v[start];
    }
    else
    {
        init(start, (start + end) / 2, node * 2 + 1);
        init((start + end) / 2 + 1, end, node * 2 + 2);
        tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
    }
}

long long query(int start, int end, int node)
{
    if (find_left > end || find_right < start)
    {
        return 0;
    }
    if (find_left <= start && find_right >= end)
    {
        return tree[node];
    }
    long long a = query(start, (start + end) / 2, node * 2 + 1);
    long long b = query((start + end) / 2 + 1, end, node * 2 + 2);
    return a + b;
}

void update2(int start, int end, int node, long long diff, int idx)
{
    if (idx < start || idx > end)
        return;
    tree[node] = tree[node] + diff;
    if (start != end)
    {
        update2(start, (start + end) / 2, node * 2 + 1, diff, idx);
        update2((start + end) / 2 + 1, end, node * 2 + 2, diff, idx);
    }
}

void update(int idx, long long data)
{
    long long diff = data - v[idx];
    v[idx] = data;
    update2(0, n - 1, 0, diff, idx);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    v = vector<long long>(n);
    tree = vector<long long>(2 * n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    init(0, n - 1, 0);

    for (int i = 0; i < m + k; i++)
    {
        int mode;
        cin >> mode;
        if (mode == 1)
        {
            long long b, c;
            cin >> b >> c;
            b--;
            update(b, c);
        }
        else
        {
            long long b, c;
            cin >> b >> c;
            b--;
            c--;
            find_left = b;
            find_right = c;
            cout << query(0, n - 1, 0) << "\n";
        }
    }
}