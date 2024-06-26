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
    vector<vector<pair<int, int>>> adj(V, vector<pair<int, int>>(0));
    for(int i=0;i<E;i++) {
        int u = 0, v = 0, d = 0;
        cin >> u >> v >> d;
        adj[u - 1].push_back({v - 1, d});
    }

    vector<ll> distance(V, 1e18);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    distance[0] = 0;
    pq.push({0, 0});
    while(!pq.empty()) {
        auto [small_distance, small] = pq.top();
        pq.pop();

        // checking if the node has been marked
        // i.e its adjacet edges have been relaxed
        if(small_distance != distance[small]) {
            continue;
        }

        // now relax all edges from the node with smallest distance
        for(pair<int, int> adjNode: adj[small]) {
            int to = adjNode.first;
            int length = adjNode.second;

            if(distance[small] + length < distance[to]) {
                distance[to] = distance[small] + length;
                pq.push({distance[to], to});
            }
        }
    }
    
    // print the shorted distance to all nodes from source
    for(int i=0;i<V;i++) {
        cout << distance[i] << " ";
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