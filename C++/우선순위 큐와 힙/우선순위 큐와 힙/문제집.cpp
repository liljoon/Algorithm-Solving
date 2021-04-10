//백준 1766
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n + 1); //i풀면 다음 풀수있는 문제들
	vector<int> able(n + 1, 1); // 처음부터 i를 풀 수 있는지
	vector<int> beforesolved(n + 1, 0); //i 풀기위해 풀어야 하는 문제 수
	for (int i = 0; i < m; i++) {// 초기화
		int a, b;
		cin >> a >> b;
		able[b] = 0;
		v[a].push_back(b);
		beforesolved[b]++;
	}
	priority_queue<int, vector<int>, greater<int>> pque; //풀수잇는 que(작은거 먼저)
	for (int i = 1; i <= n; i++) {//초기에 풀수 있ㄴ는거 먼저 집어넣기
		if (able[i] == 1) {
			pque.push(i);
		}
	}
	for (int i = 0; i < n; i++) {
		if (!v[pque.top()].empty()) { //연결되어 있을 경우
			vector<int> temp(v[pque.top()]); //연결되어 잇는 벡터 임시 저장
			cout << pque.top() << " ";

			for (int i = 0; i < temp.size(); i++) {// 연결되어 있는거 하나씩 줄여주기
				beforesolved[temp[i]]--;
			}
			pque.pop();// 기존 푼 문제 제거
			for (int i = 0; i < temp.size(); i++) {//연결되어 있는거 하나씩 확인
				if (beforesolved[temp[i]] == 0) {//선수과목 다 했으면 풀수있는 큐에 집어넣기
					pque.push(temp[i]);
				}
			}
		}
		else { //연결된게 없으면 그냥 풀기
			cout << pque.top() << " ";
			pque.pop();
		}
	}
}