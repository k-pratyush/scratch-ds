#include<iostream>
#include<vector>

using namespace std;

vector<int> s = {0, -2, 1, 4, -2};

int Find(int u) {
    if(s[u] < 0) {
        return u;
    } else {
        return Find(s[u]);
    }
}

void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if(s[u] < s[v]) {
        s[u] = s[u] + s[v];
        s[v] = u;
    } else {
        s[v] = s[u] + s[v];
        s[u] = v;
    }
}

int main() {
    cout << Find(2) << endl;
    Union(2, 4);
    cout << Find(2) << endl;
    for (auto i: s) {
        cout << i << " ";
    }
}