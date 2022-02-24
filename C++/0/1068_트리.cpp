#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, root;
vector<vector<int>> adj;
int leaves = 0;

void dfs(int idx)
{
    bool leaf = true;
    for (int i = 0; i < n; i++)
    {
        if (adj[idx][i])
        {
            leaf = false;
            dfs(i);
        }
    }
    if (leaf == true)
    {
        leaves++;
    }
}

int main()
{
    cin >> n;
    adj = vector<vector<int>>(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        int inp;
        cin >> inp;
        if (inp == -1)
        {
            root = i;
        }
        else
        {
            adj[inp][i] = 1;
        }
    }
    int delnode;
    cin >> delnode;
    for (int i = 0; i < n; i++)
    {
        if (adj[i][delnode])
        {
            adj[i][delnode] = 0;
        }
    }
    dfs(root);
    if (delnode == root)
    {
        leaves = 0;
    }
    cout << leaves << endl;
}