#include <iostream>

using namespace std;

struct Node {
	int data;
	Node* next;
}*first = NULL, *second = NULL, *third = NULL;

void displayLinkedList(Node* p) {
	while(p != NULL) {
		cout << p -> data << " ";
		p = p->next;
	}
}

void displayLinkedListRecursive(Node* p) {
	if(p != NULL) {
		cout << p->data << " ";
		displayLinkedListRecursive(p->next);
	}
}

int countLinkedList(Node* p) {
	int n = 0;
	while(p != NULL) {
		n++;
		p = p->next;
	}
	return n;
}

int sumLinkedList(Node* p) {
	int sum = 0;
	while(p) {
		sum += p->data;
		p = p->next;
	}
	return sum;
}

int maxLinkedList(Node* p) {
	int max = p->data;

	while(p) {
		if(p->data > max) {
			max = p->data;
		}
		p = p->next;
	}
	return max;
}

void searchLinkedList(Node* p, int key) {
	while(p) {
		if(p->data == key) {
			cout << "key found at " << p;
			break;
		}
		p = p->next;
	}
	if(p == NULL) {
		cout << "Not found";
	}
}

Node* searchLinkedListFast(Node* p, int key) {
	Node* q = NULL;

	while(p) {
		if(key == p->data) {
			q->next = p->next;
			p->next = first;
			first = p;
		}
		q = p;
		p = p->next;
	}
	return p;
}

void insertNode(int value, int pos) {
	Node *t, *p;
	if(pos == 0) {
		t = new Node;
		t -> data = value;
		t -> next = first;
		first = t;
	} else {
		p = first;
		for(int i = 0; i < pos -1; i++) {
			p = p -> next;
		}
		if(p) {
			t = new Node;
			t -> data = value;
			t -> next = p -> next;
			p -> next = t;
		}
	}
}

void insertInSorted(int value) {
	Node *p = first;
	Node *q = NULL;
	if(value < first -> data) {
		Node* t = new Node;
		t -> data = value;
		t -> next = first;
		first = t;
	} else {
		while(p && p -> data < value) {
			q = p;
			p = p -> next;
		}
		Node* t = new Node;
		t -> data = value;
		t -> next = q -> next;
		q -> next = t;
	}
}

void deleteNode(int pos) {
	Node* p = first;
	if(pos == 1) {
		first = p -> next;
		delete p;
	} else {
		Node* q = NULL;
		for(int i = 0; i < pos - 1; i++) {
			q = p;
			p = p -> next;
		}
		q -> next = p -> next;
		delete p;
	}
}

bool isSorted(Node* p) {
	int n = p -> data;
	while(p) {
		if(p -> data < n) {
			return false;
		}
		n = p -> data;
		p = p -> next;
	}
	return true;
}

void deleteDuplicates(Node* p) {
	Node* q = p;
	p = p -> next;
	while(p) {
		if(p -> data == q -> data) {
			q -> next = p -> next;
			delete p;
			p = q;
		}
		q = p;
		p = p -> next;
	}
}

void reverseLinkedList(Node* p) {
	Node *q = NULL, *r = NULL;
	while(p) {
		r = q;
		q = p;
		p = p -> next;
		q ->next = r;
	}
	first = q;
}

void reverseLinkedListRecursive(Node* q, Node* p) {
	if(p != NULL) {
		reverseLinkedListRecursive(p, p->next);
		p -> next = q;
	} else {
		first = q;
	}
}

void concatinateLinkedList(Node* p, Node* q) {
	Node *r = p;
	while(r -> next != NULL) {
		r = r -> next;
	}
	r -> next = q;
}

Node* Merge2SortedLinkedList(Node* p, Node* q) {
	Node *third, *last;
	if(first -> data < second -> data) {
		third = last = first;
		first = first -> next;
		last -> next = NULL;
	} else {
		third = last = second;
		second = second -> next;
		last -> next = NULL;
	}
	while(first && second) {
		if(first -> data < second -> data) {
			last -> next = first;
			last = first;
			first = first -> next;
			last -> next = NULL;
		} else {
			last -> next = second;
			last = second;
			second = second -> next;
			last -> next = NULL;
		}
	}
	if(first) {
		last -> next = first;
	} else if(second) {
		last -> next = second;
	}
	return third;
}

bool checkLoop(Node* f) {
	Node *p, *q;
	p = q = f;
	do {
		p = p -> next;
		q = q -> next;
		q = q != NULL? q -> next : NULL;
	} while(p && q && p != q);
	return (p == q);
}

void createLinkedList(int A[], int n) {
	Node* t, *last;
	first = new Node;
	first -> data = A[0];
	first -> next = NULL;
	last = first;

	for(int i = 1; i < n; i++) {
		t = new Node;
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}


void createLinkedList2(int A[], int n) {
	Node* t, *last;
	second = new Node;
	second -> data = A[0];
	second -> next = NULL;
	last = second;

	for(int i = 1; i < n; i++) {
		t = new Node;
		t->data = A[i];
		t->next = NULL;
		last->next = t;
		last = t;
	}
}

int main() {
	Node *t1, *t2;
	int A[] = {1, 4, 10, 14, 15};
	createLinkedList(A, 5);
	t1 = first -> next -> next;
	t2 = first -> next -> next -> next -> next;
	t2 -> next = t1;
	cout << checkLoop(first);
}
