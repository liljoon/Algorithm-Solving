#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 입력 받은 값을 저장 후 pque에 넣고
// 최소값을 하나씩 빼면서 입력받은 값에 다 곱하여 push
// 이 때 중복제거와 답이 아닌 값을 오버플로 날 수 있음에 주의

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k, n;
    cin >> k >> n;
    priority_queue<int, vector<int>, greater<int>> pque;
    vector<int> v;
    for (int i = 0; i < k; i++)
    {
        int inp;
        cin >> inp;
        v.push_back(inp);
        pque.push(inp);
    }
    int before = -1;
    for (int i = 0; i < n; i++)
    {
        int now = pque.top();
        pque.pop();
        if (before != -1 && before == now) //중복 되었을 경우 다시 돌어가서 제거
        {
            i--;
            continue;
        }
        for (int j = 0; j < k; j++)
        {
            long long temp = now; // long long temp = now * v[j]; 를 하게 되면 int 였던 now에 곱해져 오버플로 나옴
            temp *= v[j];
            if (temp <= 2147483647) // 오버 플로 방지
                pque.push(now * v[j]);
        }
        before = now;
    }
    cout << before << endl;
}