//���� 1766
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
	vector<vector<int>> v(n + 1); //iǮ�� ���� Ǯ���ִ� ������
	vector<int> able(n + 1, 1); // ó������ i�� Ǯ �� �ִ���
	vector<int> beforesolved(n + 1, 0); //i Ǯ������ Ǯ��� �ϴ� ���� ��
	for (int i = 0; i < m; i++) {// �ʱ�ȭ
		int a, b;
		cin >> a >> b;
		able[b] = 0;
		v[a].push_back(b);
		beforesolved[b]++;
	}
	priority_queue<int, vector<int>, greater<int>> pque; //Ǯ���մ� que(������ ����)
	for (int i = 1; i <= n; i++) {//�ʱ⿡ Ǯ�� �֤��°� ���� ����ֱ�
		if (able[i] == 1) {
			pque.push(i);
		}
	}
	for (int i = 0; i < n; i++) {
		if (!v[pque.top()].empty()) { //����Ǿ� ���� ���
			vector<int> temp(v[pque.top()]); //����Ǿ� �մ� ���� �ӽ� ����
			cout << pque.top() << " ";

			for (int i = 0; i < temp.size(); i++) {// ����Ǿ� �ִ°� �ϳ��� �ٿ��ֱ�
				beforesolved[temp[i]]--;
			}
			pque.pop();// ���� Ǭ ���� ����
			for (int i = 0; i < temp.size(); i++) {//����Ǿ� �ִ°� �ϳ��� Ȯ��
				if (beforesolved[temp[i]] == 0) {//�������� �� ������ Ǯ���ִ� ť�� ����ֱ�
					pque.push(temp[i]);
				}
			}
		}
		else { //����Ȱ� ������ �׳� Ǯ��
			cout << pque.top() << " ";
			pque.pop();
		}
	}
}