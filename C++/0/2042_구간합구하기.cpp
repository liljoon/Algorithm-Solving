#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n, m, k;
vector<long long> v;    // 수열 , 변경 적용
vector<long long> sumv; // 최초 누적합저장,변경 적용 x

//입력 2의63승 -> 전부 다 long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    vector<pair<long long, long long>> changed_num; // 변한 값을 하나씩 추가하여 저장, first: 바뀐 위치, second: 변위 값
    for (long long i = 0; i < n; i++)
    {
        long long inp;
        cin >> inp;
        v.push_back(inp);
        if (i == 0) // 누적합 저장
        {
            sumv.push_back(v[0]);
        }
        else
        {
            sumv.push_back(sumv[i - 1] + v[i]);
        }
    }
    for (long long i = 0; i < m + k; i++)
    {
        long long mode, a, b;
        cin >> mode >> a >> b;
        a--;
        if (mode == 1) // change mode
        {
            long long before = v[a];
            v[a] = b;
            changed_num.push_back(make_pair(a, b - before)); // 위치 와 변위 값 저장
        }
        else // sum mode
        {
            b--;
            long long sum = sumv[b];
            if (a != 0) //처음부터 더하는게 아닐 시
            {
                sum -= sumv[a - 1];
            }
            for (long long j = 0; j < changed_num.size(); j++) //변한 값을 확인하여 그 사이에 포함 되는지 체크
            {
                if (changed_num[j].first >= a && changed_num[j].first <= b)
                {
                    sum += changed_num[j].second; //사이에 포함된다면 변위값만 덧셈
                }
            }
            cout << sum << '\n'; //시간초과 조심
        }
    }
}