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
    int source,
    vector<vector<int>> &graph,
    vector<int> &order,
    vector<bool> &visited
) {
    visited[source] = true;
    for(int adjNode: graph[source]) {
        if(!visited[adjNode]) {
            dfs(adjNode, graph, order, visited);
        }
    }
    order.push_back(source);
}

void dfs_scc(
    int source,
    vector<vector<int>> &reverseGraph,
    vector<int> &component,
    vector<bool> &visited
) {
    visited[source] = true;
    component.push_back(source);
    for(int adjNode: reverseGraph[source]) {
        if(!visited[adjNode]) {
            dfs_scc(adjNode, reverseGraph, component, visited);
        }
    }
}

void solve() {
    int V = 0, E = 0;
    cin >> V >> E;

    vector<vector<int>> graph(V, vector<int>());
    vector<vector<int>> reverseGraph(V, vector<int>());

    for(int i = 0; i < E; i++) {
        int from = 0, to = 0;
        cin >> from >> to;
        graph[from - 1].push_back(to - 1);
        reverseGraph[to - 1].push_back(from - 1);
    }
    // find a topological order of the graph
    vector<int> order;
    vector<bool> visited(V, false);

    for(int i = 0; i < V; i++) {
        if(!visited[i]) {
            dfs(i, graph, order, visited);
        }
    }

    reverse(order.begin(), order.end());


    vector<int> scc_root_nodes;
    visited.assign(V, false);
    vector<int> label(V, -1);
    int scc_count = 1;

    for(auto v: order) {
        if(!visited[v]) {
            vector<int> component;
            dfs_scc(v, reverseGraph, component, visited);
            for(int vertex: component) {
                label[vertex] = scc_count;
            }
            ++scc_count;
        }
    }

    cout << scc_count - 1 << endl;
    for(int l: label) {
        cout << l << " ";
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