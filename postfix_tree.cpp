// Pratyush Kerhalkar


#include<iostream>
#include<string.h>
#include<stack>

using namespace std;

struct node {
	char info;
	node* left, *right;
	node(char info) {
		this->info = info;
		left = right = NULL;
	}
};

bool isOperator(char c) {
	if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
		return true;
	return false;
}

//Create a binary tree for given postfix expression
node* createPostfixTree(string postfix) {
	node *t, *t1, *t2;
	stack<node*> s;
	
	for(int i = 0; i < postfix.length(); i++) {
		if(!isOperator(postfix[i])) {
			node* t = new node(postfix[i]);
			s.push(t);
		}
		else {
			node* t = new node(postfix[i]);
			t1 = s.top();
			s.pop();
			t2 = s.top();
			s.pop();

			t->left = t2;
			t->right = t1;

			s.push(t);
		}
	}
	t = s.top();
	s.pop();
	return t;
}

void inOrder(node* root) {
	if(root == NULL)
		return;
	inOrder(root->left);
	cout << root->info << " ";
	inOrder(root->right);
}

int main() {

	node* t = createPostfixTree("ab+ef*g*-");
	inOrder(t);

}