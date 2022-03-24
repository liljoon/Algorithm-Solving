#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> parent; // 부모, 센터까지의 거리

int findroot(int idx) // 여기서 그냥 압축하면 루트까지의 거리 저장 못하므로 스킵
{
    if (parent[idx].first == idx)
    {
        return idx;
    }
    return findroot(parent[idx].first);
}

void sum_set(int a, int b)
{
    parent[a].first = b;                  // 루트끼리 합쳐버리면 거리를 판단할 수 없으므로 b 밑에 붙여서 거리 저장
    parent[a].second = abs(a - b) % 1000; // 값이 딱 1000이 되면 0이 될 수 있음에 주의
}

int find_distance(int idx) //거리 측정하며 루트로 압축 + 루트까지의 거리 저장
{
    if (parent[idx].first == idx)
    {
        return 0;
    }
    int ret = parent[idx].second + find_distance(parent[idx].first); // 재귀로 루트까지의 거리 계산
    parent[idx].first = findroot(idx);
    parent[idx].second = ret;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int ti = 0; ti < t; ti++)
    {
        int n;
        cin >> n;
        parent = vector<pair<int, int>>(n + 1);
        for (int i = 1; i < n + 1; i++)
        {
            parent[i] = make_pair(i, 0);
        }
        char mode;
        do
        {
            cin >> mode;
            if (mode == 'E')
            {
                int start;
                cin >> start;
                cout << find_distance(start) << "\n";
            }
            else if (mode == 'I')
            {
                int a, b;
                cin >> a >> b;
                sum_set(a, b);
            }
        } while (mode != 'O');
    }
}