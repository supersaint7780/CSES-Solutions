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
    int V = 0, E = 0, queries = 0;
    cin >> V >> E >> queries;
    vector<vector<ll>> graph(V, vector<ll>(V, 1e18));
    for(int i=0;i<E;i++) {
        ll u = 0, v = 0, d = 0;
        cin >> u >> v >> d;
        graph[u - 1][v - 1] = min(graph[u - 1][v - 1], d);
        graph[v - 1][u - 1] = min(graph[u - 1][v - 1], d);
    }

    vector<pair<int, int>> query;
    for(int i=0;i<queries;i++) {
        int u = 0, v = 0;
        cin >> u >> v;
        query.push_back({u - 1, v - 1});
    }

    vector<vector<ll>> distance = graph;
    for(int i=0;i<V;i++) {
        distance[i][i] = 0;
    }
    for(int k=0;k<V;k++) {
        for(int i=0;i<V;i++) {
            for(int j=0;j<V;j++) {
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }
    for(int i=0;i<queries;i++) {
        int u = query[i].first;
        int v = query[i].second;
        if(distance[u][v] == 1e18) {
            cout << -1 << endl;
        } else {
            cout << distance[u][v] << endl;
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