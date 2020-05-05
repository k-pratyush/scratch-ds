#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
} *root = NULL;

int nodeHeight(Node* p) {
    int l,r;
    l = p && p -> left ? p -> left -> height : 0;
    r = p && p -> right ? p -> right -> height : 0;
    return 1 + max(l,r);
}

int balanceFactor(Node* p) {
    int l = p && p->left ? p->left->height : 0;
    int r = p && p->right ? p->right->height : 0;
    return l - r;
}

Node* LLRotation(Node* p) {
    Node* pl = p -> left;
    Node* plr = pl -> right;
    pl -> right = p;
    p -> left = plr;
    p -> height = nodeHeight(p);
    pl -> height = nodeHeight(pl);
    if(root == p)
        root = pl;
    return pl;
}

Node* LRRotation(Node* p) {
    Node* pl = p -> left;
    Node* plr = pl -> right;
    pl -> right = plr -> left;
    p -> left = plr -> right;
    plr -> left = pl;
    plr -> right = p;
    pl -> height = nodeHeight(pl);
    p -> height = nodeHeight(p);
    plr -> height = nodeHeight(plr);
    if(root == p) {
        root = plr;
    }
    return plr;
}
Node *RLRotation(Node *p) {
    Node *pr = p->right;
    Node *prl = pr->left;
    pr->left = prl->right;
    p->right = prl->left;
    prl->right = pr;
    prl->left = p;
    pr->height = nodeHeight(pr);
    p->height = nodeHeight(p);
    prl->height = nodeHeight(prl);
    if (root == p)
        root = prl;
    return prl;
}

Node* RRRotation(Node* p) {
    Node* pr = p -> right;
    Node* prl = pr -> left;
    pr -> left = p;
    p -> right = prl;
    p -> height = nodeHeight(p);
    pr -> height = nodeHeight(pr);
    if(root == p)
        root = pr;
    return pr;
}


void inorderNodeHeight(Node* p) {
    if(p) {
        inorderNodeHeight(p -> left);
        cout << p -> height << " ";
        inorderNodeHeight(p -> right);
    }
}

Node* insertNode(Node* p, int key) {
    Node* t = NULL;
    if(!p) {
        t = new Node();
        t -> left = t -> right = NULL;
        t -> data = key;
        t -> height = 1;
        return t;
    }
    if(key < p -> data) {
        p -> left = insertNode(p -> left, key);
    }
    else if(key > p -> data) {
        p -> right = insertNode(p -> right, key);
    }
    p -> height = nodeHeight(p);
    //left imbalance because bf +2
    if (balanceFactor(p) == 2 && balanceFactor(p->left) == 1) {
        //LL rotation
        return LLRotation(p);
    }
    else if (balanceFactor(p) == 2 && balanceFactor(p->left) == -1) {
        //LR rotation
        return LRRotation(p);
    }
    //right imbalance because bf -2
    else if (balanceFactor(p) == -2 && balanceFactor(p->right) == -1) {
        //RR rotation
        return RRRotation(p);
    }
    else if (balanceFactor(p) == -2 && balanceFactor(p->right) == 1) {
        //RL rotation
        return RLRotation(p);
    }
    return p;
}

int main() {
    root = insertNode(root, 10);
    inorderNodeHeight(root);
    cout << endl;
    insertNode(root, 12);
    inorderNodeHeight(root);
    cout << endl;
    insertNode(root, 11);
    inorderNodeHeight(root);
    cout << endl;
}
