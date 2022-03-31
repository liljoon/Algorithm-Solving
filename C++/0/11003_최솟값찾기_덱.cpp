#include <iostream>
#include <deque>
using namespace std;

deque<pair<int, int>> dque;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, l;
    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        int inp;
        cin >> inp;
        while (!dque.empty() && dque.front().second < i - l + 1) //앞 쪽에 이미 인덱스가 넘어간거 다 제거
        {
            dque.pop_front();
        }
        while (!dque.empty() && dque.back().first > inp) // 뒤쪽에 지금 들어간거보다 값이 크면 필요없으니가 다 제거
        {
            dque.pop_back();
        }
        dque.push_back({inp, i});
        cout << dque.front().first << " ";
    }
}