// this is cycle detection and printing the cycle
// using dfs

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

void dfs(
    int source, 
    vector<vector<int>> &adj, 
    vector<int> &visited, 
    vector<int> &parent, 
    vector<int> &entry,
    int &start, int &end) {

    visited[source] = 1;
    for(int adjNode: adj[source]) {
        if(visited[adjNode] == 0) {
            parent[adjNode] = source;
            entry[adjNode] = entry[source] + 1;
            dfs(adjNode, adj, visited, parent, entry, start, end);
            if(start != -1) {
                return;
            }
        } else if(visited[adjNode] == 1 && abs(entry[adjNode] - entry[source]) >= 2) {
            start = adjNode;
            end = source;
            return;
        }
    }
    visited[source] = 2;
}

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

    // visited 0 -> not visited
    // 1 -> entered but not exited
    // 2 -> exited
    vector<int> visited(V, 0), parent(V, -1), entry(V, 0);
    int start = -1, end = -1;
    for(int i=0;i<V;i++) {
        if(visited[i] == 0 && start == -1) {
            dfs(i, adj, visited, parent, entry, start, end);
        }
    }

    if(start == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> ans;
        ans.push_back(start + 1);
        int i = end;
        while(i != start) {
            ans.push_back(i + 1);
            i = parent[i];
        }
        ans.push_back(start + 1);
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for(auto p: ans) {
            cout << p << " ";
        }
        cout << endl;
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