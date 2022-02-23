#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<string> v;
vector<vector<int>> cache;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    cache = vector<vector<int>>(K, vector<int>(26, 0)); // cache[a][b] : a열에 있는 b번째 알파벳(a:0)이 이어진 수
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    for (int i = 0; i < N; i++)
    {
        int mx = 0;
        for (int j = 0; j < K; j++)
        {
            cache[j][int(v[i][j] - 97)] += 1; // char형 int로 변환 시 들어올 데이터 값에 유의하여 빼기
            mx = max(mx, cache[j][int(v[i][j] - 97)]);
        }
        for (int j = 0; j < K; j++)
        {
            cache[j][int(v[i][j] - 97)] = mx;
        }
    }
    int ret = 0;
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            ret = max(ret, cache[i][j]);
        }
    }
    cout << N - ret << endl;
}