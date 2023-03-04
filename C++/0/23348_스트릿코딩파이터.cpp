#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int A, B, C;

	cin >> A >> B >> C;
	int n;
	cin >> n;
	vector<int> score(n, 0);
	for (int i = 0; i < 3 * n; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		score[i / 3] += a * A + b * B + c * C;
	}
	sort(score.begin(), score.end());
	cout << score[n - 1] << "\n";
}
