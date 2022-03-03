#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long T;
	cin >> T;
	for (long long ti = 0; ti < T; ti++)
	{
		bool found = false;
		long long n, m, s, d;
		cin >> n >> m >> s >> d;
		s--;
		d--;
		vector<vector<pair<long long, long long>>> adj(n, vector<pair<long long, long long>>());
		vector<long long> p;
		vector<long long> visited(n, 0);
		for (long long i = 0; i < m; i++)
		{
			long long a, b, c;
			cin >> a >> b >> c;
			adj[a - 1].push_back(make_pair(b - 1, c));
			adj[b - 1].push_back(make_pair(a - 1, c));
		}
		for (long long i = 0; i < n; i++) {
			long long a;
			cin >> a;
			p.push_back(a);
		}
		for (long long i = 0; i < n; i++)
		{
			sort(adj[i].begin(), adj[i].end());
		}//각 인접행렬 순서로 정렬
		priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pque;
		pque.push(make_pair(0, s));
		while (!pque.empty())
		{
			long long time = pque.top().first;
			long long idx = pque.top().second;
			pque.pop();
			if (visited[idx]) {
				continue;
			}
			//cout << idx<<" " << time << endl;
			visited[idx] = 1;
			if (idx == d)
			{
				found = true;
				cout << time << "\n";
				break;
			}
			for (long long i = 0; i < adj[idx].size(); i++)
			{
				long long next = adj[idx][i].first;
				if (visited[next]) {
					continue;
				}

				if (next == d) //다음이 도착시 신호 계산 X
				{
					pque.push(make_pair(time + adj[idx][i].second, next));
					continue;
				}
				//신호계산 시작
				long long order = -1;
				long long adj_num = adj[next].size();
				for (long long j = 0; j < adj[next].size(); j++)
				{
					if (idx == adj[next][j].first) {
						order = j;
						break;
					}
				} //교차로 순서 찾기
				long long temp_time = time + adj[idx][i].second; //교차로 통과순간 시간
				long long time_cal = temp_time % (p[next] * adj_num); //신호 순서 계산용 변수
				long long all_p = p[next] * adj_num; // 전체 신호 주기
				if ((time_cal >= p[next] * order) && (time_cal < p[next] * (order + 1))) //통과 가능 시간일 경우
				{
					pque.push(make_pair(time + adj[idx][i].second, next));
				}
				else { //통과 불가
					long long temp = p[next] * order;
					while (temp < temp_time) {  //가장 처음 오는 신호 주기 계산
						temp += all_p;
					}
					pque.push(make_pair(temp, next));
				}
			}
		}
		if (!found)
		{
			cout << -1 << "\n";
		}
	}
}