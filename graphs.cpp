#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

#define I INT_MAX;

int Find(vector<int> &s, int u) {
    if(s[u] < 0) {
        return u;
    } else {
        return Find(s, s[u]);
    }
}

void Union(vector<int> &s, int u, int v) {
    u = Find(s, u);
    v = Find(s, v);
    if(s[u] < s[v]) {
        s[u] = s[u] + s[v];
        s[v] = u;
    } else {
        s[v] = s[u] + s[v];
        s[u] = v;
    }
}

vector<vector<int>> read_matrix(int r, int c) {
    vector<vector<int> > cost_A(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> cost_A[i][j];
            if(!cost_A[i][j])
                cost_A[i][j] = I;
        }
    }
    return cost_A;
}

void bfs(vector<vector<int>> A, int start, int n) {
    int i = start;
    queue<int> q;
    vector<int> visited(n,0);
    visited[i] = 1;
    q.push(i);
    cout << "visited " << i << endl;
    while(!q.empty()) {
        i = q.front();
        q.pop();
        for(int j = 1; j < n; j++) {
            if(A[i][j] && !visited[j]) {
                visited[j] = 1; 
                q.push(j);
                cout << "visited " << j << endl;
            }
        }
    }
}

void dfs(vector<vector<int>> A, int start, int n) {
    static vector<int> visited(n, 0);
    if(!visited[start]) {
        cout << "visited " << start << endl;
        visited[start] = 1;
        for(int j = 1; j < n; j++) {
            if(A[start][j] && !visited[j]) {
                dfs(A, j, n);
            }
        }
    }
}

void prims_MST(vector<vector <int> > &cost_A, int r, int c) {
    int k, u, v;
    int min = I;
    vector<int> near(r, INT_MAX);
    vector<pair<int, int>> treeEdges;

    for(int i = 1; i < r; i++) {
        for(int j = i; j < c; j++) {
            if(cost_A[i][j] < min) {
                min = cost_A[i][j];
                u = i;
                v = j;
            }
        }
    }
    treeEdges.push_back(make_pair(u,v));
    near[u] = near[v] = 0;
    for(int i = 1; i < r; i++) {
        if(near[i] != 0) {
            if(cost_A[i][u] < cost_A[i][v]) {
                near[i] = u;
            } else {
                near[i] = v;
            }
        }
    }
    for(int i = 1; i < r - 1; i++) {
        min = I;
        for(int j = 1; j < r; j++) {
            if(near[j] != 0 && cost_A[j][near[j]] < min) {
                k = j;
                min = cost_A[j][near[j]];
            }
        }
        treeEdges.push_back(make_pair(k, near[k]));
        near[k] = 0;
        for(int j = 1; j < r; j++) {
            if(near[j] != 0 && cost_A[j][k] < cost_A[j][near[j]]) {
                near[j] = k;
            }
        }
    }
    for(int i = 0; i < r - 1; i++) {
        cout << treeEdges[i].first << " " << treeEdges[i].second << endl;
    }
}

void kruskals_MST(vector<vector <int> > &edges, int n) {
    vector<int> s(n, -1);
    int num_edges = edges[0].size();
    vector<int> included(num_edges, 0);
    vector<pair<int, int> >treeEdges;
    int u, v, k;
    int i = 0;
    while(i < n - 1) {
        int min = I;
        for(int j = 0; j < num_edges; j++) {
            if(edges[2][j] < min && !included[j]) {
                min = edges[2][j];
                u = edges[0][j];
                v = edges[1][j];
                k = j;
            }
        }
        if(Find(s, u) != Find(s,v)) {
            treeEdges.push_back(make_pair(u, v));
            Union(s, u, v);
            i++;
        }
        included[k] = 1;
    }
    for(auto x: treeEdges) {
        cout << x.first << " " << x.second << endl;
    }
}

int main() {
    freopen("adj_matrix/test2.txt", "r", stdin);
    int r, c;
    cin >> r >> c;
    vector<vector<int> > cost_A = read_matrix(r, c);
    vector<vector<int> > edges = {
        {1,1,2,2,3,4,4,5,5},
        {2,6,3,7,4,5,7,6,7},
        {25,5,12,10,8,16,14,20,18}};
    // prims_MST(cost_A, r, c);
    kruskals_MST(edges, 7);
}
