#include<iostream>

using namespace std;

struct Queue {
	int size;
	int front;
	int rear;
	int* Q;
};

void insert(Queue* q, int x) {
	if(q -> rear == q ->size - 1) {
		cout << "Queue is full";
	} else {
		q -> rear++;
		q -> Q[q -> rear] = x;
	}
}

void remove(Queue* q) {
	if(q -> front == q -> rear) {
		cout << "Queue is empty";
	} else {
		q -> front++;
	}
}

void front(Queue* q) {
	if(q -> front != -1) {
		cout << q -> Q[++q->front] << " ";
	} else {
		cout << "Queue is empty";
	}
}

int main() {
	
	//init
	Queue q;
	q.size = 100;
	q.Q = new int[q.size];
	q.front = q.rear = -1;
	insert(&q, 1);
	insert(&q, 2);
	remove(&q);
	insert(&q, 3);
	insert(&q, 4);
	remove(&q);
	front(&q);
}