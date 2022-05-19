#include <iostream>
using namespace std;

int main()
{
    char s[1000000];
    int flag = 0;
    int cnt = 0;
    cin.getline(s, 1000000);
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != ' ' && !flag)
            cnt++;
        if (s[i] != ' ')
            flag = 1;
        else
            flag = 0;
    }
    cout << cnt << endl;
}