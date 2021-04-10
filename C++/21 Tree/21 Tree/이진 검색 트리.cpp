// น้มุ 5639

#include<iostream>
using namespace std;

struct node {
	node* parent = NULL;
	node* left = NULL;
	node* right = NULL;
	int data = 0;
};

class tree {
public:
	tree() {
		root = NULL;
	}
	void insert(int a) {
		if (root == NULL) {
			root = new node;
			root->data = a;
		}
		else {
			node* temp = root;
			node* before = root;
			while(temp != NULL) {
				if (temp->data > a) {
					before = temp;
					temp = temp->left;
				}
				else {
					before = temp;
					temp = temp->right;
				}
			}
			if (before->data > a) {
				temp = new node;
				before->left = temp;
				temp->data = a;
				temp->parent = before;
			}
			else {
				temp = new node;
				before->right = temp;
				temp->data = a;
				temp->parent = before;
			}
		}
	}
	void print() {
		printre(root);
	}
	void printre(node* a) {
		if (a == NULL) {
			return;
		}
		printre(a->left);
		printre(a->right);
		cout << a->data << '\n';
	}

private:
	node* root;
};

int main() {
	tree t;
	int n;
	while (cin >> n) {
		t.insert(n);
	}
	t.print();
}