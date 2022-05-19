#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

vector<vector<int>> map;
vector<vector<int>> tree;
vector<vector<int>> all_tree;
int n, m;

void init(int start, int end, int node, int idx)
{
    if (start == end)
    {
        tree[idx][node] = map[idx][start];
    }
    else
    {
        int mid = (start + end) / 2;
        init(start, mid, node * 2, idx);
        init(mid + 1, end, node * 2 + 1, idx);
        tree[idx][node] = tree[idx][node * 2] + tree[idx][node * 2 + 1];
    }
}

void init2(int start, int end, int node)
{
    if (start == end)
    {
        for (int i = 0; i < all_tree[node].size(); i++)
        {
            all_tree[node][i] = tree[start][i];
        }
    }
    else
    {
        int mid = (start + end) / 2;
        init2(start, mid, node * 2);
        init2(mid + 1, end, node * 2 + 1);
        for (int i = 0; i < all_tree[node].size(); i++)
        {
            all_tree[node][i] = all_tree[node * 2][i] + all_tree[node * 2 + 1][i];
        }
    }
}

int queryx(int start, int end, int node, int left, int right, int idx)
{
    if (left > end || right < start)
    {
        return 0;
    }
    else if (left <= start && right >= end)
    {
        return all_tree[idx][node];
    }
    else
    {
        int mid = (start + end) / 2;
        int a = queryx(start, mid, node * 2, left, right, idx);
        int b = queryx(mid + 1, end, node * 2 + 1, left, right, idx);
        return a + b;
    }
}

int queryy(int start, int end, int node, int leftx, int rightx, int lefty, int righty)
{
    if (lefty > end || righty < start)
    {
        return 0;
    }
    else if (lefty <= start && righty >= end)
    {
        return queryx(0, n - 1, 1, leftx, rightx, node);
    }
    else
    {
        int mid = (start + end) / 2;
        int a = queryy(start, mid, node * 2, leftx, rightx, lefty, righty);
        int b = queryy(mid + 1, end, node * 2 + 1, leftx, rightx, lefty, righty);
        return a + b;
    }
}

void update(int start, int end, int node, int val, int y, int x)
{
    if (end < x || start > x)
    {
        return;
    }
    else if (start == end)
    {
        map[y][x] = val;
        tree[y][node] = val;
    }
    else
    {
        int mid = (start + end) / 2;
        update(start, mid, node * 2, val, y, x);
        update(mid + 1, end, node * 2 + 1, val, y, x);
        tree[y][node] = tree[y][node * 2] + tree[y][node * 2 + 1];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    map = vector<vector<int>>(n, vector<int>(n));
    tree = vector<vector<int>>(n, vector<int>(4 * n));
    all_tree = vector<vector<int>>(4 * n, vector<int>(4 * n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[j][i];
        }
    }
    for (int i = 0; i < n; i++)
    {
        init(0, n - 1, 1, i);
    }
    for (int i = 0; i < m; i++)
    {
        int mode;
        cin >> mode;
        if (mode == 0) // change
        {
            int x, y, val;
            cin >> x >> y >> val;
            x--;
            y--;
            update(0, n - 1, 1, val, y, x);
        }
        else // query
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--;
            y1--;
            x2--;
            y2--;

            cout << queryy(0, n - 1, 1, x1, x2, y1, y2) << endl;
        }
    }
}