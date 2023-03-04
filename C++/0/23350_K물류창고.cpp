#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
using namespace std;

int n, m;
vector<int> box_cnt;
stack<pair<int, int>> done;
deque<pair<int, int>> que;
int ret = 0;

int can_priority(int p)
{
	for (int i = m; i >= 1; i--)
	{
		if (p >= i)
			return 1;
		if (box_cnt[i] > 0)
			return 0;
	}
	return 0;
}

void poppush(int priority, int weight)
{
	while (!done.empty())
	{
		if (priority != done.top().first)
			break;
		if (done.top().second >= weight)
			break;
		int p = done.top().first;
		int w = done.top().second;
		done.pop();
		ret += w;
		box_cnt[p]++;
		que.push_front(make_pair(p, w));
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	box_cnt = vector<int>(m + 1, 0);
	for (int i = 0; i < n; i++)
	{
		int p, w;
		cin >> p >> w;
		box_cnt[p]++;
		que.push_back(make_pair(p, w));
	}

	while (!que.empty())
	{
		int p = que.front().first;
		int w = que.front().second;
		que.pop_front();
		if (!can_priority(p))
		{
			ret += w;
			que.push_back(make_pair(p, w));
			continue;
		}
		if (done.size() == 0)
		{
			ret += w;
			done.push(make_pair(p, w));
			box_cnt[p]--;
			continue;
		}
		poppush(p, w);
		done.push(make_pair(p, w));
		ret += w;
		box_cnt[p]--;
	}
	cout << ret << "\n";
}
