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

string bfs(int i, int j, vector<string> &mat) {
    int rows = mat.size();
    int cols = mat[0].size();

    vector<vector<int>> visited(rows, vector<int>(cols, 0));
    vector<vector<pair<int, int>>> parent(rows, vector<pair<int, int>>(cols));
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = 1;
    parent[i][j] = {-1, -1};
    vector<pair<int, int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int end_x = -1, end_y = -1;
    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        if(mat[x][y] == 'B') {
            end_x = x;
            end_y = y;
            break;
        }
        for(auto [dx, dy]: directions) {
            int nx = x + dx;
            int ny = y + dy;
            if(nx >= 0 && nx < rows && ny >= 0 && ny < cols 
                && mat[nx][ny] != '#' 
                && visited[nx][ny] == 0) {

                q.push({nx, ny});
                visited[nx][ny] = 1;
                parent[nx][ny] = {x, y};
            }
        }
        
    }

    string path;
    for(pair<int, int> i = {end_x, end_y}; i.first != -1 && i.second != -1; i = parent[i.first][i.second]) {
        auto par = parent[i.first][i.second];
        if(i.first - par.first == 1 && i.second - par.second == 0) {
            path.push_back('D');
        } else if(i.first - par.first == -1 && i.second - par.second == 0) {
            path.push_back('U');
        } else if(i.first - par.first == 0 && i.second - par.second == 1) {
            path.push_back('R');
        } else {
            path.push_back('L');
        }
    }
    if(path.size() > 0) {
        path.pop_back();
        reverse(all(path));
    }
    

    return path;
}
void solve() {
    int rows = 0, cols = 0;
    cin >> rows >> cols;
    vector<string> mat(rows);
    for(int i=0;i<rows;i++) {
        cin >> mat[i];
    }

    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            if(mat[i][j] == 'A') {
                string path = bfs(i, j, mat);
                if(path.size() > 0) {
                    cout << "YES" << endl;
                    cout << path.size() << endl;
                    cout << path << endl;
                    return;
                }
            }
        }
    }
    cout << "NO" << endl;
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