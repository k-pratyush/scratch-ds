#include<iostream>
#include<math.h>

using namespace std;

struct Term {
	int coef;
	int exp;
};

struct Poly {
	int n;
	struct Term* terms;
};

void createPolynomial(struct Poly* p) {
	cout << "Enter number of terms ";
	cin >> p->n;
	p->terms = new Term[p->n];
	cout << "Enter terms ";
	for(int i = 0; i < p->n; i++) {
		cin >> p->terms[i].coef >> p->terms[i].exp;
	}
}

void displayPolynomial(struct Poly p) {
	for(int i = 0; i < p.n; i++) {
		cout << p.terms[i].coef << " x^ " << p.terms[i].exp << endl;
	}
}

struct Poly* add(struct Poly *p1,  struct Poly *p2) {
	struct Poly* sum;
	sum = new Poly;
	sum->terms = new Term[p1->n + p2 -> n];
	int i,j,k;
	i=j=k=0;

	while(i < p1->n && j < p2 -> n) {
		if(p1->terms[i].exp > p2->terms[j].exp) {
			sum->terms[k++] = p1->terms[i++];
		} else if(p1->terms[i].exp < p2->terms[j].exp) {
			sum->terms[k++] = p2->terms[j++];
		} else {
			sum->terms[k].exp = p1->terms[i].exp;
			sum->terms[k++].coef = p1->terms[i++].coef + p2->terms[j++].coef;
		}
	}
	for(;i<p1->n;i++) {
		sum->terms[k++] = p1->terms[i];
	}
	for(;j<p2->n;j++) {
		sum->terms[k++] = p2->terms[j];
	}
	sum->n = k;
	return sum;
}

int main() {
	struct Poly p1, p2, *p3;
	createPolynomial(&p1);
	createPolynomial(&p2);
	p3 = add(&p1,&p2);
	displayPolynomial(*p3);

}