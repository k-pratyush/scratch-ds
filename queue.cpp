#include<iostream>

using namespace std;

class Node {
	int data;
	Node* next;
public:
	void insert(int x);
	void remove();
	void display();
} *front=NULL, *rear=NULL;


void Node::insert(int x) {
	Node*t = new Node;
	if(!t) {
		cout << "Queue is full";
	} else {
		t -> data = x;
		t -> next = NULL;
		if(!front) {
			front = rear = t;
		} else {
			rear -> next = t;
			rear = t;
		}
	}
}

void Node::remove() {
	if(!front) {
		cout << "Queue is empty";
	} else {
		Node* p = front;
		if(front -> next) {
			front = front -> next;
		} else {
			front = NULL;
		}
		delete p;
	}
}

void Node::display() {
	if(front) {
		cout << front -> data;
	} else {
		cout << "empty";
	}
}

int main() {
	Node p;
	p.insert(1);
	p.insert(2);
	p.remove();
	p.insert(3);
	p.insert(4);
	p.insert(5);
	p.remove();
	p.display();
}