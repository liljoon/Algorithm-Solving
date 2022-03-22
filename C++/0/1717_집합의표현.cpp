#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int findroot(int idx)
{
    int temp = idx;
    while (parent[idx] != idx)
    {
        idx = parent[idx];
    }
    // while (parent[temp] != temp)
    // {
    //     int temp2 = parent[temp];
    //     parent[temp] = idx;
    //     temp = temp2;
    // }
    parent[temp] = idx; //자신의 상단을 최상단으로 올려 루트 빨리 찾기 최적화
    return idx;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    parent = vector<int>(n + 1);
    for (int i = 0; i < parent.size(); i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int mode, a, b;
        cin >> mode >> a >> b;
        if (mode == 0)
        {
            int a_root = findroot(a);
            int b_root = findroot(b);
            parent[b_root] = a_root;
        }
        else if (mode == 1)
        {
            if (findroot(a) == findroot(b))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
}