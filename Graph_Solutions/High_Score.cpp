// #include <bits/stdc++.h>

// using namespace std;
// typedef long long ll;
// const int maxN = 2501;
// const int maxM = 5001;
// const ll INF = 0x3f3f3f3f3f3f3f3f;

// struct Edge {
//     int a, b; ll c;
// } edges[maxM];

// int N, M;
// ll dp[maxN];
// bool vis[maxN], visR[maxN];
// vector<int> G[maxN], GR[maxN];

// void dfs(int u){
//     vis[u] = true;
//     for(int v : G[u])
//         if(!vis[v])
//             dfs(v);
// }

// void dfsR(int u){
//     visR[u] = true;
//     for(int v : GR[u])
//         if(!visR[v])
//             dfsR(v);
// }

// int main(){
//     scanf("%d %d", &N, &M);
//     for(int i = 0, a, b; i < M; i++){
//         ll c;
//         scanf("%d %d %lld", &a, &b, &c);
//         edges[i] = {a, b, -c};
//         G[a].push_back(b);
//         GR[b].push_back(a);
//     }
//     dfs(1); dfsR(N);

//     fill(dp+2, dp+N+1, INF);
//     bool improvement = true;
//     for(int iter = 0; iter < N && improvement; iter++){
//         improvement = false;
//         for(int i = 0; i < M; i++){
//             int u = edges[i].a;
//             int v = edges[i].b;
//             ll w = edges[i].c;

//             if(dp[v] > dp[u]+w){
//                 dp[v] = dp[u]+w;
//                 improvement = true;

//                 if(iter == N-1 && vis[v] && visR[v]){
//                     printf("-1\n");
//                     return 0;
//                 }
//             }
//         }
//     }

//     printf("%lld\n", -dp[N]);
// }

#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define int ll
#define endl '\n'
 
const ll mod = 1000000007;
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>());
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }
    vector<int> dist(n + 1, -1e10);
    dist[1] = 0;
    for (int i = 0; i < n - 1; i++){
        for (int j = 1; j < n + 1; j++){
            if (dist[j] != -1e10){
                for (pair<int, int> x : graph[j]){
                    int v = x.first;
                    int w = x.second;
                    if (dist[j] + w > dist[v])
                        dist[v] = dist[j] + w;
                }
            }
        }
    }
    for (int u = 1; u < n + 1; u++){
        if (dist[u] != -1e10){
            for (pair<int, int> x : graph[u]){
                int v = x.first;
                int w = x.second;
                if (dist[u] + w > dist[v]){
                    queue<int> q;
                    q.push(u);
                    vector<bool> visited(n + 1, false);
                    while (!q.empty()){
                        int node = q.front();
                        q.pop();
                        if (node == n){
                            cout << -1;
                            exit(0);
                        }
                        visited[node] = true;
                        for (pair<int, int> x : graph[node]){
                            if (!visited[x.first]){
                                q.push(x.first);
                            }
                        }
                    }
                }
            }
        }
    }
 
    cout << dist[n];
 
    return 0;
}
