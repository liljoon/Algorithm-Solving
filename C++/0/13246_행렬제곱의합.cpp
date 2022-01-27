#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
int n;
long long b;

//행렬 제곱 반환
vector<vector<int>> matrix_multiply(vector<vector<int>> a, vector<vector<int>> b)
{
    vector<vector<int>> ret(a.size(), vector<int>(a.size(), 0));
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            for (int k = 0; k < a.size(); k++)
            {
                ret[i][j] += (a[i][k] * b[k][j]);
                ret[i][j] %= 1000;
            }
        }
    }
    return ret;
}

//행렬 덧셈, 반환x
void matrix_sum(vector<vector<int>> &a, vector<vector<int>> b)
{
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            a[i][j] += b[i][j];
            a[i][j] %= 1000;
        }
    }
}

vector<vector<int>> solve(long long n, vector<vector<int>> v)
{
    if (n == 1)
    {
        return v;
    }
    if (n % 2 == 1)
    {
        return matrix_multiply(solve(n - 1, v), v);
    }
    vector<vector<int>> t = solve(n / 2, v);
    return matrix_multiply(t, t);
}

vector<vector<int>> solve2(long long n, vector<vector<int>> v)
{
    if (n == 1)
    {
        return v;
    }
    if (n % 2 == 1)
    {
        vector<vector<int>> t = solve2(n - 1, v);
        matrix_sum(t, solve(n, v));
        return t;
    }
    vector<vector<int>> t = solve2(n / 2, v);
    vector<vector<int>> t1 = matrix_multiply(t, solve(n / 2, v));
    matrix_sum(t, t1);
    return t;
}

int main()
{
    cin >> n >> b;
    v = vector<vector<int>>(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
            v[i][j] %= 1000;
        }
    }
    vector<vector<int>> a = solve2(b, v);

    //출력
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < a.size(); j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}