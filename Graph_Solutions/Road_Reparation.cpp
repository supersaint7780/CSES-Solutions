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

class DisjointSet {
private:
    vector<int> parent, size;
public:
    DisjointSet(int _size): parent(_size), size(_size, 0) {
        iota(parent.begin(), parent.end(), 0);
    } 
    int findUParent(int u) {
        if(u == parent[u]) {
            return u;
        }
        return parent[u] = findUParent(parent[u]);
    }
    void unionBySize(int u, int v) {
        int pu = findUParent(u);
        int pv = findUParent(v);

        if(pu == pv) {
            return;
        }

        if(size[pu] < size[pv]) {
            parent[pu] = parent[pv];
            size[pv] += size[pu];
        } else {
            parent[pv] = parent[pu];
            size[pu] += size[pv];
        }
    }
};


void solve() {
    ll V = 0, E = 0;
    cin >> V >> E;
    vector<pair<ll, pll>> edges;
    for(int i=0;i<E;i++) {
        ll u = 0, v = 0, d = 0;
        cin >> u >> v >> d;
        edges.push_back({d, {u - 1, v - 1}});
    }
    sort(all(edges));

    int edgeCount = 0;

    DisjointSet ds(V);
    ll mst_weight = 0;
    for(auto edge: edges) {
        ll weight = edge.first;
        ll u = edge.second.first;
        ll v = edge.second.second;
        if(ds.findUParent(u) != ds.findUParent(v)) {
            mst_weight += weight;
            ++edgeCount;
            ds.unionBySize(u, v);
        }
    }

    if(edgeCount == V - 1) {
        cout << mst_weight << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
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