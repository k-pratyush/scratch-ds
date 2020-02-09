#include<iostream>
#include<vector>

using namespace std;

struct Node {
	int data;
	Node* next;
}*HEAD;


void displayCircularLinkedList(Node* p) {
	static int flag = 0;

	if(p != HEAD || flag == 0) {
		flag = 1;
		cout << p -> data << " ";
		displayCircularLinkedList(p -> next);
	} 
	flag = 0;
}


void insertNode(Node* x, int data, int pos) {
	Node* t = new Node;
	t -> data = data;
	Node* p = HEAD;
	if(pos == 0) {
		t -> next = HEAD;
		while(p->next != HEAD) {
			p = p -> next;
		}
		p -> next = t;
	} else {
		for(int i = 0; i < pos - 1; i++)
			p = p -> next;
		t -> next = p -> next;
		p -> next = t;
	}
}

void deleteNode(Node* p, int pos) {
	if(pos == 1) {
		p = HEAD;
		while(p -> next != HEAD)
			p = p -> next;
		p -> next = HEAD -> next;
		delete HEAD;
		HEAD = p -> next;
	} else {
		for(int i = 0; i < pos - 2; i++)
			p = p -> next;
		Node* q = p -> next;
		p -> next = q -> next;
		delete q;
	}
}

void createCircularLinkedList(vector<int> A) {
	Node *t, *last;
	HEAD = new Node;
	HEAD -> data = A[0];
	HEAD -> next = HEAD;
	last = HEAD;
	for(int i = 1; i < A.size(); i++) {
		t = new Node;
		t -> data = A[i];
		t -> next = last -> next;
		last -> next = t;
		last = t;
	}
}

int main() {
	vector<int> A = {1,4,5,6};
	createCircularLinkedList(A);
	insertNode(HEAD, 3, 1);
	insertNode(HEAD, 0, 0);
	displayCircularLinkedList(HEAD);
	cout << endl;
	deleteNode(HEAD, 1);
	deleteNode(HEAD, 2);
	displayCircularLinkedList(HEAD);
}