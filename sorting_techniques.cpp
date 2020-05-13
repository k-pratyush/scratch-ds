#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void bubble_sort(vector<int> &a) {
    int n = a.size();
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(a[j+1] < a[j]) {
                swap(a[j+1], a[j]);
            }
        }
    }
}

void insertion_sort(vector<int> &a) {
    int n = a.size();
    for(int i = 1; i < n; i++) {
        int j = i -1;
        int x = a[i];
        while(j > -1 && a[j] > x) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = x;
    }
}

void selection_sort(vector<int> &a) {
    int n = a.size();
    for(int i = 0; i < n; i++) {
        int j = i, k = i;
        while(j < n) {
            if(a[j] < a[k])
                k = j;
            j++;
        }
        swap(a[i], a[k]);
    }
}

int partition(vector<int> &a, int l, int r) {
    int pivot = a[l];
    int i = l, j = r;
    do {
        do {
            i++;
        } while(a[i] <= pivot);
        do {
            j--;
        } while(a[j] > pivot);
        if(i < j)
            swap(a[i], a[j]);
    } while(i < j);
    swap(a[l], a[j]);
    return j;
}

void quick_sort(vector<int> &a, int l, int h) {
    int j;
    if (l < h) {
        j = partition(a, l, h);
        quick_sort(a, l, j);
        quick_sort(a, j + 1 , h);
    }
}

void merge(vector<int> &a, int l, int mid, int h) {
    int i = l;
    int j = mid + 1;
    int k = l;
    int b[h+1];
    while(i <= mid && j <= h) {
        if(a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    for(;i<=mid;i++)
        b[k++] = a[i];
    for(;j<=h;j++)
        b[k++] = a[j];
    for(i = l; i <= h; i++)
        a[i] = b[i];
}

void merge_sort(vector<int> &a) {
    int n = a.size();
    int p;
    for(p = 2; p <= n; p *= 2) {
        for(int i = 0; i + p - 1 < n; i += p) {
            int l = i;
            int h = i + p - 1;
            int m = (l + h) / 2;
            merge(a, l, m, h);
        }
    }
    if(p/2 < n) {
        merge(a, 0, p/2 - 1, n-1);
    }
}

void merge_sort_recursive(vector<int> &a, int l, int h) {
    int mid;
    if (l < h) {
        mid = (l + h) / 2;
        merge_sort_recursive(a, l, mid);
        merge_sort_recursive(a, mid+1, h);
        merge(a, l, mid, h);
    }
}

void count_sort(vector<int> &a) {
    vector<int> count(*max_element(a.begin(), a.end()) + 1, 0);
    for(auto i: a) {
        count[i]++;
    }
    int j = 0;
    for(int i = 0; i < count.size(); i++) {
        if(count[i] > 0) {
            while(count[i] != 0) {
                a[j++] = i;
                count[i]--;
            }
        }
    }
}

int main() {
    vector<int> a = {8, 5, 7, 3, 2, 1};
    count_sort(a);

    for(auto i: a) {
        cout << i << " ";
    }
}
