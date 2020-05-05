#include<iostream>
#include<vector>
#include<stack>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
} *root = NULL;

void inorder(Node* p) {
    if(p) {
        inorder(p -> left);
        cout << p -> data << " ";
        inorder(p -> right);
    }
}

int height(Node* p) {
    if(p)
        return 1 + max(height(root -> left), height(root -> right));
    return 0;
}


void insert(int value) {
    if(!root) {
        root = new Node;
        root -> left = root -> right = NULL;
        root -> data = value;
    } else {
        Node *it = root;
        Node* temp = it;
        while(it) {
            temp = it;
            if(value < it -> data)
                it = it -> left;
            else if(value > it -> data)
                it = it -> right;
            else
                return;
        }
        Node *p = new Node;
        p->left = p->right = NULL;
        p->data = value;
        if(temp -> data > value)
            temp -> left = p;
        else
            temp -> right = p;
    }
}

Node* insertRecursive(Node* p, int value) {
    Node* t = NULL;
    if(!p) {
        t = new Node;
        t -> data = value;
        t -> left = t -> right = NULL;
        return t;
    }
    if(value < p -> data) {
        p -> left = insertRecursive(p -> left, value);
    }
    if(value > p -> data) {
        p -> right = insertRecursive(p -> right, value);
    }
    return p;
}

Node* InPred(Node* p) {
    while(p -> right) {
        p = p -> right;
    }
    return p;
}

Node* InPost(Node* p) {
    while(p -> left) {
        p = p -> left;
    }
    return p;
}


Node* deleteNode(Node* p, int value) {
    Node* q;
    if(!p) {
        return NULL;
    }
    if(!p -> left && !p -> right) {
        if(p == root)
            root = NULL;
        delete p;
        return NULL;
    }
    if(value < p -> data)
        p -> left = deleteNode(p -> left, value);
    else if(value > p -> data)
        p -> right = deleteNode(p -> right, value);
    else {
        if(height(p -> left) > height(p -> right)) {
            q = InPred(p -> left);
            p -> data = q -> data;
            p -> left = deleteNode(p -> left, q -> data);
        } else {
            q = InPost(p -> right);
            p->data = q->data;
            p->right = deleteNode(p->right, q->data);
        }
    }
    return p;
}


void search(int value) {
    if(!root) {
        cout << "Empty tree" << endl;
        return;
    } else {
        Node* it = root;
        while(it) {
            if(value == it -> data) {
                cout << "Found at " << it << endl;
                return;
            }
            if(value > it -> data) {
                it = it -> right;
            } else {
                it = it -> left;
            }
        }
        cout << "Value not found" << endl;
    }
}

void createPre(vector<int> arr) {
    stack<Node*> st;
    Node* p;
    int i = 0;
    root = new Node;
    root -> data = arr[i++];
    root -> left = root -> right = NULL;
    p = root;
    while(i < arr.size()) {
        if(arr[i] < p -> data) {
            Node* t = new Node;
            t -> data = arr[i];
            t -> left = t -> right = NULL;
            p -> left = t;
            st.push(p);
            p = t;
            i++;
        } else {
            if(arr[i] > p -> data && !st.empty() && arr[i] < st.top() -> data) {
                Node* t = new Node;
                t -> data = arr[i];
                t -> left = t -> right = NULL;
                p -> right = t;
                p = t;
                i++;
            } else if(!st.empty()) {
                p = st.top();
                st.pop();
            }
        }
    }
}

int main() {
    // root = insertRecursive(root, 5);
    // insertRecursive(root, 4);
    // insertRecursive(root, 1);
    // inorder(root);
    // deleteNode(root, 1);
    // insertRecursive(root, 3);
    // inorder(root);
    // cout << endl;
    // search(4);
    // search(10);
    vector<int> arr = {5,4,1,3};
    createPre(arr);
    inorder(root);
}
