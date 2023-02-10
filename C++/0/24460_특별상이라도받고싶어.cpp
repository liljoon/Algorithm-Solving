#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;

int second_small(int arr[])
{
	sort(arr, arr + 4);
	return arr[1];
}

int solve(int y, int x, int n)
{
	if (n == 1)
		return v[y][x];
	int arr[] = {solve(y, x, n / 2), solve(y + n / 2, x, n / 2), solve(y, x + n / 2, n / 2), solve(y + n / 2, x + n / 2, n / 2)};
	return second_small(arr);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	v = vector<vector<int>>(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cin >> v[i][j];
	}
	cout << solve(0, 0, n) << "\n";
}
