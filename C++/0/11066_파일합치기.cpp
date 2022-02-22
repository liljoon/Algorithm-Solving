#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int n;
vector<vector<int>> cache;
vector<int> cache_sum;

int solve(int start, int end) // start 부터 end까지 들어간 비용을 의미(합 의미 X!!)
{
    if (start == end) //하나의 경우 들어간 비용 없음
    {
        return 0;
    }
    if (cache[start][end] != -1) // dp
    {
        return cache[start][end];
    }
    int mn = 987654321;
    for (int i = start; i < end; i++)
    {
        //좌,우 분할해서 들어간 비용 합과 이번에 합치면서 들어가는 비용 계산
        //이번에 들어가는 비용 계산시 좌, 우 숫자 합을 하는데 매번 더하면 시간초과 -> 누적합으로 dp
        int sum1 = cache_sum[i];
        if (start - 1 >= 0)
        {
            sum1 -= cache_sum[start - 1];
        }

        int sum2 = cache_sum[end] - cache_sum[i];

        mn = min(mn, solve(start, i) + solve(i + 1, end) + sum1 + sum2); //쪼갠 경우의 수 중 가장 작은값
    }
    cache[start][end] = mn;
    return mn;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for (int ti = 0; ti < t; ti++)
    {
        cin >> n;
        v.clear();
        cache = vector<vector<int>>(n, vector<int>(n, -1));
        cache_sum = vector<int>(n, 0);
        for (int i = 0; i < n; i++)
        {
            int inp;
            cin >> inp;

            v.push_back(inp);
            cache_sum[i] = inp;
        }
        for (int i = 0; i < n - 1; i++) //누적합 계산
        {
            cache_sum[i + 1] += cache_sum[i];
        }
        cout << solve(0, n - 1) << endl;
    }
}