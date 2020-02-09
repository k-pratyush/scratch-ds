#include<iostream>

using namespace std;

class Diagonal {
    private:
    int n;
    int *A;
    public:
    Diagonal(int n) {
        this->n = n;
        A = new int[n];
    }

    void Set(int i, int j, int x) {
        if(i == j)
            A[i-1] = x;
    }

    int Get(int i, int j) {
        if (i == j)
            return A[i-1];
        return 0;
    }

    void Display() {
        int i, j;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j)
                    cout << A[i] << " ";
                else
                    cout << 0 << " ";
            }
            cout << "\n";
        }
    }
};

class LowerTri
{
private:
    int n;
    int *A;

public:
    LowerTri(int n)
    {
        this->n = n;
        A = new int[n*(n+1)/2];
    }

    void Set(int i, int j, int x)
    {
        if (i >= j)
            A[i*(i - 1)/2 + j-1] = x;
    }

    int Get(int i, int j)
    {
        if (i >= j)
            return A[i*(i - 1)/2 + j-1];
        return 0;
    }

    void Display()
    {
        int i, j;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i >= j)
                    cout << A[i*(i-1)/2 + j-1] << " ";
                else
                    cout << 0 << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    LowerTri lt(4);
}
