#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;

	int n;
	cin >> n;
	int k = 0;
	int length = 3;
	while (length < n)
	{
		length = length * 2 + k + 4;
		k++;
	}
	while (1)
	{
		int div1 = (length - (k + 3)) / 2;
		int div2 = (length - (k + 3)) / 2 + k + 3;
		if (n <= div1)
		{
			length = div1;
			k--;
		}
		else if (n > div2)
		{
			n -= div2;
			length = div1;
			k--;
		}
		else
		{
			if (n == div1 + 1)
				cout << "m" << endl;
			else
				cout << "o" << endl;
			break;
		}
	}
}
