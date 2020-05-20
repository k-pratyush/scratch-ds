#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define I INT_MAX;

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

int main() {
    freopen("adj_matrix/test1.txt", "r", stdin);
    int r,c;
    cin >> r >> c;
    vector<vector<int> > A(r, vector<int> (c));
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin >> A[i][j];
            // if(!A[i][j])
            //     A[i][j] = I;
        }
    }
    dfs(A, 1, A.size());
}
