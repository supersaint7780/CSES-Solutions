#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define endl '\n'
#define MOD 1000000007
#define all(x) begin(x), end(x)
#define LONG_INF (ll) 1e18
#define INF (ll) 1e9 

void dfs(
    ll source, 
    vector<vector<ll>> &adj, 
    vector<bool> &visited, 
    vector<ll> &order) {

    visited[source] = true;
    for(ll adjNode: adj[source]) {
        if(!visited[adjNode]) {
            dfs(adjNode, adj, visited, order);
        }
    }
    order.push_back(source);
}

void dfs_scc(
    ll source, 
    vector<vector<ll>> &reverseAdj, 
    vector<bool> &visited, 
    vector<ll> &component_nodes) {
    
    visited[source] = true;
    component_nodes.push_back(source);
    for(ll adjNode: reverseAdj[source]) {
        if(!visited[adjNode]) {
            dfs_scc(adjNode, reverseAdj, visited, component_nodes);
        }
    }
}

void solve() {
    ll V = 0, E = 0;
    cin >> V >> E;
    vector<vector<ll>> adj(V, vector<ll>());
    vector<vector<ll>> reverseAdj(V, vector<ll>());

    for(int i=0;i<E;i++) {
        ll u = 0, v = 0;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        reverseAdj[v - 1].push_back(u - 1);
    }

    vector<bool> visited(V, false);

    // stores all the nodes in the topological order
    // i.e in the descending order of their exit time
    vector<ll> order;
    for(ll i=0;i<V;i++) {
        if(!visited[i]) {
            dfs(i, adj, visited, order);
        }
    }
    reverse(order.begin(), order.end());

    visited.assign(V, false);

    vector<ll> scc_root_nodes;
    for(ll v: order) {
        if(!visited[v]) {
            vector<ll> component_nodes;
            dfs_scc(v, reverseAdj, visited, component_nodes);

            scc_root_nodes.push_back(component_nodes.front());
            component_nodes.clear();
        }
    }

    if(scc_root_nodes.size() == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
        cout << scc_root_nodes[1] + 1 << " " << scc_root_nodes[0] + 1<< endl;
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