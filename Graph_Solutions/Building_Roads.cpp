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

void bfs(int source, vector<int> &visited, vector<vector<int>> &adj) {
    queue<int> q;
    q.push(source);
    visited[source] = 1;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(int adjnode: adj[node]) {
            if(visited[adjnode] == 0) {
                q.push(adjnode);
                visited[adjnode] = 1;
            }
        }
    }
}

void solve() {
    int V = 0, E = 0;
    cin >> V >> E;
    vector<vector<int>> adj(V, vector<int>(0));
    for(int i=0;i<E;i++) {
        int v = 0, u = 0;
        cin >> v >> u;
        adj[v - 1].push_back(u - 1);
        adj[u - 1].push_back(v - 1);
    }

    vector<int> visited(V, 0);
    vector<int> super_nodes;
    for(int i=0;i<V;i++) {
        if(visited[i] == 0) {
            super_nodes.push_back(i);
            bfs(i, visited, adj);
        }
    }

    cout << super_nodes.size() - 1 << endl;
    for(int i=0;i<super_nodes.size() - 1;i++) {
        cout << super_nodes[i] + 1 << " " << super_nodes[i+1] + 1 << endl;
    }
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