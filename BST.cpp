// Pratyush Kerhalkar


#include<iostream>
#include<string.h>
#include<stack>

using namespace std;

struct node {
	int info;
	node* left, *right;
	node(int info) {
		this->info = info;
		left = right = NULL;
	}
};

//node insertion in BST
node* insert(node* root, int info) {
	node* curr, *prev;
	node* temp = new node(info);

	if(root == NULL)
		return temp;

	curr = root;
	prev = NULL;

	while(curr != NULL) {
		prev = curr;

		if(curr->info == info) {
			cout << "item already exists" << "\n";
			delete temp;
			return root;
		}
		else if(info < curr -> info)
			curr = curr->left;
		else
			curr = curr->right;
	}
	if(info < prev->info)
		prev->left = temp;
	else
		prev->right = temp;

	return root;
}

//Search an element in the tree
void search(node* root, int item) {
	node* temp = root;

	while(temp != NULL) {
		if(item == temp->info) {
			cout << item << " found" << "\n";
			return;
		}
		else if(item < temp->info)
			temp=temp->left;
		else
			temp=temp->right;
	}
	cout << item << " not found" << "\n";
}

//Delete a node from tree
node* deleteNode(node* root, int item) {
	if(root == NULL) {
		cout << "tree is empty" << "\n";
		return root;
	}
	if(item < root->info) {
		root->left = deleteNode(root->left, item);
	}
	else if(item > root->info) {
		root->right = deleteNode(root->right, item);
	}
	else {
		if(root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		else if(root->left == NULL) {
			node* temp = root;
			root = root->right;
			delete temp;
		}

		else if(root->right == NULL) {
			node* temp = root;
			root = root->left;
			delete temp;
		}
		else {
			node* temp = minElement(root->right);
			root->info = temp->info;
			root->right = deleteNode(root->right, temp->info);
		}
	}
	return root;
}

//Find the maximum element from the tree
node* maxElement(node* root) {
	node* temp = root;
	while(temp->right != NULL) {
		temp = temp->right;
	}
	return temp;
}

//Find the minimum element from the tree
node* minElement(node* root) {
	node* temp = root;
	while(temp->left != NULL) {
		temp = temp->left;
	}
	return temp;
}

//Find the height of the tree
int height(node* root) {
	if(root == NULL)
		return 0;
	return (1 + max(height(root->left), height(root->right)));
}

//Tree traversal
void preOrder(node* node) {
	if(node == NULL)
		return;

	cout << node->info << " ";
	preOrder(node->left);
	preOrder(node->right);
}

void inOrder(node* node) {
	if(node == NULL)
		return;

	inOrder(node->left);
	cout << node->info << " ";
	inOrder(node->right);
}

void postOrder(node* node) {
	if(node == NULL)
		return;

	postOrder(node->right);
	postOrder(node->left);
	cout << node->info << " ";
}

int main() {
	node* root = new node(6);
	insert(root, 5);
	insert(root, 3);
	insert(root, 7);
	insert(root, 8);
	insert(root, 99);
	inOrder(root);
	cout << "\n";

	search(root, 3);
	search(root, 19);
	deleteNode(root, 5);
	cout << "\n";
	search(root, 5);

	strNode* t = createPostfixTree("ab+ef*g*-");
	//inOrder(t);
}