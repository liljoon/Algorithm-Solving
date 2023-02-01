#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct s
{
	string name;
	int a;
	int b;
	int c;
};

bool compare(s s1, s s2)
{
	if (s1.a != s2.a)
		return s1.a > s2.a;
	if (s1.b != s2.b)
		return s1.b < s2.b;
	if (s1.c != s2.c)
		return s1.c > s2.c;
	return s1.name.compare(s2.name) < 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<s> v(n);
	for (int i = 0; i < n; i++)
	{
		string name;
		int a, b, c;
		cin >> name >> a >> b >> c;
		v[i].name = name;
		v[i].a = a;
		v[i].b = b;
		v[i].c = c;
	}
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < n; i++)
	{
		cout << v[i].name << '\n';
	}
}
