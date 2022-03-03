#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k;
int mn = 987654321;
int main()
{
    cin >> n >> k;
    vector<int> visited(100001, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push(make_pair(0, n));
    while (!que.empty())
    {
        int idx = que.top().second;
        int time = que.top().first;
        que.pop();
        if (idx > 100000 || idx < 0)
        {
            continue;
        }
        if (visited[idx])
        {
            continue;
        }
        visited[idx] = true;

        if (idx == k)
        {
            cout << time << endl;
            return 0;
        }
        else
        {
            if (idx != 0)
            {
                que.push(make_pair(time, idx * 2));
            }
            que.push(make_pair(time + 1, idx + 1));
            if (idx > 0)
            {
                que.push(make_pair(time + 1, idx - 1));
            }
        }
    }
}