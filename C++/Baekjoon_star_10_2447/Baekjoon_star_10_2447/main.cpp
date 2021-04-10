#include<iostream>
using namespace std;

void solve(int y, int x, int n);
char star[3000][3000];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
           star[i][j]=' ';
        }
    }
    solve(0, 0, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << star[i][j];
        }
        cout << endl;
    }
}

void solve(int y, int x, int n)
{
    if (n == 1)
    {
        star[y][x] = '*';
        return;
    }

    int div = n / 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1) {
                continue;
            }
            else {
                solve(y + (i * div), x + (j * div), div);
            }
        }
    }

}
