#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vs = vector<string>;

#define endl '\n'
#define MOD 1000000007
#define all(x) begin(x), end(x)
#define LONG_INF (ll) 1e18
#define INF (ll) 1e9 
#define rall(x) rbegin(x), rend(x)

void solve() {
    ll size = 0, queries = 0;
    cin >> size >> queries;

    vll arr(size);
    for(auto &it: arr) {
        cin >> it;
    }

    vll prefix = arr;
    for(int i=1;i<size;i++) {
        prefix[i] += prefix[i-1];
    }

    while(queries--) {
        int l = 0, r = 0;
        cin >> l >> r;
        --l;
        --r;
        cout << prefix[r] - (l - 1 >= 0 ? prefix[l-1] : 0) << endl;
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