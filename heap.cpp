#include<iostream>
#include<vector>

using namespace std;

void insert(vector<int> &a, int n) {
    int temp = a[n];
    int i = n;
    while(i > 1 && temp > a[i/2]) {
        a[i] = a[i/2];
        i = i/2;
    }
    a[i] = temp;
}

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void Delete(vector<int> &a, int n) {
    swap(a[1],a[n]);
    int i = 1;
    int j = 2*i;
    while(j < n - 1) {
        if(a[j+1] > a[j])
            j += 1;
        if(a[i] < a[j]) {
            swap(&a[i], &a[j]);
            i = j;
            j *= 2;
        } else {
            break;
        }
    }
}

void heap_sort(vector<int> &a, int n) {
    for(int i = n; i > 1; i--) {
        Delete(a, i);
    }
}

void createHeap(vector<int> &a, int n) {
    for(int i = 2; i < n; i++) {
        insert(a, i);
    }
}

int main() {
    vector<int> a = {-1, 1, 4, 12, 5, 6};
    int n = 6;
    createHeap(a, n);
    // Delete(a, 5);
    heap_sort(a, 5);
    for(int i = 1; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
