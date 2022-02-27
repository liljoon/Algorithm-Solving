#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> map;
vector<vector<int>> visited;
struct node {
	int y;
	int x;
	int price;
	node(int y, int x, int price)
	{
		this->y = y;
		this->x = x;
		this->price = price;
	}
};

struct compare {
	bool operator()(const node& a, const node& b)
	{
		return a.price > b.price;
	}
};

int main() {
	int n;
	int cnt = 0;
	do {
		cnt++;
		cin >> n;
		map = vector<vector<int>>(n, vector<int>(n, 0));
		visited = vector<vector<int>>(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		priority_queue<node,vector<node>,compare> pque;
		pque.push(node(0, 0, 0));
		while(!pque.empty())
		{
			node temp = pque.top();
			pque.pop();
			if (temp.x >= n || temp.x < 0 || temp.y >= n || temp.y < 0)
			{
				continue;
			}
			if (visited[temp.y][temp.x]) {
				continue;
			}
			if (temp.x == n - 1 && temp.y == n - 1)
			{
				cout <<"Problem "<<cnt<<": " << temp.price + map[temp.y][temp.x] << endl;
				break;
			}
			visited[temp.y][temp.x] = 1;
			pque.push(node(temp.y+1,temp.x ,temp.price+ map[temp.y][temp.x]));
			pque.push(node(temp.y, temp.x+1, temp.price + map[temp.y][temp.x]));
			pque.push(node(temp.y-1, temp.x, temp.price + map[temp.y][temp.x]));
			pque.push(node(temp.y, temp.x-1, temp.price + map[temp.y][temp.x]));
		}

	} while(n!=0);

}
