#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	queue<pair<int, int>> que;
	vector<int> visited(200001, 987654321);
	int n, k;
	cin >> n >> k;
	que.push(make_pair(n, 0));
	int ret = 987654321;
	int cnt = 0;
	while (!que.empty())
	{
		int place, sec;

		place = que.front().first;
		sec = que.front().second;
		que.pop();
		if (place > 200000 || place < 0 || visited[place] < sec)
			continue;
		if (sec > ret)
			break;
		if (place == k)
		{
			ret = sec;
			cnt++;
		}
		else
			visited[place] = sec;
		que.push(make_pair(place * 2, sec + 1));
		que.push(make_pair(place + 1, sec + 1));
		que.push(make_pair(place - 1, sec + 1));
	}
	cout << ret << endl
		 << cnt << endl;
}
