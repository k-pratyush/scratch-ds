#include<iostream>
#include<vector>
#include<list>

using namespace std;

int hashFunc(int key) {
    return key % 10;
}

void Insert(vector<list<int> > &H, int key) {
    int index = hashFunc(key);
    H[index].push_back(key);
    H[index].sort();
}

bool Search(vector<list<int> > &H, int key) {
    int index = hashFunc(key);
    for(auto it: H[index])
        if(it == key)
            return true;
    return false;
}

int main() {
    vector<list<int> > hashTable(10);
    Insert(hashTable, 12);
    Insert(hashTable, 22);
    Insert(hashTable, 42);
    for(auto it: hashTable[2]) {
        cout << it << " ";
    }
    cout << Search(hashTable, 22) << endl;
    cout << Search(hashTable, 242) << endl;
    cout << Search(hashTable, 35) << endl;
}