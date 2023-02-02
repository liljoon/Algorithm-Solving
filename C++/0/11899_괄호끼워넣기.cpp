#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string s;
	vector<char> v;
	cin >> s;
	for (auto i : s)
	{
		v.push_back(i);
		while (v.size() >= 2 && v[v.size() - 1] == ')' && v[v.size() - 2] == '(')
		{
			v.pop_back();
			v.pop_back();
		}
	}
	cout << v.size() << "\n";
}
