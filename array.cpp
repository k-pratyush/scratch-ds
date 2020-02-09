#include<iostream>

using namespace std;

class Array {
public:
    int A[20];
    int size;
    int length;
};

void displayArray(Array arr) {
    cout << "elements are: ";
    for(int i = 0; i < arr.length; i++) {
        cout << arr.A[i] << " ";
    }
}

void insertElement(Array &arr, int pos, int val) {
    if(arr.length < arr.size) {
        int i = arr.length;
        while(i > pos) {
            arr.A[i] = arr.A[i-1];
            i--;
        }
        arr.length++;
        arr.A[pos] = val;
    }
}

void deleteElement(Array &arr, int pos) {
    if(pos >= 0 && pos < arr.length) {
        int i = pos;
        while(i < arr.length) {
            arr.A[i] = arr.A[i+1];
            i++;
        }
        arr.length--;
    }
}

void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int linearSearch(Array arr, int key) {
    for(int i = 0; i < arr.length; i++) {
        if (key == arr.A[i])
            return i;
    }
    return -1;
}

int linearSearchTransposition(Array &arr, int key) {
    for(int i = 0; i < arr.length; i++) {
        if(key == arr.A[i]) {
            swap(arr.A[i-1], arr.A[i]);
            return i;
        }
    }
    return -1;
}

int linearSearchMoveToHead(Array &arr, int key) {
    for(int i = 0; i < arr.length; i++) {
        if(key == arr.A[i]) {
            swap(arr.A[0], arr.A[i]);
            return i;
        }
    }
    return -1;
}

int binarySearch(Array arr, int key) {
    int low = 0;
    int high = arr.length - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr.A[mid] == key) {
            return mid;
        }
        else if(arr.A[mid] > key) {
            high = mid -1;
        }
        else if(arr.A[mid] < key) {
            low = mid + 1;
        }
    }
    return -1;
}

int binarySearchRecursive(Array arr, int key, int low, int high) {
    if(low <= high) {
        int mid = (low + high) / 2;
        if (arr.A[mid] == key) {
            return mid;
        }
        else if(arr.A[mid] < key) {
            binarySearchRecursive(arr, key, mid+1, high);
        }
        else {
            binarySearchRecursive(arr, key, low, mid-1);
        }
    }
    return -1;
}

void reverseArray(Array &arr) {
    for(int i = 0, j = arr.length -1; i < j; i++, j--) {
        swap(arr.A[i], arr.A[j]);
    }
}

void negativePositiveSort(Array &arr) {
    int i = 0;
    int j = arr.length -1;
    while(i < j) {
        while(arr.A[i] < 0)
            i++;
        while(arr.A[j] >= 0)
            j--;
        if(i < j)
            swap(arr.A[i], arr.A[j]);
    }
}

Array* mergeSortedArrays(Array arr1, Array arr2) {
    int i = 0, j = 0, k = 0;
    Array* narray = new Array;

    while(i < arr1.length && j < arr2.length) {
        if(arr1.A[i] < arr2.A[j])
            narray->A[k++] = arr1.A[i++];
        else
            narray->A[k++] = arr2.A[j++];
    }
    for(;i< arr1.length; i++)
        narray->A[k++] = arr1.A[i];
    for(;j< arr2.length; j++)
        narray->A[k++] = arr2.A[j];
    narray->length = arr1.length + arr2.length;
    narray->size = 10;
    return narray;
}

Array* setUnion(Array arr1, Array arr2) {
    int i = 0, j = 0, k = 0;
    Array* narray = new Array;

    while(i < arr1.length && j < arr2.length) {
        if(arr1.A[i] < arr2.A[j])
            narray->A[k++] = arr1.A[i++];
        else if(arr1.A[i] > arr2.A[j])
            narray->A[k++] = arr2.A[j++];
        else {
            narray->A[k++] = arr1.A[i++];
            j++;
        }
    }
    for(;i< arr1.length; i++)
        narray->A[k++] = arr1.A[i];
    for(;j< arr2.length; j++)
        narray->A[k++] = arr2.A[j];
    narray->length = k;
    narray->size = 10;
    return narray;
}

Array* setIntersection(Array arr1, Array arr2) {
    int i = 0, j = 0, k = 0;
    Array* narray = new Array;

    while(i < arr1.length && j < arr2.length) {
        if(arr1.A[i] < arr2.A[j])
            i++;
        else if(arr1.A[i] > arr2.A[j])
            j++;
        else {
            narray->A[k++] = arr1.A[i++];
            j++;
        }
    }
    narray->length = k;
    narray->size = 10;
    return narray;
}

Array* setSubtraction(Array arr1, Array arr2) {
    int i = 0, j = 0, k = 0;
    Array* narray = new Array;

    while(i < arr1.length && j < arr2.length) {
        if(arr1.A[i] < arr2.A[j])
            narray->A[k++] = arr1.A[i++];
        else if(arr1.A[i] > arr2.A[j])
            j++;
        else {
            i++;
            j++;
        }
    }
    for(;i< arr1.length; i++)
        narray->A[k++] = arr1.A[i];

    narray->length = k;
    narray->size = 10;
    return narray;
}

void missingElements(Array arr) {
    int diff = arr.A[0];
    int n = arr.length;
    for(int i = 0; i < n; i++) {
        if(arr.A[i] - i != diff) {
            while(diff < arr.A[i] - i) {
                cout << diff + i << " ";
                diff++;
            }
        }
    }
}

void missingElementsUnsorted(Array arr, int l, int h) {
    Array* a = new Array;
    a->length = h;
    for(int i = 0; i < h; i++)
        a->A[i] = 0;
    for(int i = 0; i < arr.length; i++)
        a->A[arr.A[i]]++;
    for(int i = l; i < h; i++)
        if(a->A[i] == 0)
            cout << i << " ";
}

void commonElementsSorted(Array arr) {
    int lastDuplicate = 0;
    int n = arr.length;
    for(int i = 0; i < n-1; i++) {
        if(arr.A[i] == arr.A[i+1]) {
            if(lastDuplicate != arr.A[i]) {
                cout << arr.A[i] << " ";
                lastDuplicate = arr.A[i];
            }
        }
    }
}

void commonElementsUnsorted(Array arr) {
    
}

int main() {
    Array arr = {{1,2,3,3,4,4,4,5,7,10}, 20, 10};
    //Array arr1 = {{1,3,5,7,9}, 20, 5};
    //Array arr2 = {{2,4,6,8,10}, 20, 5};
    //Array *arr3 = setSubtraction(arr, arr1);
    commonElementsSorted(arr);
}
