#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
}*top=NULL;

void push(int x) {
    Node* t = new Node;
    if(t == NULL) {
        cout << "Stack is full";
    } else {
        t -> data = x;
        t -> next = top;
        top = t;
    }
}

void pop() {
    if(top == NULL) {
        cout << "Stack is empty";
    } else {
        Node *t = top;
        top = top->next;
        delete t;
    }
}

void display() {
    Node* p;
    p = top;
    while(p) {
        cout << p -> data << " ";
        p = p -> next;
    }
    cout << endl;
}

int main() {
    push(5);
    push(6);
    push(7);
    pop();
    display();
}
