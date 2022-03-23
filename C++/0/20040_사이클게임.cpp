#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;
int findroot(int idx)
{
    if (idx == parent[idx])
    {
        return idx;
    }
    parent[idx] = findroot(parent[idx]);
    return parent[idx];
}

void sum_set(int a, int b)
{
    int a_root = findroot(a);
    int b_root = findroot(b);
    if (a_root != b_root)
    {
        parent[a_root] = b_root;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    parent = vector<int>(n);
    int game_end = 0;
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (findroot(a) == findroot(b) && game_end == 0)
        {
            game_end = i + 1;
        }
        sum_set(a, b);
    }
    cout << game_end << "\n";
}