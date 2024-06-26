#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define endl '\n'
#define MOD 1000000007
#define all(x) begin(x), end(x)

void dfs(int i, int j, vector<vector<int>> &visited, vector<string> &mat) {
    if(visited[i][j] == 1 || mat[i][j] == '#') {
        return;
    }
    visited[i][j] = 1;
    int rows = visited.size();
    int cols = visited[0].size();
    
    vector<pair<int, int>> directions {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    for(auto [dx, dy]: directions) {
        int x = i + dx;
        int y = j + dy;
        if(x >= 0 && x < rows && y >= 0 && y < cols) {
            dfs(x, y, visited, mat);
        }
    }
}

void solve() {
    int rows = 0, cols = 0;
    cin >> rows >> cols;
    vector<string> mat(rows);
    for(int i=0;i<rows;i++) {
        cin >> mat[i];
    }
    vector<vector<int>> visited(rows, vector<int>(cols, 0));
    int rooms = 0;
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            if(mat[i][j] == '.' && visited[i][j] == 0) {
                ++rooms; 
                dfs(i, j, visited, mat);
            }
        }
    }
    cout << rooms << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
     
    int testcases = 1;
    // cin >> testcases;
    while(testcases--) {
        solve();
    }
    return 0;
}