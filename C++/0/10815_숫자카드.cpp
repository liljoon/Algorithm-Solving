#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> card, find_list;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    card = vector<int>(N);
    for (int i = 0; i < N; i++)
    {
        cin >> card[i];
    }

    cin >> M;
    find_list = vector<int>(M);
    for (int i = 0; i < M; i++)
    {
        cin >> find_list[i];
    }

    sort(card.begin(), card.end());

    for (int i = 0; i < M; i++)
    {
        if (binary_search(card.begin(), card.end(), find_list[i]))
        {
            cout << 1 << " ";
        }
        else
        {
            cout << 0 << " ";
        }
    }
}