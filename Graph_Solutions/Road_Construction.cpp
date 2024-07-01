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
    DisjointSet(int _size): parent(_size), size(_size, 1) {
        iota(parent.begin(), parent.end(), 0);
    } 
    int findUParent(int u) {
        if(u == parent[u]) {
            return u;
        }
        return parent[u] = findUParent(parent[u]);
    }
    int unionBySize(int u, int v) {
        int pu = findUParent(u);
        int pv = findUParent(v);

        if(pu == pv) {
            return size[pu];
        }

        if(size[pu] < size[pv]) {
            parent[pu] = parent[pv];
            size[pv] += size[pu];
            return size[pv];
        } else {
            parent[pv] = parent[pu];
            size[pu] += size[pv];
            return size[pu];
        }
    }
};


void solve() {
    int V = 0, E = 0;
    cin >> V >> E;
    vector<pii> edges;
    for(int i=0;i<E;i++) {
        int u = 0, v = 0;
        cin >> u >> v;
        edges.push_back({u - 1, v - 1});
    }

    int max_size = 1;
    int components = V;



    DisjointSet ds(V);
    for(auto edge: edges) {
        int u = edge.first;
        int v = edge.second;
        if(ds.findUParent(u) != ds.findUParent(v)) {
            components--;
            max_size = max(max_size, ds.unionBySize(u, v));
            cout << components << " " << max_size << endl;
        } else {
            cout << components << " " << max_size << endl;
        }
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