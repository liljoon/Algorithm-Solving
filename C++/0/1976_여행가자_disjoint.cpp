#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;
int findroot(int a)
{
    if (parent[a] == a)
    {
        return a;
    }
    parent[a] = findroot(parent[a]);
    return parent[a];
}

void sum(int a, int b)
{
    int a_root = findroot(a);
    int b_root = findroot(b);
    parent[a_root] = b_root;
}

int main()
{
    int n, m;
    cin >> n >> m;
    parent = vector<int>(n);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int inp;
            cin >> inp;
            if (inp)
            {
                sum(i, j);
            }
        }
    }
    int temp = -1;
    for (int i = 0; i < m; i++)
    {
        int inp;
        cin >> inp;
        inp--;
        if (temp == -1)
        {
            temp = findroot(inp);
        }
        else if (temp != findroot(inp))
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}