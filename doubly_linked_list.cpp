#include<iostream>
#include<vector>

using namespace std;

struct Node {
	Node* prev;
	int data;
	Node* next;
}*first = NULL;



void displayLinkedList(Node *p) {
	while(p) {
		cout << p -> data << " ";
		p = p -> next;
	}
}

int lengthOfList(Node *p) {
	int len = 0;
	while(p) {
		len++;
		p = p -> next;
	}
	return len;
}

void insertNode(Node *p, int data, int pos) {
	Node* t = new Node;
	t -> data = data;
	if(pos == 0) {
		t -> prev = NULL;
		t -> next = first;
		first -> prev = t;
		first = t;
	} else {
		Node* x = p;
		for(int i = 0; i < pos -1; i++)
			x = x -> next;
		t -> next = x -> next;
		t -> prev = x;
		if(p -> next)
			x -> next -> prev = t;
		x -> next = t;
	}
}

void deleteNode(int pos) {
	Node* p = first;
	if(pos == 1) {
		first = first->next;
		delete p;
		if(first)
			first -> prev = NULL;
	} else {
		for(int i = 0; i < pos - 1; i++)
			p = p -> next;
		p -> prev -> next = p -> next;
		if(p -> next)
			p -> next -> prev = p -> prev;
		delete p;
	}
}

void reverseDoublyLinkedList() {
	Node* p = first;
	Node *temp;
	while(p) {
		temp = p -> next;
		p -> next = p -> prev;
		p -> prev = temp;
		p = p -> prev;
		if(p && p -> next == NULL)
			first = p;
	}
}

void createDoublyLinkedList(vector<int> A) {
	Node* t, *last;
	first = new Node;
	first -> data = A[0];
	first -> prev = first -> next = NULL;
	last = first;

	for(int i = 1; i < A.size(); i++) {
		t = new Node;
		t -> data = A[i];
		t -> next = last -> next;
		t -> prev = last;
		last -> next = t;
		last = t;
	}
}

int main() {
	vector<int> A = {1,4,12,43,5};
	createDoublyLinkedList(A);
	reverseDoublyLinkedList();
	displayLinkedList(first);
}