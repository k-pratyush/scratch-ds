#include<iostream>

using namespace std;

struct Element {
	int i;
	int j;
	int x;
};

struct Sparse {
	int m;
	int n;
	int num;
	struct Element* e;
};

void createSparseMatrix(struct Sparse* s) {
	cout << "Enter dimensions: ";
	cin >> s->m >> s->n;
	cout << "Number of non zero elements: ";
	cin >> s-> num;
	s->e = new Element[s->num];
	cout << "Enter non zero elements: ";
	for(int i = 0; i < s->num; i++) {
		cin >> s->e[i].i;
		cin >> s->e[i].j;
		cin >> s->e[i].x;
	}
}

void displaySparseMatrix(struct Sparse s) {
	int k = 0;
	for(int i = 0; i < s.m; i++) {
		for(int j = 0; j < s.n; j++) {
			if(i == s.e[k].i && j == s.e[k].j) {
				cout << s.e[k++].x << " ";
			} else {
				cout << "0 ";
			}
		}
		cout << "\n";
	}
}

struct Sparse* addSparseMatrix(struct Sparse* s1, struct Sparse* s2) {
	Sparse* sum;
	sum = new Sparse;
	sum -> e = new Element[s1->num + s2->num];
	int i,j,k;
	i=j=k=0;

	while(i < s1->num && j < s2->num) {
		if(s1->e[i].i < s2->e[j].i) {
			sum->e[k++] = s1->e[i++];
		} else if(s1->e[i].i > s2->e[j].i) {
			sum->e[k++] = s2->e[j++];
		} else {
			if(s1->e[i].j < s2->e[i].j) {
				sum->e[k++] = s1->e[i++];
			} else if(s1->e[i].j > s2->e[i].j) {
				sum->e[k++] = s2->e[j++];
			} else {
				sum->e[k] = s1->e[i];
				sum->e[k++].x = s1->e[i++].x + s2->e[j++].x;
			}
		}
	}
	for(;i < s1->num; i++) {
		sum->e[k++] = s1->e[i];
	}
	for(;j < s2->num; j++) {
		sum->e[k++] = s2->e[j];
	}
	sum->m = s1->m;
	sum->n = s1->n;
	sum->num = k;

	return sum;
}

int main() {
	Sparse s1, s2, *s3;
	createSparseMatrix(&s1);
	displaySparseMatrix(s1);
	createSparseMatrix(&s2);
	displaySparseMatrix(s2);
	s3 = addSparseMatrix(&s1, &s2);
	displaySparseMatrix(*s3);
}