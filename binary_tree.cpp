#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
#include<vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
} *root = NULL;

void inorder(Node* root) {
    if(root) {
        inorder(root -> left);
        cout << root -> data << " ";
        inorder(root -> right);
    }
}

void inorderIter(Node* root) {
    if(!root)
        return;
    stack<Node*> st;
    while(root || !st.empty()) {
        if(root) {
            st.push(root);
            root = root -> left;
        } else {
            root = st.top();
            st.pop();
            cout << root -> data << " ";
            root = root -> right;
        }
    }
}

void preorder(Node* root) {
    if(root) {
        cout << root -> data << " ";
        preorder(root -> left);
        preorder(root -> right);
    }
}


void preorderIter(Node* root) {
    if(!root)
        return;
    stack<Node*> st;
    while(root || !st.empty()) {
        if(root) {
            cout << root -> data << " ";
            st.push(root);
            root = root -> left;
        } else {
            root = st.top();
            st.pop();
            root = root -> right;
        }
    }
    
}

void postorder(Node* root) {
    if(root) {
        postorder(root -> left);
        postorder(root -> right);
        cout << root -> data << " ";
    }
}


void levelorder(Node* root) {
    if(root == NULL) {
        cout << "Empty tree" << endl;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* p = q.front();
        q.pop();
        cout << p -> data << " ";
        if(p -> left) {
            q.push(p -> left);
        }
        if(p -> right) {
            q.push(p -> right);
        }
    }
}

void createTree() {
    queue<Node*> q;
    Node* p, *t;
    int x;
    cout << "Enter data for root node: " << endl;
    cin >> x;
    root = new Node;
    root -> data = x;
    root -> left = root -> right = NULL;
    q.push(root);
    while(!q.empty()) {
        p = q.front();
        q.pop();
        cout << "Enter left child of " << p -> data << endl;
        cin >> x;
        if(x != -1) {
            t = new Node;
            t -> data = x;
            t -> left = t -> right = NULL;
            p -> left = t;
            q.push(t);
        }
        cout << "Enter right child  " << p -> data << endl;
        cin >> x;
        if(x != -1) {
            t = new Node;
            t -> data = x;
            t -> left = t -> right = NULL;
            p -> right = t;
            q.push(t);
        }
    }
}


int height(Node* root) {
    if(root)
        return 1 + max(height(root -> left), height(root -> right));
    return 0;
}

void diagonal(Node* root, int ht, vector<int> &arr) {
    if(root) {
        arr[ht] +=  root -> data;
        diagonal(root -> right, ht, arr);
        diagonal(root -> left, ht + 1, arr);
    }
}

int main() {
    createTree();
    vector<int> arr(height(root), 0);
    diagonal(root, 0, arr);
    for(int i : arr)
        cout << i << " ";
}
