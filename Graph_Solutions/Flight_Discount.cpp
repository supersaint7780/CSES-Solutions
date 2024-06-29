#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vll = vector<ll>;

#define endl '\n'
#define MOD 1000000007
#define all(x) begin(x), end(x)
#define LONG_INF (ll) 1e18
#define INF (int) 1e9

/* since we need to calculate the min cost with disount
* on a single flight in that path
* BRUTE FORCE : find all possible paths till the end using dfs
* for each path find cost of max flight, half it and sum all flight
* in that path to get its cost
* repeat it for all paths and and take the minimum value
* this methods will work but will take too much time
* since we are checking all paths
*
* OPTIMAL SOLUTION: 
* create two graphs one from the source 
* and a reverse graph from the end
* apply dijkstra on both graph 
* from start in first from end in second
* let us say we discount a flight from city a to b
* so our flight path would be somewhat like 1 -> a -> b -> n
* this a -> b is all possible edges
* since we already know the shorted distance from 1 to a and
* form end -> b(b -> end will be some)
* we can iterate all edges to check which gives the overall
* minimum cost
*/

vector<ll> dijkstra(int source, vector<vector<pll>> &adj) {
    int V = adj.size();

    vector<ll> distance(V, LONG_INF);
    distance[source] = 0;

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, source});

    while(!pq.empty()) {
        auto [dist_from, from] = pq.top();
        pq.pop();

        // indicates old node
        // we remove it since there is a new node
        // in pq with updated distance
        if(dist_from != distance[from]) {
            continue;
        }

        for(auto [to, cost]: adj[from]) {
            if(distance[to] > distance[from] + cost) {
                distance[to] = distance[from] + cost;
                pq.push({distance[to], to});
            }
        }
    }
    return distance;
}

void solve() {
    int V = 0, E = 0;
    cin >> V >> E;

    vector<vector<pll>> graph(V, vector<pll>());
    vector<vector<pll>> reverseGraph(V, vector<pll>());

    for(int i=0;i<E;i++) {
        ll u = 0, v = 0, cost = 0;
        cin >> u >> v >> cost;
        graph[u - 1].push_back({v - 1, cost});
        reverseGraph[v - 1].push_back({u - 1, cost});
    }

    int start = 0;
    int end = V - 1;
    vector<ll> dist_start = dijkstra(start, graph);
    vector<ll> dist_end = dijkstra(end, reverseGraph);

    // iterating over all edges applying the discount
    ll min_cost = LONG_INF;
    for(int i=0;i<V;i++) {
        ll from = i;
        for(auto [to, cost]: graph[from]) {
            min_cost = min(min_cost, dist_start[from] + cost/2 + dist_end[to]);
        }
    }
    cout << min_cost << endl;
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