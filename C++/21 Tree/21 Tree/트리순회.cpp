//น้มุ 1991

#include<iostream>
#include<string>
using namespace std;

struct node {
	int left;
	int right;
};

node tree[30];
void preorder(int index);
void inorder(int index);
void postorder(int index);

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char temp,in;
		cin >> in;
		cin >> temp;
		tree[(int)in-65].left = (int)temp-65;
		cin >> temp;
		tree[(int)in-65].right = (int)temp-65; 
	}
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	cout << '\n';
}


void preorder(int index) {
	cout << (char)(65 + index);
	if (tree[index].left != (int)'.'-65) {
		preorder(tree[index].left);
	}
	if (tree[index].right != (int)'.'-65) {
		preorder(tree[index].right);
	}
}

void inorder (int index) {
	if (tree[index].left != (int)'.' - 65) {
		inorder(tree[index].left);
	}
	cout << (char)(65 + index);
	if (tree[index].right != (int)'.' - 65) {
		inorder(tree[index].right);
	}
}

void postorder(int index) {
	if (tree[index].left != (int)'.' - 65) {
		postorder(tree[index].left);
	}
	if (tree[index].right != (int)'.' - 65) {
		postorder(tree[index].right);
	}
	cout << (char)(65 + index);
}