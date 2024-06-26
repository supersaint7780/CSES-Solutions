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
    int V = 0, E = 0;
    cin >> V >> E;
    vector<vector<int>> adj(V, vector<int>(0));
    for(int i=0;i<E;i++) {
        int u = 0, v = 0;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    vector<int> visited(V, 0);
    vector<int> color(V, 0);
    
    bool isImpossible = false;

    for(int i=0;i<V;i++) {
        if(visited[i] == 0) {
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            color[i] = 1;
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                for(int adjNode: adj[node]) {
                    if(visited[adjNode] == 0) {
                        visited[adjNode] = 1;
                        color[adjNode] = (color[node] == 2) ? 1 : 2;
                        q.push(adjNode);
                    } else if(color[node] == color[adjNode]) {
                        isImpossible = true;
                        break;
                    }
                }
            }
            if(isImpossible) {
                break;
            }
        }
    }

    if(isImpossible) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    for(int i=0;i<V;i++) {
        cout << color[i] << " ";
    }
    cout << endl;

    
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