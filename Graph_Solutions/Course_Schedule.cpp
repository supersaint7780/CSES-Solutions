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

void dfs(int source, vector<int> &visited, vector<int> &ans, vector<vector<int>> &adj, bool &impossible) {
    visited[source] = 1;
    for(int adjNode: adj[source]) {
        if(visited[adjNode] == 0) {
            visited[adjNode] = 1;
            dfs(adjNode, visited, ans, adj, impossible);
        } else if(visited[adjNode] == 1) {
            impossible = true;
            return;
        }
    }
    ans.push_back(source);
    visited[source] = 2;
}

void solve() {
    int V = 0, E = 0;
    cin >> V >> E;
    vector<vector<int>> adj(V, vector<int>());
    for(int i=0;i<E;i++) {
        int u = 0, v = 0;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
    }

    vector<int> visited(V, 0);
    vector<int> ans;
    bool impossible = false;
    for(int i=0;i<V;i++) {
        if(visited[i] == 0) {
            dfs(i, visited, ans, adj, impossible);
        }
    }

    if(impossible) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    for(int i=V-1;i>=0;i--) {
        cout << ans[i] + 1 << " ";
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