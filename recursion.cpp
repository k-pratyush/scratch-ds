#include<iostream>
#include<vector>

using namespace std;

void funB(int);

//Head recursion
void funcHead(int n) {
    if(n > 0) {
        funcHead(n-1);
        cout << n << " ";
    }
}

//Tail recursion
void funcTail(int n) {
    if(n > 0) {
        cout << n << " ";
        funcTail(n-1);
    }
}

//Tree recursion
void fun(int n) {
    if(n > 0) {
        cout << n << " ";
        fun(n-1);
        fun(n-1);
    }
}

//Indirect recursion
void funA(int n) {
    if(n > 0) {
        cout << n << " ";
        funB(n-1);
    }
}
void funB(int n) {
    if(n > 1) {
        cout << n << " ";
        funA(n/2);
    }
}

//Nested recursion
int nestedFun(int n) {
    if(n > 100) {
        return n-10;
    } else {
        return nestedFun(nestedFun(n+11));
    }
}

//Sum of n numbers
int sumOfNumbers(int n) {
    if(n == 0) {
        return 0;
    } else {
        return sumOfNumbers(n-1) + n;
    }
}

//Factorial of n numbers
int factorial(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return factorial(n-1) * n;
    }
}

//Power
int powerMN(int m, int n) {
    if(n == 0) {
        return 1;
    } else {
        return powerMN(m, n-1) * m;
    }
}
int powerFast(int m, int n) {
    if(n == 0)
        return 1;
    if(n % 2 == 0)
        return powerFast(m * m,  n/2);
    else
        return m * powerFast(m* m, (n-1)/2);
    
}

//Taylor series - e^x for n terms
double e(int x, int n) {
    static double p = 1, f = 1;
    double r;
    if(n == 0)
        return 1;
    else {
        r = e(x, n-1);
        p = p * x;
        f = f * n;
        return r + p/f;
    }
}

//Taylor series - Horner's rule
double eHorner(int x, int n) {
    static float s = 1;
    if(n == 0) {
        return s;
    } else {
        s = 1 + (x*s/n);
        return eHorner(x, n-1);
    }
}

//Fibonacci memoization top down approach
vector<int> DP(100, 0);
int fibDP(int n) {
    if(DP[n] == 0) {
        if(n <= 1)
            DP[n] = n;
        else
            DP[n] = fibDP(n-1) + fibDP(n-2);
    }
    return DP[n];
}

//nCr
int nCr(int n, int r) {
    if(r == 0 || n == r) {
        return 1;
    }
    return nCr(n-1, r-1) + nCr(n-1, r);
}

//Tower of Hanoi (A to C using B) -> A B C
void TOH(int n, int A, int B, int C) {
    if(n > 0) {
        TOH(n-1, A, C, B);
        cout << "move " << A << " to " << C << endl;
        TOH(n-1, B, A, C);
    }
}

int main() {
    TOH(3, 1, 2, 3);
}
