#include <iostream>
#include <vector>
using namespace std;
// https://dlwnsdud205.tistory.com/156
// union find
// 최대한 값이 높은 게이트 우선으로 도킹하고
// 해당 자리가 도킹되었으면 그 밑으로 parent를 연결 시켜 해결
// 도킹 자리 찾기 최적화
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
    int gate, plane;
    cin >> gate >> plane;
    parent = vector<int>(gate + 1);
    for (int i = 0; i < gate + 1; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < plane; i++)
    {
        int temp;
        cin >> temp;
        if (parent[findroot(temp)] == 0) //더 이상 도킹 불가
        {
            cout << i << endl;
            return 0;
        }
        parent[findroot(temp)] += -1; //해당 자리에 도킹하고 하나 전으로 자리 마련
    }
    cout << plane << endl; //전부 도킹 가능
}