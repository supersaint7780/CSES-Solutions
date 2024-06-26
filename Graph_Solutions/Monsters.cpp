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

void solve() {
    int rows = 0, cols = 0;
    cin >> rows >> cols;
    vector<string> graph(rows);
    for(int i=0;i<rows;i++) {
        cin >> graph[i];
    }
    vector<vector<char>> next(rows, vector<char>(cols, ' '));

    // first let the monsters move then you move
    // this way you would never collide with the monsters

    pair<int, int> human;
    queue<pii> q;
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            if(graph[i][j] == 'A') {
                human = pii(i, j);
            } else if(graph[i][j] == 'M') {
                q.push({i, j});
            }
        }
    }
    q.push(human);
    next[human.first][human.second] = 'X';

    vector<pii> directions {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if(graph[x][y] == 'A' && (x == 0 || y == 0 || x == rows - 1 || y == cols - 1)) {
            cout << "YES" << endl;
            pair<int, int> end {x, y};

            string path;
            while(true) {
                char par = next[end.first][end.second];
                if(par == 'X') {
                    break;
                }
                path.push_back(par);

                if(par == 'L') {
                    end.second += 1;
                } else if(par == 'R') {
                    end.second -= 1;
                } else if(par == 'D') {
                    end.first -= 1;
                } else if(par == 'U') {
                    end.first += 1;
                }
            }
            if(path.size() > 0) {
                cout << path.size() << endl;
                reverse(path.begin(), path.end());
                cout << path << endl;
            }
            return;
        }

        for(auto [dx, dy]: directions) {
            int nx = x + dx;
            int ny = y + dy;
            if(nx >= 0 && nx < rows && ny >= 0 && ny < cols && graph[nx][ny] == '.') {
                graph[nx][ny] = graph[x][y];
                if(graph[nx][ny] == 'A') {
                    if(dx == 1) {
                        next[nx][ny] = 'D';
                    } else if(dx == -1) {
                        next[nx][ny] = 'U';
                    } else if(dy == 1) {
                        next[nx][ny] = 'R';
                    } else if(dy == -1) {
                        next[nx][ny] = 'L';
                    }
                }
                q.push({nx, ny});
            }
        }
    }
    cout << "NO" << endl;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
     
    int testcases = 1;
    while(testcases--) {
        solve();
    }
    return 0;
}