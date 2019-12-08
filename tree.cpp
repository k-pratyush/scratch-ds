// Pratyush Kerhalkar


#include<iostream>
#include<string.h>

using namespace std;

struct node {
    int info;
    node* left;
    node* right;
    node(int info) {
    	this->info = info;
    	left = right = NULL;
    }
};

//Insert a node in an empty position
node* insert(node* root, int item, string path) {
    int i;
    node* curr, *prev;
    node* temp = new node(item);
    if(root == NULL)
        return temp;

    prev = NULL;
    curr = root;

    for(i = 0; i < path.length() && curr != NULL; i++) {
        prev = curr;
        if(path[i] == 'L')
            curr = curr->left;
        else
            curr = curr->right;
    }

    if(curr != NULL || i != path.length()) {
        cout << "Insertion not possible" << "\n";
        delete temp;
        return root;
    }

    if(path[i-1] == 'L')
        prev->left = temp;
    prev->right = temp;
}


//Search an element in the tree
bool search(node* root, int item) {
    if(root == NULL)
        return false;

    if(root->info == item)
        return true;

    bool s1 = search(root->left, item);    
    bool s2 = search(root->right, item);
    if(s1 || s2)
        return true;
    
}

//Copy a tree
node* copy(node* root) {
    if(root==NULL)
        return NULL;

    node* temp = new node(NULL);
    temp->info = root->info;
    temp->left = copy(root->left);
    temp->right = copy(root->right);

    return temp;
}


//Find the height of the tree
int height(node* root) {
    if(root == NULL)
        return 0;
    return(1 + max(height(root->left), height(root->right)));
}

static int node_counter = 0;
int countNodes(node* node) {

    if(node != NULL) {
        countNodes(node->left);
        node_counter++;
        countNodes(node->right);
    }
    return node_counter;
}


static int leaf_counter = 0;
int countLeaf(node* node) {

    if(node != NULL) {
        countLeaf(node->left);
        if(node->left == NULL && node->right == NULL)
            leaf_counter++;
        countLeaf(node->right);
    }
    return leaf_counter;
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
    node* root = new node(4);
    
    root->left = new node(3);
    root->right = new node(2);
    root->left->left = new node(1);
    
    insert(root, 5, "LLR");

    inOrder(root);
    cout << "\n";

    node* temp = copy(root);

    cout << search(root, 5) << "\n";
    cout << search(root, 4) << "\n";
    cout << search(root, 10) << "\n";
    cout << "\n";

    inOrder(temp);
    cout << "\n";

    cout << height(root) << "\n";
    cout << countNodes(root) << "\n";
    cout << countLeaf(root) << "\n";
}
