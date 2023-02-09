#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int start, last;
vector<int> v;
int m,n;

bool is_okay(int len)
{
	int cnt = 0;
	for(int i=0;i<n;i++)
	{
		cnt += v[i] / len;
	}
	if (cnt >= m)
		return true;
	else
		return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int ret = -1;
	cin >> m >> n;
	v = vector<int>(n);
	for(int i=0; i < n; i++)
		cin>>v[i];
	sort(v.begin(), v.end());

	start = 1;
	last = v[n - 1];
	int mid = (start + last) / 2;
	while (start <= last)
	{

		if (is_okay(mid))
		{

			ret = max(ret, mid);
			start = mid + 1;
		}
		else
		{
			last = mid - 1;
		}
		mid = (start + last) / 2;
	}
	if (ret == -1)
		cout<<0<<"\n";
	else
		cout<<ret<<"\n";
}
